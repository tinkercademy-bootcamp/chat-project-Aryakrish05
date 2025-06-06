# Exercise 6

**Update this README with your answers to the questions below.**

## Adding Third Party Libraries or Source Code to Your Project

- There is a new file `src/spdlog-hello-world-main.cc`
- It uses the spdlog and fmt libraries. 
  [More info here](https://github.com/gabime/spdlog) - Fast C++ logging 
  library with various sink types and formatting options
- How do you compile this file using the `g++` CLI?
  - If we use the debian package manager `sudo apt install libspdlog-dev` and `sudo apt install libfmt-dev` to install the spdlog and fmt libraries, then we just have to call  `g++ <filename> -o <exec_name> -lspdlog -lfmt` to compile.
  - This is because the linker looks only some locations unless a `-L` flag is specified. The package managers install and place the binaries in these locations.
- What do you need to change in your makefile to use this library?
  - `LDFLAGS` must be modified to include both of these flags `-lspdlog` and `-lfmt` which tell the linker that some programs might need to use these libraries.
  - We should also add a target to compile the spdlog file
- How many different ways can this library be added into your project?
  - Use `sudo apt install libspdlog-dev` to install it onto the default directories which the linker searches for and `#include<spdlog/spdlog.h>` in the .cpp file. While compiling `-lspdlog` must be used as a flag
  - Use other package managers and handle ensure that the `-I` flag is given so that the header files are searched in appropriate locations by the compiler. `-L` should also be given to mention the directories for the linker to find required executables.
  - We may build from source and install, we would  have to clone the git repository and use the appropriate build system, CMake in this case to compile the files. After which we may resort to using `-I` and `-L` flags or just use `sudo make install`. This will copy the binaries and libraries into system wide directories which are by default searched for by our compilers and linkers.
  - **We may copy paste Header-only files manually onto our project directory.**
- What are the tradeoffs in the different ways?
  - The package manager usage is easier to handle but the installed versions may be outdated
  - Building from source may ensure that you install the most recent version but you may have to make any updates manually.
  - copy pasting header only files will take a lot of compilation time which is not good.
- Why are there so many different ways to do it?
  - C++ hasn't provided a default way of doing it and there have been multiple improvements over the years and older methods may only work for legacy software.  
## Static Linking vs Dynamic Linking

- What are the differences between static linking and dynamic linking?
- What are the tradeoffs?
- How do you enable static linking or dynamic linking in your makefile?

## Git Clone and Building from Source

- Where is `g++` looking for the include files and library files?
  - There are two kinds of header files, one enclosed in `""` and the other enclosed in `<>`. For the first one the compiler first searchs in the current directory and then searches in the standard system directories while for the second one it searches in the default include search paths.
  - These default include search paths for includes depend on which operating system is being used, for my ssh system, `/usr/include`,`/usr/lib/gcc/aarch64-linux-gnu/14/include`,`/usr/include/aarch64-linux-gnu` and `/usr/include`   
  In my windows system I got paths like ` c:\mingw\bin\../lib/gcc/mingw32/6.3.0/include`. Note here is that `\` and `/` are both used as directory separators in windows, although `bin\..` is redundant , it is probably present as the compiler binaries are present in `c:\mingw\bin`. 
  - Unless `-I` flags are mentioned, `g++` looks for the include files in these standard directories for the header files, if `-I[path to header-files]` is mentioned, it searches in the path provided first , note that even if the path provided isn't valid, there will be no error thrown and it tries checking in these places, if it can't find the header, it looks in the default include search paths
  - Note about `-I./path/to/directory`- this refers to a directory starting from current directory while `-I/path/to/directory` refers to a directory starting from the root directory `/`.
  - The linker searches first in the directories mentioned in `-L` flags (which is very similar to `-I` flag but is an instruction to the linker) and then in the default library search paths.
  -The default library search paths are `/usr/local/lib/aarch64-linux-gnu`,
`/lib/aarch64-linux-gnu`,`/usr/lib/aarch64-linux-gnu`,`/usr/local/lib`,`/lib`,
`/usr/lib`,`/usr/aarch64-linux-gnu/lib` on my ssh system.
**Does this depend on architecture ?**
- How do you find out?
  - To find where the compiler searches for the header files, 
    `g++ -v -E - < /dev/null` may be used to get the paths searched, on linux.
    On windows, `g++ -v -E - < NUL` may be used. 
  - To get the default directories for libraries, multiple methods exist,for example (in linux)`ld --verbose | grep SEARCH_DIR` may be used.
  - To find where the obj files etc are present in the system for a particular library, we may use `sudo find / -type d -name spdlog 2>/dev/null` on linux.

## C++ Package Managers

- Why are there so many C++ package managers?
- Which one is the best one?
- Which are the most notable ways to manage the compilation of C++ projects?