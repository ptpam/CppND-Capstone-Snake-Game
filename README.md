# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. To clean the bulid directory `make clean`
3. Compile: `make build`
4. Run it: `./build/SnakeGame`.

## Changes made

### 📤 Loops, Functions, I/O 
Introduced clear and logical loops and functions, akin to a well-organized recipe for better code comprehension. Enabled efficient data reading from files, emphasizing a structured narrative. Additionally, implemented user-friendly input prompts for smoother interactions.
### 🎨 Object-Oriented Programming
Introduced new classes with appropriate access specifiers and methods, adhering to a structured organization for better code management.
Established a rational inheritance hierarchy among classes, with virtual and override functions enhancing the code's extensibility.
Utilized overloaded functions strategically to offer flexibility in code application, resembling a versatile toolkit.
### 🌐 Memory Management 
Integrated destructors appropriately, aligning with the Resource Acquisition Is Initialization (RAII) pattern for efficient resource management. Implemented all aspects of the Rule of 5, emphasizing move semantics for optimized data handling. Incorporated references judiciously for smooth data access, avoiding the complexities associated with raw pointers.
### 🔐  Concurrency 
Introduced multithreading components, allowing parallel execution for improved performance and responsiveness. Implemented mutex strategically to synchronize thread execution, ensuring data integrity in a multi-threaded environment.

🚀 Program Grand Finale:
* The program starts by prompting the user for their name.
* The game terminates when the snake is not alive or if the user presses ESC.
* Scores are saved into a file, and the top 10 players are displayed at the end.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
