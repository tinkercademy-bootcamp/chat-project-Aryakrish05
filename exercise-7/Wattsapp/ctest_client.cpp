/* 
 * Attention:
 * To keep things simple, do not handle socket/bind/listen/.../epoll_create/epoll_wait API error 
 */
#include "Server.hpp"
#include <cstdlib>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define DEFAULT_PORT    8080
#define MAX_CONN        16
#define MAX_EVENTS      32
#define BUF_SIZE        16
#define MAX_LINE        256

void server_run();
void client_run(char[]);

int main(int argc, char * argv[])
{
	if(argc!=2){
		std::cerr<<"Invalid call to exec"<<std::endl;
		exit(EXIT_FAILURE);
	}
        client_run(argv[1]);
	return 0;
}

/*
 * register events of fd to epfd
 */
static void epoll_ctl_add(int epfd, int fd, uint32_t events)
{
	struct epoll_event ev;
	ev.events = events;
	ev.data.fd = fd;
	if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) == -1) {
		perror("epoll_ctl()\n");
		exit(1);
	}
}

static void set_sockaddr(struct sockaddr_in *addr)
{
	bzero((char *)addr, sizeof(struct sockaddr_in));
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = INADDR_ANY;
	addr->sin_port = htons(DEFAULT_PORT);
}

static int setnonblocking(int sockfd)
{
	if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) ==
	    -1) {
		return -1;
	}
	return 0;
}

/*
 * test clinet 
 */
void client_run(char log_file[])
{
	std::ofstream logger(log_file);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in srv_addr;
	set_sockaddr(&srv_addr);

	if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0) {
		perror("connect()");
		exit(1);
	}

	int epoll_fd = epoll_create1(0);
	setnonblocking(sockfd);
	setnonblocking(STDIN_FILENO);

	epoll_ctl_add(epoll_fd, sockfd, EPOLLIN | EPOLLET);
	epoll_ctl_add(epoll_fd, STDIN_FILENO, EPOLLIN | EPOLLET);

	char buf[MAX_LINE];
	struct epoll_event events[MAX_EVENTS];
	logger<<"input: ";
	for (;;) {
		int no_events = epoll_wait(epoll_fd, events, MAX_EVENTS, 5000);
		for (int i = 0; i < no_events; i++) {
			int fd = events[i].data.fd;

			if (fd == sockfd) {
				std::string message = "";
				for (;;) {
					int bytes = recv(sockfd, buf, sizeof(buf), 0);
					if (bytes <= 0) {
						if (errno == EAGAIN || errno == EWOULDBLOCK) break;
						if (bytes == 0) {
							std::cout << "Server closed connection.\n";
							close(sockfd);
							return;
						}
						perror("recv");
						break;
					}
					message.append(buf, bytes);
				}
				logger<< "Server sent message: " << message << std::endl;
				logger<< "input: ";
			} else if (fd == STDIN_FILENO) {
				std::cout<<"input: ";
				if (fgets(buf, sizeof(buf), stdin)) {
					send(sockfd, buf, strlen(buf), 0);
					logger<<buf<<std::endl;
				}
			}
		}
	}
	close(sockfd);
}
