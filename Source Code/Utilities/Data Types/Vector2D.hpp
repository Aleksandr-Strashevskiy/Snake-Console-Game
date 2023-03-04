#ifndef SOURCE_CODE_UTILITIES_DATA_TYPES_VECTOR2D_HPP
#define SOURCE_CODE_UTILITIES_DATA_TYPES_VECTOR2D_HPP

namespace utilities::data_types {
    class vector2d {
      public:
        /**
         * @brief Construct a new vector2d object
         */
        constexpr vector2d( ) = default;

        /**
         * @brief Construct a new vector2d object
         * @param x coordinate
         * @param y coordinate
         */
        constexpr vector2d( const int x, const int y ) : m_x( x ), m_y( y ) { }

        /**
         * @brief Construct a new vector2d object
         * @param other vector2d object
         */
        bool operator==( const vector2d &other ) const {
            return m_x == other.m_x && m_y == other.m_y;
        }

        /**
         * @brief Construct a new vector2d object
         * @param other vector2d object
         */
        bool operator!=( const vector2d &other ) const {
            return !operator==( other );
        }

        /**
         * @brief Get the x coordinate
         * @return int x coordinate
         */
        [[nodiscard]] constexpr int x( ) const {
            return m_x;
        }

        /**
         * @brief Get the y coordinate
         * @return int y coordinate
         */
        [[nodiscard]] constexpr int y( ) const {
            return m_y;
        }

        /**
         * @brief Set the x coordinate
         * @param x coordinate
         */
        void set_x( const int x ) {
            m_x = x;
        }

        /**
         * @brief Set the y coordinate
         * @param y coordinate
         */
        void set_y( const int y ) {
            m_y = y;
        }

      private:
        /**
         * @brief x coordinate
         */
        int m_x { };
        /**
         * @brief y coordinate
         */
        int m_y { };
    };
} // namespace utilities::data_types

#endif // SOURCE_CODE_UTILITIES_DATA_TYPES_VECTOR2D_HPP