#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <string>
#define PORT 8080
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

#endif