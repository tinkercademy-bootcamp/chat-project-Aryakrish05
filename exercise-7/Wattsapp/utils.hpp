#ifndef UTILS_HPP
#define UTILS_HPP

//predefined starting characters of each communicated message between server and client
//indicate which character corresponds to which command
enum class Command:char{
        CREATE_USERNAME='a',
        SEND_INVITE='b',
        ACCEPT_INVITE='c',
        CREATE_CHANNEL='d',
        SEND_MSG_CHANNEL='e',
        EXIT_CHANNEL='f',
};

#endif