#ifndef TCP_ECHO_CLIENT_HPP
#define TCP_ECHO_CLIENT_HPP 1
#include <cstdlib>
#include <netinet/in.h>
#include <string>
#include <sys/types.h>

sockaddr_in create_address(const std::string &server_ip, int port);

void connect_to_server(int sock, sockaddr_in &server_address);

void send_and_receive_message(int sock, const std::string &message);

std::string read_args(int argc, char *argv[]);

#endif