#ifndef SOURCE_CODE_CORE_GAMEINTERFACE_INTERFACE_HPP
#define SOURCE_CODE_CORE_GAMEINTERFACE_INTERFACE_HPP

namespace core {
    class game_interface {
      public:
        /**
         * @brief Runs the game interface
         */
        static void run( ) noexcept;

      private:
        /**
         * @brief Configures the game
         */
        static void configure_game( ) noexcept;

        /**
         * @brief Clears the screen
         */
        static void clear_screen( ) noexcept;
    };
} // namespace core

#endif // SOURCE_CODE_CORE_GAMEINTERFACE_INTERFACE_HPP