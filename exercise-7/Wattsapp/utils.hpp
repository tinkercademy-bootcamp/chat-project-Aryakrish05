#ifndef UTILS_HPP
#define UTILS_HPP

//predefined starting characters of each communicated message between server and client
//indicate which character corresponds to which command
enum class Command:char{
        CREATE_USERNAME='a',
        SEND_INVITE='b',
        REC_INVITE='c',
        ACCEPT_INVITE='d',
        CREATE_CHANNEL='e',
        SEND_MSG_CHANNEL='f',
        REC_MSG_CHANNEL='g'
        EXIT_CHANNEL='h',
        REC_INVITE='i',
};

#endif