#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sys/socket.h>
#include <unistd.h>
#include "utils.hpp"
class Client{
private:
        std::string user_name;
        int connected_socket;
        std::set<std::string>channels;
public:
        Client(std::string name,int socket):user_name(name),connected_socket(socket){}
        ~Client();
        void join_channel(std::string channel_name);
        void exit_channel(std::string channel_name);
        void send_data(std::string message);//includes messages and invites
};