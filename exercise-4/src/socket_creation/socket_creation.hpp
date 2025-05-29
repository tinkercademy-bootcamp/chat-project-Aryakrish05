#ifndef SOCKET_CREATION_HPP
#define SOCKET_CREATION_HPP 1
#include <string>
#include <netinet/in.h>
#include <optional>
int create_socket();
sockaddr_in create_address(int port,const std::optional<std::string> &server_ip=std::nullopt);
#endif