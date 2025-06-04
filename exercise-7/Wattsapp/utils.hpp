#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
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
        CHANNELNAME_IN_USE='o',
        CHANNEL_JOINED='p',
        
        SEPARATOR='~',
        TERMINAL='|'
};

void print_error(bool condition, const std::string& error_msg);
void split_message(const std::string& message,std::string& first_argument,std::string& second_argument);
void split_message(const std::string& message, std::string& argument);
void make_message(const char command,const std::vector<std::string>& arguments,std::string& message);

#endif