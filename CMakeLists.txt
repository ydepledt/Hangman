cmake_minimum_required(VERSION 3.10)


project(hangman)

set(SOURCES src/main.cpp src/Word.cpp src/Game.cpp src/Settings.cpp src/File.cpp src/utils.cpp)
add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
target_include_directories(main PRIVATE include)
