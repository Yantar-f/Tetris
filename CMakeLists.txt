cmake_minimum_required(VERSION 3.26)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp
        Application.cpp
        Application.h
        ApplicationStates/StateStack.cpp
        ApplicationStates/StateStack.h
        ApplicationStates/State.cpp
        ApplicationStates/State.h
        CommonTypedefs.h
        Log/Logger.cpp
        Log/Logger.h
        FatalTerminationManager.cpp
        FatalTerminationManager.h
        ApplicationStates/StateType.h
        ApplicationStates/Commands/PushStateCommand.cpp
        ApplicationStates/Commands/StateStackCommand.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6/include)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
