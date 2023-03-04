#include "GameInterface.hpp"

#include "../Game Board/GameBoard.hpp"

#include <iostream>
#include <Windows.h>

namespace core {
    void game_interface::run( ) noexcept {
        // Print welcome message
        std::cout << "Welcome to snake game!" << '\n';

        // Wait for user input
        std::cout << "Press any key to configure the game...";
        std::cin.get( );

        // Clear the screen
        clear_screen( );

        // Configure the game
        configure_game( );
    }

    void game_interface::configure_game( ) noexcept {
        std::cout << "Enter the board size (width height): ";
        int width { };
        int height { };
        std::cin >> width >> height;

        std::cout << "Enter the snake size: ";
        int snake_size { };
        std::cin >> snake_size;

        // Wait for user input
        std::cout << "Press any key to start the game...";
        std::cin.get( );

        // Clear the screen
        clear_screen( );

        // Create the game board
        game_board board {
            data_types::vector2d {width, height},
            static_cast< std::uint32_t >( snake_size )
        };

        // Run the game
        board.run( clear_screen );
    }

    void game_interface::clear_screen( ) noexcept {
        // https://stackoverflow.com/questions/1733582/how-to-clear-the-console-screen-in-c
        COORD topLeft { 0, 0 };
        HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );

        CONSOLE_SCREEN_BUFFER_INFO screen { };
        unsigned long written { };

        // Get the number of cells in the current buffer
        ::GetConsoleScreenBufferInfo( console, &screen );

        // Fill the entire buffer with spaces
        ::FillConsoleOutputCharacterA( console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written );

        // Fill the entire buffer with the current colors and attributes
        ::FillConsoleOutputAttribute( console,
                                      FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                                      screen.dwSize.X * screen.dwSize.Y,
                                      topLeft,
                                      &written );

        // Move the cursor to the top left
        ::SetConsoleCursorPosition( console, topLeft );
    }
} // namespace core