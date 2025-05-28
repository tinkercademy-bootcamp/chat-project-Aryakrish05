# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files **(Done)**
- How would you compile from the command line?
  - `g++ client_main.cpp cpp_files/socket_creation.cpp cpp_files/tcp_echo_client.cpp -o client`
  - `g++ server_main.cpp cpp_files/socket_creation.cpp cpp_files/tcp_echo_server.cpp -o server`
  - The above commands may be used to compile and link the files. Executables are directly created in the src directory
- How would you compile using make?
  - Makefile has been created, simply calling make will make the object files, link them and store the executables in the build/ directory
  - The good thing about this is that the object files of the cpp files corresponding to the headers once created need not be obtained by recompilation again when changes are made only to main files. This saves compilation time. **However the linking process will take the same amount of time ?**
- **How would you compile using VS Code?**
  - A tasks.json file may be created in .vscode folder in the exercise-4 directory. This may be filled with the commands needed to compile the code.
  - Using Ctrl+Shift+B, the compiling and linking may be done.
### Compiling vs Linking

- What is the difference between compiling and linking in C++?
- What is the difference between creating an executable and creating a 
  library?
- How do you compile a library, and then use that library to compile an
  executable?

### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
- Is there a difference in compilation time between the two?
- How can you assess performance other than compilation speed?