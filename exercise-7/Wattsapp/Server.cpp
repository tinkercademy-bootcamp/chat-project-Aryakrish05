#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sys/socket.h>
#include <unistd.h>
#include "utils.hpp"

class Channel;

class Client;

std::map<int,Client*> socket_client;

std::map<std::string,Client*> user_name_client_ptr;

std::map<std::string,Channel*> channel_name_channel_ptr;

class Client{
private:
        std::string user_name;
        int connected_socket;
        std::set<Channel*>channel_list;
public:
        Client(std::string& name,int socket):user_name(name),connected_socket(socket){}
        ~Client(){
                close(connected_socket);
                for(auto member_channel:channel_list){
                        member_channel->remove_client(this);
                }
                //also have to remove occurrences of client from map
        }
        void join_channel(Channel* channel_ptr){
                channel_ptr->add_client(this);
                channel_list.insert(channel_ptr);
        }
        void exit_channel(Channel* channel_ptr){
                channel_list.erase(channel_ptr);
        }
        bool check_channel(Channel* channel_ptr){
                return (channel_list->count(channel_ptr));
        }
        void send_data(std::string& data){
                if(send(connected_socket,data.c_str(),data.size(),MSG_NOSIGNAL)<0){
                        //means that the client has closed the connection
                        //need to delete this class
                }
        }
        std::string get_user_name(){
                return user_name;
        }
};

class Channel{
private:
        std::string channel_name;
        std::set<Client*>client_list;
public:
        Channel(std::string name,Client* client_member):channel_name(name){
                client_list.insert(client);
        }
        //channel must have at least one person, else destructor shall be called
        void broadcast_data(std::string data){
                for(auto client_member:client_list){
                        client_member->send_data(data);
                }
        }
        void remove_client(Client* client_member){
                client_list.erase(client_member);
                if(client_list.empty()){
                        //need to permanently delete the channel
                }
        }
        void add_client(Client* client_member){
                client_list.add_client(client_member);
        }
        void check_client(Client* client_member){
                return client_list.count(client_member);
        }
        std::string get_channel_name(){
                return channel_name;
        }
};

