# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- **What's an easy way to identify the changes in source code from one exercise
  to another?**
    - We may use the command `diff -ru exercise-x/src/ exercise-y/src/` to compare code directories of exercises x and y after being in the directory of the repository, this is assuming that the changes to both exercises are comitted in the same branch of the repository
    **what if they are in diff repositories ? How to use git for this ?**
## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
  - I think there are better ways, for example I think separating the functions declared/defined in main files for client and server may be separately maintained in different header and cpp files. We may also modify Makefile accordingly such that when we do any changes to the main files, we wouldn't have to recompile all the addresses
  - I also think the header file need not be included in the corresponding cpp file. **Is this correct ?**
- What are the advantages and disadvantages?
  - One advantage that I observed in this kind of partitioning is that it is slightly more clearer and there aren't too many files, writing a Makefile for this is also comparitively easier
  - A disadvantage as mentioned in the above question is that if the server address is changed, the entire file with all the functions need to be compiled which will take more time than if the functions were in a separate file
## Introduction to Namespace

- There are different ways namespace is being used in this exercise
- Which way is better? What are the advantages and disadvantages?

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
- What namespace and directory structure should you use? Why?

## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory structure? 
- How do you judge what makes a good naming convention or programming style?

## "Senses" in Programming

- Have you ever heard of programmers referring to "code smells"? How can code
  smell?
    - These are warning signs which point to potential structural weaknesses(now or in the future if current practices continue). They arise mostly because of following bad patterns in codes.
    - These make readability and maintainability of the code quite hard.
    - Some types of smells are described below.
      - structural smell- duplicate code, long functions and classes that are designed to do too many things
      - behavioural smell- dead parts of code which are not being used
      - design smells- data clumps(if a set of variables are being passed to functions together multiple times but are not in the same class). This is bad design. 
      - readability smells- poor naming of functions or variables.
- What does it mean to have a sense of taste in programming? How can code taste?
    - These depend on how logically abstractions have been made by the programmer.
    - A code with a good taste would be simple and minimal with more emphasis on clarity than obscure optimisations.
- Is there an analogue for every sense?
  - Yes, a brief description is given below.
- What other code senses can you think of?
  - Sight - how appealing the code is to a reviewer,depends on how well and consistently the code has been formatted
  - Touch - how the shortcuts and tools in the IDE feel to a programmer.
  - Sound - how the logical flow of the program is designed
- How many senses do humans have?
  - 5 senses
- When would you want to see something before you touch it?
  - Say there is a codebase written in a language I am familiar with and I am asked to make certain modifications/improvements. I feel it would be better for me to read the code and get an understanding of how the code is structured and what each part of the code does before starting to work on it.
- When would you want to touch something before you see it?
  - I feel it is sometimes better to try out the functions in a library or an unfamiliar programming language before reading large codebases involving features from that library or that programming language to gain better intuition or clarity. 