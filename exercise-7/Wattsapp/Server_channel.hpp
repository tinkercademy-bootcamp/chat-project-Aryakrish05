#ifndef SERVER_CHANNEL_HPP
#define SERVER_CHANNEL_HPP
#include <string>
#include <set>
class Client;
class Channel{
private:
        std::string channel_name;
        std::set<Client*>client_list;
public:
        Channel(std::string name,Client* client_member);
        ~Channel();
        //channel must have at least one person, else destructor shall be called
        void broadcast_data(std::string data);
        void remove_client(Client* client_member);
        void add_client(Client* client_member);
        bool check_client(Client* client_member);
        std::string get_channel_name();
};

#endif