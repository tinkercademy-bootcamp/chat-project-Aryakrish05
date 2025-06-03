#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <system_error>
#include <vector>

#define PORT            8080
#define MAX_CONN        16
#define MAX_EVENTS      32
#define BUF_SIZE        16
#define MAX_LINE        256

//predefined starting characters of each communicated message between server and client
//indicate which character corresponds to which command
enum Command{
        
        CREATE_USERNAME='a',
        
        SEND_INVITE='b',
        REC_INVITE='c',
        ACCEPT_INVITE='d',
        
        CREATE_CHANNEL='e',
        SEND_MSG_CHANNEL='f',
        REC_MSG_CHANNEL='g',
        EXIT_CHANNEL='h',

        USER_CREATED='i',
        USERNAME_IN_USE='j',
        CHANNEL_EXITED='k',
        CHANNEL_CREATED='l',
        INVALID_INVITEE='m',
        INVITED='n',
        CHANNELNAME_IN_USE='m',
        
        SEPARATOR='~',
        TERMINAL='\0'
};

void print_error(bool condition, const std::string& error_msg) {
    if (condition) {
        std::cerr << error_msg << '\n';
    }
}
void split_message(const std::string& message,std::string& first_argument,std::string& second_argument){
        int i;
        for(i=1;i<message.size();i++){
                if(message[i]==Command::SEPARATOR)break;
                first_argument+=message[i];
        }
        for(i=i+1;i<message.size();i++){
                second_argument+=message[i];
        }
}
void split_message(const std::string& message, std::string& argument){
        int i;
        for(int i=1;i<message.size();i++){
                argument+=message[i];
        }
}
void make_message(const char command,const std::vector<std::string>& arguments,std::string& message){
        message="";
        message+=command;
        for(int i=0;i<arguments.size();i++){
                message+=Command::SEPARATOR;
                message+=arguments[0];
        }
        message+=Command::TERMINAL;
}
#endif