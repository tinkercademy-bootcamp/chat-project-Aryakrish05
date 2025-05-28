#include "../header_files/error_handling.hpp"
#include <sys/socket.h>
#include <sys/types.h>
int create_socket() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  check_error(sock < 0, "Socket creation error\n");
  return sock;
}