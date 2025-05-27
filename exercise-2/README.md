# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?
  - We may need to use `SOCK_RAW` while implementing our custom protocols
  - `SOCK_RAW` is used to give raw access to the data-link layer and network layer( ignoring the transport layer)
  - This may be used to bypass protocols like TCP and UDP
### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
  - No it's just a draft of the spec.
- Where is the official C++23 spec?
  - To view the official spec, one needs to purchase from the link mentioned in https://isocpp.org/std/the-standard.
- Why was this link chosen instead?
  - The official spec is not available online and this is probably the latest draft before the spec was published.
- Is this a helpful reference for learning C++?
  - I don't think so, it will only serve as a reference for experienced programmers who may be writing compilers for C++ and stuff.
  - This as mentioned in the above website is not meant for learners.
- **Can the various implementations of C++ compilers be different from the C++ standard?**
  - Compilers must aim to follow the C++ standard but may differ in certain aspects of implementation.
- What are the most widely used and most significant C++ compilers?
  - GCC and Clang
- Where is the equivalent spec for C++26?
  - Although the final standard document hasn't been finalised, the most recent draft can be found on
  [C++26 Draft](https://open-std.org/jtc1/sc22/wg21/docs/papers/2025/n5008.pdf) which was obtained from the [Github Repository](https://github.com/cplusplus/draft).
- Where do you find the spec for the HTTP protocol?
  - [Links to official HTTP specs](https://httpwg.org/specs/) is where we may find the latest specifications for the HTTP protocol, some of the RFCs by the IETF.
- What about HTTPS? Is there a spec for that protocol?
  - There is no separate spec for this protocol. Information on it can be found in the HTTP specs.
## Introduction to C++ and Sockets Programming

- Read the code in `src/`
- Are there any bugs in this code? 
  - I don't think there are any bugs in this code
- What can you do to identify if there are bugs in the code?
  - We may think of test cases or edge cases and run the code on them. 

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
  - This code works almost the same  as exercise-1 but it has the code distributed over various functions which make it more modular and easier to understand.
- Is this code better or worse than exercise-1?
  - This code is better than that of exercise-1 in the way that it is easier to read.
- What are the tradeoffs compared to exercise-1?
  - This might be slightly slower due to overheads due to function calls
- Are you able to spot any mistakes or inconsistencies in the changes?
  - I think the code in my exercise-1 and this code are not different at all. 
  - However I have added an additional function which allows the user to type multiple words in the command line.
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
  - I think performance is slightly impacted when functions are used as there is a certain overhead in function calls, there are some loads and stores on the stack involved.
  - Function calls also cause misses in the instruction caches which may slow down the program.
- What do we mean when we say performance?
  - Performance may mean the time taken by a program to run
- How do we measure performance in a program?
  - We may use libraries like std::chrono to measure the time taken by the program to run.

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- **What is `git tag`? How is `git tag` different from `git branch`?**
  - A tag is a reference to a specific point in the history of a branch
  - It is usually used to mark versions of the code which are functioning well or alternatively release versions
  Some commands using git tag:
    - **git tag** - used to list all the tags
    - **git tag -l "pattern*"**- used to list all the tags starting with a given pattern
    - **git tag `<tagname>`**- used to mark the current state of the repo with a tag. Tags created like this are called lightweight tags. They are pretty much like a branch that doesn't change-a pointer to a specific commit
    - **git tag -a `<tagname>` -m `<message>`**- used to mark the current state of the repo as an **annotated tag**
    - **git show `<tagname>`** - shows the details of a tag
    - **git push origin `<tagname>`**- used to push a locally existing tag onto a remote repo
    - **`git tag -d <tagnames>`** or **`git tag --delete <tagnames>`**- used to delete tags locally
    - **`git push origin -d <tagnames>`** or **`git push origin --delete <tagnames>`** or **`git push origin :<tagname>`** can be used for deleting some tags from a remote repo
    - **`git checkout -b <branch-name> <tag-name>`** - used to create a branch from a tagged checkpoint of the repo and switch to it
- How can you use `git tag` and `git branch` to make programming easier and more fun?
  - Tags may be marked after important commits and branches may be created later from those tagged versions of the repo

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?