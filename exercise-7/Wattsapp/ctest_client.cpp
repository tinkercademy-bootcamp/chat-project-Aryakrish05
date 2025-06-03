/* 
 * Attention:
 * To keep things simple, do not handle socket/bind/listen/.../epoll_create/epoll_wait API error 
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define DEFAULT_PORT    8080
#define MAX_CONN        16
#define MAX_EVENTS      32
#define BUF_SIZE        16
#define MAX_LINE        256

void server_run();
void client_run();

int main(int argc, char *argv[])
{
        client_run();
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
void client_run()
{
	int n;
	int c;
	int sockfd;
	char buf[MAX_LINE];
	struct sockaddr_in srv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	set_sockaddr(&srv_addr);

	if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0) {
		perror("connect()");
		exit(1);
	}

	for (;;) {
		printf("input: ");
		fgets(buf, sizeof(buf), stdin);
		c = strlen(buf) - 1;
		buf[c] = '\0';
		write(sockfd, buf, c + 1);

		bzero(buf, sizeof(buf));
		while (errno != EAGAIN
		       && (n = read(sockfd, buf, sizeof(buf))) > 0) {
			printf("echo: %s\n", buf);
			bzero(buf, sizeof(buf));

			c -= n;
			if (c <= 0) {
				break;
			}
		}
	}
	close(sockfd);
}