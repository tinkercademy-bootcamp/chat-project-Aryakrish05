#include<sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include "tcp_echo_client.hpp"
#include "socket_creation.hpp"

int main(int argc, char *argv[]) {
  const int kPort = 8080;
  const std::string kServerAddress = "127.0.0.1";

  std::string message = read_args(argc, argv);

  int my_socket = create_socket();
  sockaddr_in server_address = create_address(kServerAddress, kPort);

  connect_to_server(my_socket, server_address);
  send_and_receive_message(my_socket, message);
  close(my_socket);

  return 0;
}