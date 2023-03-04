#ifndef SOURCE_CODE_CORE_GAME_BOARD_GAMEBOARD_HPP
#define SOURCE_CODE_CORE_GAME_BOARD_GAMEBOARD_HPP

#include "../../Utilities/Data Types/Vector2D.hpp"

#include <cstdint>
#include <functional>
#include <vector>

namespace core {
    /**
     * @brief The namespace for the data types
     */
    namespace data_types = utilities::data_types;

    /**
     * @brief The elements of the game board
     */
    enum board_elements : std::int8_t {
        empty      = ' ',
        wall       = '#',
        snake_head = 'X',
        snake_body = 'x',
        food       = 'O'
    };

    class game_board {
      public:
        /**
         * @brief Construct a new game board object
         * @param board_size The size of the game board
         * @param snake_init_size The initial size of the snake
         */
        explicit game_board( const data_types::vector2d &board_size, std::uint32_t snake_init_size ) noexcept;

        /**
         * @brief Run the game
         * @param clear_console The function to clear the console
         */
        void run( const std::function< void( ) > &clear_console ) noexcept;

      private:
        /**
         * @brief Create a board object
         * @return std::vector< std::vector< char > > The game board
         */
        [[nodiscard]] std::vector< std::vector< char > > create_board( ) const noexcept;
        /**
         * @brief Create a snake object
         * @return std::vector< data_types::vector2d > The snake
         */
        [[nodiscard]] std::vector< data_types::vector2d > create_snake( ) const noexcept;

        /**
         * @brief Update the snake
         * @param direction The direction of the snake
         * @param snake The snake
         * @param food The food
         */
        void update_snake( std::int8_t direction,
                           std::vector< data_types::vector2d > &snake,
                           std::vector< data_types::vector2d > &food ) noexcept;

        /**
         * @brief Place food on the game board
         * @param food The food
         */
        void place_food( std::vector< data_types::vector2d > &food ) const noexcept;

        /**
         * @brief Update the game board
         * @param board The game board
         * @param snake The snake
         * @param food The food
         */
        static void update_board( std::vector< std::vector< char > > &board,
                                  const std::vector< data_types::vector2d > &snake,
                                  const std::vector< data_types::vector2d > &food ) noexcept;

        /**
         * @brief Check if the game is over
         * @param board The game board
         * @param snake The snake
         * @return true The game is over
         * @return false The game is not over
         */
        [[nodiscard]] bool is_game_over( std::vector< std::vector< char > > &board,
                                         std::vector< data_types::vector2d > &snake ) const noexcept;

        /**
         * @brief Print the game board
         * @param board The game board
         */
        void print_board( const std::vector< std::vector< char > > &board ) const noexcept;

        /**
         * @brief The initial size of the snake
         */
        std::uint32_t m_snake_init_size { };
        /**
         * @brief The score of the game
         */
        std::uint32_t m_score { };
        /**
         * @brief The size of the game board
         */
        data_types::vector2d m_board_size { };
    };
} // namespace core

#endif // SOURCE_CODE_CORE_GAME_BOARD_GAMEBOARD_HPP