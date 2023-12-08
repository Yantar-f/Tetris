cmake_minimum_required(VERSION 3.26)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tetris main.cpp
        Application.cpp
        Application.hpp
        StateStack.cpp
        StateStack.hpp
        states/State.cpp
        states/State.hpp
        CommonDefinitions.hpp
        log/Logger.cpp
        log/Logger.hpp
        FatalTerminationManager.cpp
        FatalTerminationManager.hpp
        states/StateName.hpp
        commands/PushStateCommand.cpp
        commands/PopStateCommand.cpp
        commands/ClearStateCommand.cpp
        states/MainMenuState.cpp
        states/MainMenuState.hpp
        states/PreloadAppState.cpp
        states/PreloadAppState.hpp
        states/GameState.cpp
        states/GameState.hpp
        states/GamePauseState.cpp
        states/GamePauseState.hpp
        Context.cpp
        states/MenuState.cpp
        states/MenuState.hpp
        states/EndGameMenuState.hpp
        states/EndGameMenuState.cpp
        states/tetris-shapes/TetrisShape.cpp
        states/tetris-shapes/TetrisShape.hpp
        states/tetris-shapes/BShape.cpp
        states/tetris-shapes/BShape.hpp
        states/tetris-shapes/ZShape.cpp
        states/tetris-shapes/ZShape.hpp
        states/tetris-shapes/LShape.cpp
        states/tetris-shapes/LShape.hpp
        states/tetris-shapes/IShape.cpp
        states/tetris-shapes/IShape.hpp
        states/tetris-shapes/ShapeType.hpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6/include)
target_link_libraries(Tetris sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
