#include "../error_handling.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <optional>
#include <string>
int create_socket() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  check_error(sock < 0, "Socket creation error\n");
  return sock;
}

sockaddr_in create_address(int port,const std::optional<std::string> &server_ip=std::nullopt) {
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  if(server_ip){
    // Convert the server IP address to a binary format
    auto err_code = inet_pton(AF_INET, server_ip.value().c_str(), &address.sin_addr);
    check_error(err_code <= 0, "Invalid address/ Address not supported.\n");
  }
  else{
    address.sin_addr.s_addr=INADDR_ANY;
  }
  return address;
}