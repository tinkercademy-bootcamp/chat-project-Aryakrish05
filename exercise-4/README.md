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
  - Compiling is the process in which a single file of a program is converted into the corresponding objfile or .o file.
  - Linking is the process in which multiple obj files are processed by the linker making the final binaries(executable files). This resolves external symbol references(references to functions defined in other files) and identifies the entry point of the program.(usually main())
  Note that even if there is a single file, linking must be done to find the entry point of the program.
- What is the difference between creating an executable and creating a library?
  - An executable contains compiled and linked code in a machine-readable format. This can be executed directly without further processing.
  - A library is a collection of pre-written **(do they have to be compiled already ?)** program files which contain functions/classes/macros which may be imported in other code and used to perform some tasks. A library by itself cannot be executed in general.
- **How do you compile a library, and then use that library to compile an executable?**
  - We may compile a library and use a linker to link the code which uses functions/classes from the library to obtain the final executable.
### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
    - It is good to have multiple small files as it is easier to maintain. Since each file contains a section of the code separated logically, it is easier for someone to read the code.
    - If changes are made to some part of the code, the whole code need not be compiled, in this case, we may save some compile time.
    - This will help when multiple people are working on the same project
    - Although this may take slightly more time when compiling all the files(say the first time it is being compiled), as the project becomes larger, the above pros will easily become more important than this.
- Is there a difference in compilation time between the two?
  - Having multiple files may be slightly slower when building the whole project.
  - Due to more includes, the preprocessing may take more time than when fewer large files are present.
  - I don't think there will be much of a time difference while compiling as the same code is compiled in both cases. It is assumed that the same functions are not defined in different files as then these cannot be linked without encountering errors.
  - Linking may take more time as the linker has to search for a called function across multiple files.
- How can you assess performance other than compilation speed?
  - We may assess performance by looking at the time it takes for the program to run, i.e runtime.