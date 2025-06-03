#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#include <arpa/inet.h>
#include <netinet/in.h>
//#include <netdb.h>

#include <fcntl.h>
 
#include <cstring>

#include "Server_channel.hpp"
#include "Server_client.hpp"

static void epoll_ctl_add(int epfd,int fd,uint32_t events);

static void set_sockaddr(sockaddr_in * addr);

static int set_non_blocking(int socketfd);

void parse_message(std::string& message,Client* sender);

void set_socket_options(int sock, int opt);

void server_run();

#endif