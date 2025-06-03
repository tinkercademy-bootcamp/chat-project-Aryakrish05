#include <string>
#include <map>
#include <sys/socket.h>
#include "Server_channel.hpp"
#include "Server_client.hpp"

extern std::map<int,Client*> socket_client;

extern std::map<std::string,Client*> user_name_client_ptr;

extern std::map<std::string,Channel*> channel_name_channel_ptr;