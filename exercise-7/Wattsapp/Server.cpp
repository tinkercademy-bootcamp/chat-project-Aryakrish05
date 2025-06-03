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
void parse_message(std::string& message,Client* sender){
        std::string reply="";
        std::string sender_name=sender->get_user_name();
        if(message[0]==Command::SEND_INVITE){
                //format is USERNAME~CHANNELNAME\0
                int i;
                std::string invitee_name="",channel_name="";
                split_message(message,invitee_name,channel_name);
                if(!user_name_client_ptr.count(invitee_name)){
                        make_message(Command::INVALID_INVITEE,{},reply);
                        sender->send_data(reply);
                        return;
                }
                make_message(INVITED,{},reply);
                sender->send_data(reply);
                //format is USERNAME~CHANNELNAME\0
                make_message(Command::REC_INVITE,
                        {sender_name,channel_name},reply);
                user_name_client_ptr[invitee_name]->send_data(reply);
                return;
        }
        if(message[0]==Command::SEND_MSG_CHANNEL){
                //format CHANNEL~CONTENT\0
                std::string channel_name="";
                std::string content="";
                split_message(message,channel_name,content);
                //format SENDER~CHANNEL~CONTENT\0
                make_message(Command::REC_MSG_CHANNEL,
                        {sender_name,channel_name,content},reply);
                channel_name_channel_ptr[channel_name]->broadcast_data(reply);
                return;
        }
        if(message[0]==Command::CREATE_CHANNEL){
                //CHANNEL
                std::string channel_name;
                split_message(message,channel_name);
                
        }
        if(message[0]==Command::EXIT_CHANNEL){

        }
        if(message[0]==Command::ACCEPT_INVITE){

        }

}
void server_run(){
        char buf[BUF_SIZE];
        char reply[BUF_SIZE];
        epoll_event events[MAX_EVENTS];
        
        int epfd=epoll_create1(0);
        
        int listen_sock=socket(AF_INET,SOCK_STREAM,0);
        sockaddr_in server_address;
        set_sockaddr(&server_address);
        print_error(bind(listen_sock,(sockaddr*)&server_address,sizeof(server_address))<0,
                "bind failed");
        set_non_blocking(listen_sock);
        listen(listen_sock,MAX_CONN);

        epoll_ctl_add(epfd,listen_sock,EPOLLIN|EPOLLOUT|EPOLLET);

        int conn_sock;
        sockaddr_in client_address;
        socklen_t client_address_len=sizeof(client_address);
        for(;;){
                int no_events=epoll_wait(epfd,events,MAX_EVENTS,-1);
                for(int i=0;i<no_events;i++){
                        if(events[i].data.fd==listen_sock){
                                int conn_sock=accept(listen_sock,(sockaddr*)&client_address, &client_address_len);
                                inet_ntop(AF_INET,&client_address.sin_addr,buf,client_address_len);
                                printf("[+] connected with %s:%d\n", buf,
				       ntohs(client_address.sin_port));
                                int no_characters_recd=recv(conn_sock,buf,sizeof(buf),MSG_WAITALL);
                                print_error(no_characters_recd<0, "Username not received");
                                char op_type=buf[0];
                                //op_type here must always be username based
                                if(op_type==Command::CREATE_USERNAME){
                                        std::string user_name="";
                                        for(int i=1;i<no_characters_recd;i++){
                                                if(buf[i]=='\0')break;
                                                user_name+=buf[i];
                                        }
                                        if(user_name_client_ptr.count(user_name)){
                                                buf[0]=Command::USERNAME_IN_USE;
                                                buf[1]=Command::TERMINAL;
                                                print_error(send(conn_sock,buf,2,MSG_NOSIGNAL)<0,"Disconnected before username is entered");
                                                close(conn_sock);                                                
                                        }
                                        else{
                                                buf[0]=Command::USER_CREATED;
                                                buf[1]=Command::TERMINAL;
                                                print_error(send(conn_sock,buf,2,MSG_NOSIGNAL)<0,"Disconnected before username is confirmed");
                                                Client* new_client=new Client(user_name,conn_sock);
                                                user_name_client_ptr[user_name]=new_client;
                                                socket_client[conn_sock]=new_client;
                                        }   
                                }
                                else{
                                        print_error(1, "Invalid Username entry");
                                }
                                set_non_blocking(conn_sock);
                                epoll_ctl_add(epfd,conn_sock,EPOLLIN | EPOLLET | EPOLLRDHUP |
					      EPOLLHUP);
                        }
                        else if(events[i].events & EPOLLIN){
                                std::string message="";
                                for(;;){
					memset(buf,0, sizeof(buf));
					int no_characters_recd = recv(events[i].data.fd, buf,sizeof(buf),0);
                                        for(int i=0;i<no_characters_recd;i++){
                                                if(buf[i]==Command::TERMINAL)break;
                                                message+=buf[i];
                                        }
					if (no_characters_recd <= 0 /* || errno == EAGAIN */ ) {
						break;
					} else {
						printf("[+] data: %s\n", buf);
						print_error(send(events[i].data.fd, buf,strlen(buf),MSG_NOSIGNAL)<0,"Disconnected alr");//
					}
                                }
                        }
                }
        }
}