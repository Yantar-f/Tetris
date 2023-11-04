cmake_minimum_required(VERSION 3.26)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.0/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.0/include)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
