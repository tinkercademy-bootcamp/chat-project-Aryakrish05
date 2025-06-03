#include <string>
#include <map>
#include <sys/socket.h>
#include "Server_channel.hpp"
#include "Server_client.hpp"
#include "Database.hpp"
#include "Server.hpp"

std::map<int,Client*> socket_client;

std::map<std::string,Client*> user_name_client_ptr;

std::map<std::string,Channel*> channel_name_channel_ptr;

int main(){
        server_run();
}