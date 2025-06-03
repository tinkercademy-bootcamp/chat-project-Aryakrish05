#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/epoll.h>

#include <arpa/inet.h>
#include <netinet/in.h>
//#include <netdb.h>

#include <fcntl.h>
 
#include <cstring>

#include "utils.hpp"
//#include "Server_channel.hpp"
//#include "Server_client.hpp"
//#include "Database.hpp"

static void epoll_ctl_add(int epfd,int fd,uint32_t events){
        struct epoll_event ev;
        ev.events=events;
        ev.data.fd=fd;
        print_error((epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev)==-1),
                        "epoll_ctl()");
}

static void set_sockaddr(sockaddr_in * addr){
        memset(addr, 0, sizeof(sockaddr_in));
        addr->sin_family=AF_INET;
        addr->sin_addr.s_addr=INADDR_ANY;
        addr->sin_port=htons(PORT);
}

static int set_non_blocking(int socketfd){
        int errcode=fcntl(socketfd,F_SETFL,fcntl(socketfd,F_GETFL,0)|O_NONBLOCK);
        if(errcode==-1){
                return -1;
        }
        return 0;
}

void server_run(){
        char buf[BUF_SIZE];
        
        int epfd=epoll_create1(0);
        
        int listen_sock=socket(AF_INET,SOCK_STREAM,0);
        sockaddr_in server_address;
        set_sockaddr(&server_address);
        print_error(bind(listen_sock,(sockaddr*)&server_address,sizeof(server_address))<0,
                "bind failed");
        
}