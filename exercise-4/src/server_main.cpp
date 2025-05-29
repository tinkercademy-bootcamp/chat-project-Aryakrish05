#include <iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include "tcp_echo_server/tcp_echo_server.hpp"
#include "socket_creation/socket_creation.hpp"

int main() {
  const int kPort = 8080;
  int my_socket = create_socket();
  sockaddr_in address = create_address(kPort);

  start_listening_on_socket(my_socket, address);
  std::cout << "Server listening on port " << kPort << "\n";
  handle_connections(my_socket, kPort);
  close(my_socket);

  return 0;
}