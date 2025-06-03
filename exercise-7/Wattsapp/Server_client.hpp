#ifndef SERVER_CLIENT_HPP
#define SERVER_CLIENT_HPP
#include <string>
#include <set>
class Channel;
class Client{
private:
        std::string user_name;
        int connected_socket;
        std::set<Channel*>channel_list;
public:
        Client(int socket);
        ~Client();
        void join_channel(Channel* channel_ptr);
        void exit_channel(Channel* channel_ptr);
        bool check_channel(Channel* channel_ptr);
        void send_data(const std::string& data);
        std::string get_user_name();
        void set_user_name(std::string new_user_name);
};
#endif