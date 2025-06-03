#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <map>
#include <sys/socket.h>
#include "utils.hpp"
#include "Server_channel.hpp"
#include "Server_client.hpp"

std::map<int,Client*> socket_client;

std::map<std::string,Client*> user_name_client_ptr;

std::map<std::string,Channel*> channel_name_channel_ptr;

#endif