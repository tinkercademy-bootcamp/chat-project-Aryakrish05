#ifndef ERROR_HANDLING_HPP
#define ERROR_HANDLING_HPP 1
#include <iostream>
#include <unistd.h>
template <typename T, typename S> void check_error(T test, S error_message) {
  if (test) {
    std::cerr << error_message << "\n";
    exit(EXIT_FAILURE);
  }
}
#endif