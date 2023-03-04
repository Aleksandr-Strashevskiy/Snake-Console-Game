# Snake-Console-Game
Snake Game is a classic arcade game created using C++ and WinApi. In this game, the player controls a snake that moves around the screen, eating food and growing in length. The objective is to avoid colliding with the walls or the snake's own tail. The game features a simple graphical user interface in console.

## Prerequisites
To build and run the game, you'll need the following software:
* [Clang 15.0](https://github.com/mstorsjo/llvm-mingw) or later
* [CMake 3.25](https://cmake.org/download/) or later
* [Git](https://git-scm.com/downloads) (optional)

## Building the game
### Downloading the repository
To download the repository, follow these steps:
1. Open a command prompt and navigate to the directory where you want to clone the repository.
2. Run the following command to clone the repository:
```git
git clone https://github.com/Aleksandr-Strashevskiy/Snake-Console-Game.git
```
This will create a new directory named **Snake-Console-Game** in the current directory, containing the source code for the game.

### Building with CMake
To build the game using CMake, follow these steps:
1. Open a command prompt and navigate to the root directory of the repository.
2. Run the following commands to create a build directory and generate the build files:
```cmake
mkdir build
cd build
cmake ..
```
3. Run the following command to build the game:
```cmake
cmake --build .
```
This will create an executable file named **"SNAKE_GAME_${CMAKE_BUILD_TYPE}.exe"** in the **bin** directory.

### Building without CMake
To build the game without CMake, follow these steps:
1. Open a command prompt and navigate to the root directory of the repository.
2. Run the following command to build the game:
```clang
clang++ -Wall -Wextra -Wpedantic -mwindows src/*.cpp -lwinmm -o Snake.exe
```
This will create an executable file named **"Snake.exe"** in the root directory.

## Running the game
### The version you have compiled
To run the game, follow these steps:
1. Open a command prompt and navigate to the directory containing the exe file.
2. Run the following command to start the game:
```cmd
./<compiled_name>.exe
```
Alternatively, you can double-click on the Snake.exe file to start the game.

### Release version
To run the game, follow these steps:
1. Go to [Releases](https://github.com/Aleksandr-Strashevskiy/Snake-Console-Game/releases) page in github
2. Choose the version that suits you and download it
3. Launch it

## Controls
Use the arrow keys or the **W**, **A**, **S**, and **D** keys to move the snake around the screen.

## License
This game is released under the MIT License. See the [LICENSE](https://github.com/Aleksandr-Strashevskiy/Snake-Console-Game/blob/Release/LICENSE) file for details.

## History
The Snake Game project was created in the first year of university as a fun way to kill time in classes. Since then, it has been updated and improved with new features and better performance. It is now being made available to the public as an open source project.
