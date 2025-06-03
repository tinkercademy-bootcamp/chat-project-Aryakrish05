#include <string>
#include <set>
#include <map>
#include "Server_channel.hpp"
#include "Server_client.hpp"
#include "Database.hpp"

Channel::Channel(std::string name,Client* client_member):channel_name(name){
        client_list.insert(client_member);
}
Channel::~Channel(){
        //called only when no members are there
        channel_name_channel_ptr.erase(channel_name);
}
void Channel::broadcast_data(std::string data){
        for(auto client_member:client_list){
                client_member->send_data(data);
        }
}
void Channel::remove_client(Client* client_member){
        client_list.erase(client_member);
        if(client_list.empty()){
                delete this;
        }
}
void Channel::add_client(Client* client_member){
        client_list.insert(client_member);
}
bool Channel::check_client(Client* client_member){
        return client_list.count(client_member);
}
std::string Channel::get_channel_name(){
        return channel_name;
}