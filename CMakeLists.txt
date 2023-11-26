cmake_minimum_required(VERSION 3.26)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp
        Application.cpp
        Application.h
        StateStack.cpp
        StateStack.h
        states/State.cpp
        states/State.h
        CommonDefinitions.h
        log/Logger.cpp
        log/Logger.h
        FatalTerminationManager.cpp
        FatalTerminationManager.h
        states/StateName.h
        commands/PushStateCommand.cpp
        commands/PopStateCommand.cpp
        commands/ClearStateCommand.cpp
        states/MainMenuState.cpp
        states/MainMenuState.h
        states/PreloadAppState.cpp
        states/PreloadAppState.h
        states/GameState.cpp
        states/GameState.h
        states/GamePauseState.cpp
        states/GamePauseState.h
        Context.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6/include)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
