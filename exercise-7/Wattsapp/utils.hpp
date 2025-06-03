#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>

#define DEFAULT_PORT    8080
#define MAX_CONN        16
#define MAX_EVENTS      32
#define BUF_SIZE        16
#define MAX_LINE        256

//predefined starting characters of each communicated message between server and client
//indicate which character corresponds to which command
enum class Command:char{
        
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
        
        TERMINAL='\0'
};
void print_error(bool condition,std::string error_msg){
        if(condition){
                std::cerr<<error_msg<<"\n";
        }
}
#endif