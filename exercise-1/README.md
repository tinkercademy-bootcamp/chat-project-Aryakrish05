# Exercise 1

**Update this README with your answers to the questions below.**
## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
  - Standard sources may be used, google search results may be used subject to verification and LLMs may be used optionally.
- How can you tell if the source of your information is good?
  - We need to cross-verify with standard sources for each of the topics.
- How would you define "good" in this situation?
  - Good refers to concise and correct.

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.**(Done)**
- **What are the most important command line arguments to learn for `g++`?Read more**
  - name of the file to be compiled
  - -o filename to give a name for output file
  - -c flag for compiling without linking
  - -Ox flag for enabling/disabling compiler optimisations
  - -Wall flag for enabling most common warnings
  - -std=c++[version year 17 or 20] to change standard used for compilation
  - -g to add debug information
- What is the difference between debug vs release versions?
  - Debug version is the version of a software used while testing and development. Debug information may still be present in the code. Compiler optimisations may be disabled in order to ease debugging. 
  - Release version is the version that shall be deployed for usage. This should be void of such debug information and asserts and should be well-tested with almost all edge cases.
- What are the tradeoffs between debug and release versions?
  - The release versions may make use of compiler optimisations and may run faster than debug and release version. However, enabling these optimisations results in increased compile time of the release build in comparison to the debug build.
- What arguments would you use in a debug build?
  - We may need to use debuggers like gdb, so we use -g as a flag while compiling. We may also use -O0 to disable compiler optimisations.
- What about for release?
  - We may use -O2,-O3,etc which are compiler optimisations.
- What other kinds of build types are useful?
  - Benchmark/Performance build
  - Staging build or Pre-release build
  - Test build
  - Sanitized build
## Learn Basics of Make

- Create a Makefile that will speed up the process.**(Done)**
- **[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make
  fundamentals with practical examples and common patterns.**
- How else can you learn about make?
  - [Official manual for GNU make](https://www.gnu.org/software/make/manual/)
  - Using search engines or LLMs
- How can you tell if the resource you are using is correct?
  - Verification with the official manual mentioned above may be done.
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - **How does make know when it needs to rebuild the executables?**
    - The prerequisites are mentioned for a given target. It compares the time when the current target was made and the last modified time of the prerequisites, if these are the same, then it doesn't rebuild the executables. Else it rebuilds.
  - Change your Makefile such that `make clean` will remove `build/` and all its contents **(Done)**
- **What are the most important command line arguments to learn for make?**
  - `make` which builds the default target(the one specified first in Makefile)
  - `make target` which builds a particular target
  - Varibles may also be passed through command line **Read more**
- **What are the most important directives to learn about in Makefile?**
  - `target:prerequisites` - defines a rule
  - `.PHONY`- declares a rule not tied to a file
  - `include`- may be used to split makefiles
  - conditional logic
  - variables **Read More** 
- What are the most important commands to implement in your Makefile?
  - We should have the first/default target to be all(building this results in compilation of the entire program) for eg `make all`
  - `make clean` is also helpful to delete executables
- Which ones are essential, which ones are nice to haves?
  - make all/any-other-targetname must be present at the top which is a default target. Just calling make should complete the build.
  - make clean, used for deleting the executables created now although nice to have is not a necessity.

## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?
  - It will be easier for the person reviewing to find out what changes have been made in that commit
  - Adding comments describing what was done specifically in the commit is also very helpful to the person reviewing. While commiting after making changes to multiple tasks, these comments tend to become very big and hard to read.
- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?
  - As mentioned above it is good to have more number of small commits as if the code stops working after a particular point, it is easy to go back to the previous working version. **clarify**
- **What are the most important commands to know in git?**
  - **Git clone**: used to download existing source code from a remote repository and save it on your system 
    - git clone repository-link 
    - we may also download from the github website
    - We may use different protocols SSH and HTTPS for this **more description incoming**
  - **Git branch**: used to view branches and the existing active branch, create new branch locally and locally delete branches
    - git branch branch-name : used to create a new branch locally [using it for existing branch names is not allowed]
    - git branch -d branch-name : used to locally delete an *existing* branch that is *not active*
    - git branch or git branch --list : used to view which branches are present and which one of them is active
    - **many more from https://git-scm.com/book/en/v2/Git-Branching-Branch-Management**

  - **Git checkout**: used to switch from one branch to another usually. The changes in the current branch must be committed for this to be a valid operation.
    - git checkout locally-existing-branch-name
    - git checkout -b new-branch-name: Creates a new branch locally and switches to it
  
  - **Git status** : used to display information about the existing branch - shows:
    - the changes not staged for commit
    - changes to be committed
    - untracked files
    - and whether the branch is up to date with or not **what is this**
  
  - **Git add** : modified files should be added to the next commit in order for their changes to be committed
    - git add filename : for a single file
    - git add -A : for all the files
    - *NOTE*: These changes are not effected until we do the next commit
  - **Git commit** : saving the changes done *locally* so far- like making a checkpoint which can be visited later
    - git commit -m "commit message"
    - **what happens if you commit only some of the changed things and attempt to push ?**

  - **Git push** : uploading commits to the remote server
    - git push remote-repo-name branch-name 
    - **not completely clear**

  - **Git pull** :

  - **Git merge** :

  - **Git revert** :

  - **Git rebase** :

  - **Git difference**:

  - **Git stash**:

  - **Git log** :

  - **Git init**: 
  - **Git origin**:
## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments **(Done)**
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- **What do all these headers do? Find out more about them**
  - These contain the implementations of functions and macros which are essential for the functioning of the program.
    - **unistd.h**- Provides access to POSIX API[read(),close()] 
    - **sys/types.h** - Provides system data types like size_t (not required as it is indirectly included by other headers)
    - **arpa/inet.h**- Provides functions for interconversion of addresses between human readable and binary types [inet_pton()]
    - **netinet/in.h**- Provides structs,consts and functions for usage of protocols like IPv4 and IPv6 [sockaddr_in,htons()]
    - **sys/socket.h**- Has structures and functions defined which are essential for socket programming [socket(),connect(),send(),setsockopt(),bind(),listen(),accept()]
- How do you find out which part of the below code comes from which header?
  - After hovering the cursor over the function/object/macros, do Ctrl+click to be redirected to the original location.
  - To get more information on system calls like socket, we may type `man socket` to get more info.
- How do you change the code so that you are sending messages to servers other than localhost?
  - We just have to change the server address appropriately.
  **Do we have to change the port ?**
- **How do you change the code to send to a IPv6 address instead of IPv4?**
  - The struct containing the address sockaddr_in must be changed to sockaddr_in6.This struct has contents
    - sin6_family which must be set to AF_INET6
    - sin6_port which must be set to PortNo
    - sin6_addr- a struct of type in6_addr containing the IPv6 address which must be set to in6addr_any which allows the socket to bind to any process
  - All occurrences of AF_INET should be replaced with AF_INET6
  - The loopback address in the client code must be changed to "::1".
- **Bonus: How do you change the client code to connect by hostname instead of IP address?**
  
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
  - inet_pton does the job of converting the server address given in human readable format to binary format.
  - If the character string given as input doesn't belong to the valid address family mentioned by the first argument, in this case AF_INET(IPv4), then it returns 0.
  - If the address family mentioned as the first argument itself isn't a valid address family, then it returns -1.
  - It returns 1 if the transformation is successful
  - We want our program to run if the transformation is done successfully. So we have this check, if the function returns -1 or 0, we throw an error

- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
  - the connect() system call connects the client socket referred to by the **file descriptor** my_sock to the address specified by the struct sockaddr pointer address.
  - If connection succeeds, a zero is returned, else -1 is returned. We aptly check for this and handle any errors.

- **What is the difference between a pointer and a reference?**
  - A pointer is an address to the memory location at which an object/datatype is present while a reference is an alias to a variable containing an object/datatype.
  - A pointer may not point to a valid object, it may be NULL while a reference must always point to a valid object(What if the destructor of the object was called ?)
  - A reference once bound to one variable cannot be made to refer to another variable.
- When is it better to use a pointer?
  - It is good to use this when you want to allow the pointer to not point to anything, i.e NULL
  - Using pointers becomes essential in construction of data structures like linked lists where we need to keep changing the location where the pointer loop variable is pointing to.

- When is it better to use a reference?
  - A reference may be used while passing to functions to avoid copying. It is better to use this instead of pointers as they are easier to handle.
- **What is the difference between `std::string` and a C-style string?**
  - std::string is an object class defined in the string header file while C-style strings are character arrays which are not defined in any specific header files but are an intrinsic part of C++
  - The string class contains a method called size() which returns the size of the string in O(1) while finding the length of C-style strings takes linear time.
- What type is a C-style string?
  - It is an array of characters terminated with a null character '\0'.
- **What happens when you iterate a pointer?**

  - Let's say the pointer points to a data type (that is **not** `void` — i.e., `ptr++` on a `void*` pointer is not a valid operation) occupying **x bytes** of data in memory.
  - Doing `ptr++` makes the pointer point to  
    **`[current address + x]`**
  - For example, consider:

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;

    struct item {
      int x;
      char y;
      int z;
    };

    int main() {
      item x = {1, 1, 1};
      item* ptr = &x;

      cout << ptr << endl;
      ptr++;
      cout << ptr << endl;
      cout << sizeof(item) << endl;
      cout << sizeof(ptr) << endl;
    }
    ```

    This code prints:

    ```
    0xffffc82060c8
    0xffffc82060d4
    12
    8
    ```

    which shows the above claim.
  - Note that in the above example, the size of the struct item was 12 bytes although summing up the contents just gave 9 bytes. This is because of padded bytes. **Read more**
  - Also because a 64 bit architecture is followed in the system, we have the pointer which is essentially a memory address to be of 8 bytes as can be seen by the output. **How does one find if the remote system is of 32 bit or 64 bit architecture ?**

- What are the most important safety tips to know when using pointers?
  - We should ensure that the pointer is actually pointing to a valid memory location before dereferencing it
  - When memory has been allocated and the pointer is pointing to this allocated memory location, when it is not going to be used, we need to deallocate it to avoid memory leaks.
## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?
  - Compilation may be done by using the command `make` or by separately compiling the two cpp files using `g++`.
  - To run this project all we need to do are open two terminals and run ./server and ./client in that order to establish communication. A similar thing may be done to communicate with another system.
## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()` from `<sys/socket.h>`?
  - The linux man pages, which may be found by typing `man 2 socket` as information is found in the second page of the manual or in the web version https://man7.org/linux/man-pages/man2/socket.2.html
- What is the most authoritative source of information about the TCP and IP protocols?
  - RFC (Requests for comments) published by the IETF (Internet Engineering Task Force)
- What is the most authoritative source of information about the C++ programming language?
  - The C++ ISO standard https://isocpp.org/std/the-standard (need to purchase the document)
  - Other handy references https://en.cppreference.com/ and https://www.stroustrup.com/4th.html (book written by one of the creators about C++)
- **What information can you find about using Markdown when structuring prompts to LLMs?**
  - Using markdown while structuring prompts can help boost their efficiency and performance **WHY**
- What is the difference between LLM and AI?
  - LLM is an application of the broad field of cs-AI. LLMs are trained to understand and generate human language. 
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
  - "An LLM" is correct as there is an 'el' sound while pronouncing it, which starts with a vowel. This is somewhat similar to saying "An Hour" instead of "A Hour".