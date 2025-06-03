#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sys/socket.h>
#include <unistd.h>
#include "utils.hpp"
class Channel;
class Client{
private:
        std::string user_name;
        int connected_socket;
        std::set<Channel*>channel_list;
public:
        Client(std::string name,int socket):user_name(name),connected_socket(socket){}
        ~Client();
        void join_channel(Channel* channel_ptr);
        void exit_channel(Channel* channel_ptr);
        bool check_channel(Channel* channel_ptr);
        //if he is not part of channel then he should not be able to send message across the channel 
        void send_data(std::string data);//includes messages and invites
        std::string get_user_name();
};
class Channel{
private:
        std::string channel_name;
        std::set<Client*>client_list;
public:
        Channel(std::string name,Client* client);
        //channel must have at least one person, else destructor shall be called
        void broadcast_data(std::string data);
        void remove_client(Client*);
        //if after this the class is empty, delete this will be called
        void add_client(Client*);
        void check_client(Client*);
        std::string get_channel_name();
};