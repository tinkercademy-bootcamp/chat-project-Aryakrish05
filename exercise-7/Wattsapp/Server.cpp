#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#include <arpa/inet.h>
#include <netinet/in.h>
//#include <netdb.h>

#include <errno.h>
#include <fcntl.h>
 
#include <cstring>

#include "utils.hpp"
#include "Server_channel.hpp"
#include "Server_client.hpp"
#include "Database.hpp"

static void epoll_ctl_add(int epfd,int fd,uint32_t events){
        struct epoll_event ev;
        ev.events=events;
        ev.data.fd=fd;
        print_error((epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev)==-1),
                        "epoll_ctl()");
}

static void set_sockaddr(struct sockaddr_in * addr){
        memset(addr, 0, sizeof(sockaddr_in));
        addr->sin_family=AF_INET;
        addr->sin_addr.s_addr=INADDR_ANY;
        addr->sin_port=htons(PORT);
}