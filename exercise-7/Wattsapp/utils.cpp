#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"
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
        int N_1=static_cast<int>(arguments.size())-1;
        for(int i=0;i<N_1;i++){
                message+=arguments[i];
                message+=Command::SEPARATOR;
        }
        if(arguments.size()){
                message+=arguments[N_1];
        }
        message+=Command::TERMINAL;
}