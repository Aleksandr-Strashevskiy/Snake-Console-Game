# Use FILE command with GLOB_RECURSE option to find all .cpp files recursively in current directory
FILE( GLOB_RECURSE SRC_FILES *.cpp )

# Add the found .cpp files to the target sources of the project
TARGET_SOURCES( ${PROJECT_NAME} PRIVATE ${SRC_FILES} )