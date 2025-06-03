#include <string>
#include <set>
#include <map>
#include <unistd.h>
#include "Server_channel.hpp"
#include "Server_client.hpp"
#include "Database.hpp"

Client::Client(std::string& name,int socket):user_name(name),connected_socket(socket){}
Client::~Client(){
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