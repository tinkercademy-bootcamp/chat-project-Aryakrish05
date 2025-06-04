#include <string>
#include <set>
#include <map>
#include <iostream>
#include <unistd.h>
#include "Server_channel.hpp"
#include "Server_client.hpp"
#include "Database.hpp"

Client::Client(int socket):user_name("Default_name"),connected_socket(socket){
        std::cout<<"Client Construction in progress..."<<user_name<<"\n";
}
Client::~Client(){
        std::cout<<"Client Destruction in progress..."<<user_name<<"\n";
        close(connected_socket);
        for(auto member_channel:channel_list){
                member_channel->remove_client(this);
        }
        socket_client.erase(connected_socket);
        user_name_client_ptr.erase(user_name);
}
void Client::join_channel(Channel* channel_ptr){
        channel_ptr->add_client(this);
        channel_list.insert(channel_ptr);
}
void Client::exit_channel(Channel* channel_ptr){
        channel_list.erase(channel_ptr);
        channel_ptr->remove_client(this);
}
bool Client::check_channel(Channel* channel_ptr){
        return (channel_list.count(channel_ptr));
}
void Client::send_data(const std::string& data){
        if(send(connected_socket,data.c_str(),data.size(),MSG_NOSIGNAL)<0){
                delete this;
        }
}
std::string Client::get_user_name(){
        return user_name;
}
void Client::set_user_name(std::string new_user_name){
        user_name=new_user_name;
        std::cout<<"UserName is set to "<<user_name<<"\n";
}