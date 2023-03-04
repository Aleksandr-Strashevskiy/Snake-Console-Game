#include "GameBoard.hpp"

#include <iostream>
#include <random>
#include <thread>

namespace core {
    game_board::game_board( const data_types::vector2d &board_size, const std::uint32_t snake_init_size ) noexcept
        : m_board_size( board_size ), m_snake_init_size( snake_init_size ) { }

    void game_board::run( const std::function< void( ) > &clear_console ) noexcept {
        // Create the game board
        auto board = create_board( );

        // Create the snake
        auto snake = create_snake( );

        // Create the food
        std::vector< data_types::vector2d > food { };

        // Start the game loop
        while ( true ) {
            // Place the food
            place_food( food );

            // Update the game board
            update_board( board, snake, food );

            // Print the game board
            print_board( board );

            // Check if the game is over
            if ( is_game_over( board, snake ) )
                break;

            // Get the direction from the user
            std::int8_t direction { };
            std::cin >> direction;

            // Update the snake
            update_snake( direction, snake, food );

            // Clear the screen
            clear_console( );

            // Sleep for 200 milliseconds
            std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
        }
    }

    std::vector< std::vector< char > > game_board::create_board( ) const noexcept {
        // Check if the board size is valid
        if ( m_board_size.x( ) < 0 || m_board_size.y( ) < 0 )
            return { };

        // Create the game board with empty spaces
        std::vector< std::vector< char > > board( m_board_size.x( ),
                                                  std::vector< char >( m_board_size.y( ), board_elements::empty ) );

        // Create the walls
        for ( auto &i : board ) {
            i[ 0 ]             = board_elements::wall;
            i[ i.size( ) - 1 ] = board_elements::wall;
        }

        // Return the game board
        return board;
    }

    std::vector< data_types::vector2d > game_board::create_snake( ) const noexcept {
        // Create the snake
        std::vector< data_types::vector2d > snake( m_snake_init_size, data_types::vector2d( 0, 0 ) );

        // Return the snake
        return snake;
    }

    void game_board::update_snake( const std::int8_t direction,
                                   std::vector< data_types::vector2d > &snake,
                                   std::vector< data_types::vector2d > &food ) noexcept {
        // Check if the snake is out of bounds
        if ( snake.front( ).x( ) < 0 || snake.front( ).x( ) >= m_board_size.x( ) || snake.front( ).y( ) < 0
             || snake.front( ).y( ) >= m_board_size.y( ) )
            return;

        // Check if the snake is eating food
        if ( snake.front( ).x( ) == food.front( ).x( ) && snake.front( ).y( ) == food.front( ).y( ) ) {
            // Remove the food
            food.clear( );

            // Increase the snake's length
            snake.emplace_back( snake.back( ) );

            // Update score
            ++m_score;
        } else {
            // Remove the tail of the snake
            snake.pop_back( );
        }

        // Update the snake
        switch ( direction ) {
            case 'w' :
                snake.insert( snake.begin( ), data_types::vector2d( snake.front( ).x( ) - 1, snake.front( ).y( ) ) );
                break;
            case 'a' :
                snake.insert( snake.begin( ), data_types::vector2d( snake.front( ).x( ), snake.front( ).y( ) - 1 ) );
                break;
            case 's' :
                snake.insert( snake.begin( ), data_types::vector2d( snake.front( ).x( ) + 1, snake.front( ).y( ) ) );
                break;
            case 'd' :
                snake.insert( snake.begin( ), data_types::vector2d( snake.front( ).x( ), snake.front( ).y( ) + 1 ) );
                break;
            default :
                break;
        }
    }

    void game_board::place_food( std::vector< data_types::vector2d > &food ) const noexcept {
        // Create a random number generator
        std::random_device rd { };
        std::mt19937 gen( rd( ) );
        std::uniform_int_distribution<> dis_x( 0, m_board_size.x( ) - 1 );
        std::uniform_int_distribution<> dis_y( 0, m_board_size.y( ) - 1 );

        // Create the food
        food.emplace_back( dis_x( gen ), dis_y( gen ) );
    }

    void game_board::update_board( std::vector< std::vector< char > > &board,
                                   const std::vector< data_types::vector2d > &snake,
                                   const std::vector< data_types::vector2d > &food ) noexcept {
        // Place the snake on the board
        for ( const auto &i : snake )
            board[ i.x( ) ][ i.y( ) ] = board_elements::snake_body;

        // Place the snake head on the board
        board[ snake.front( ).x( ) ][ snake.front( ).y( ) ] = board_elements::snake_head;

        // Place the food on the board
        for ( const auto &i : food )
            board[ i.x( ) ][ i.y( ) ] = board_elements::food;

        // Place the walls on the board
        for ( auto &i : board ) {
            i[ 0 ]             = board_elements::wall;
            i[ i.size( ) - 1 ] = board_elements::wall;
        }
    }

    bool game_board::is_game_over( std::vector< std::vector< char > > &board,
                                   std::vector< data_types::vector2d > &snake ) const noexcept {
        // Check if the snake is out of bounds
        if ( snake.front( ).x( ) < 0 || snake.front( ).x( ) >= m_board_size.x( ) || snake.front( ).y( ) < 0
             || snake.front( ).y( ) >= m_board_size.y( ) )
            return true;

        // Check if the snake has hit itself
        for ( const auto &i : snake ) {
            if ( i == snake.front( ) )
                return true;
        }

        // Check if the snake has hit the wall
        if ( board[ snake.front( ).x( ) ][ snake.front( ).y( ) ] == board_elements::wall )
            return true;

        // Return false
        return false;
    }

    void game_board::print_board( const std::vector< std::vector< char > > &board ) const noexcept {
        // Print the game board
        for ( const auto &row : board ) {
            for ( const auto &element : row )
                std::cout << element;

            std::cout << '\n';
        }

        // Print the score
        std::cout << "Score: " << m_score << '\n';
    }
} // namespace core