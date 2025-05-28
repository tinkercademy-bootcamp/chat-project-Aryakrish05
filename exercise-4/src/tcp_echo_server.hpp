#ifndef TCP_ECHO_SERVER_HPP
#define TCP_ECHO_SERVER_HPP 1
#include <sys/types.h>
#include<netinet/in.h>

void set_socket_options(int sock, int opt);

sockaddr_in create_address(int port);

void bind_address_to_socket(int sock, sockaddr_in &address);

void listen_on_socket(int sock);

void start_listening_on_socket(int my_socket, sockaddr_in &address);

void handle_accept(int sock);

void handle_connections(int sock, int port);

#endif