//
// Created by Yantar on 05/11/2023.
//
#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#pragma once
#include <SFML\Graphics.hpp>
#include <chrono>

using namespace std::chrono_literals;

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update(std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> timePoint);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mainWindow;
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> previousTickTimePointMs;
    std::chrono::milliseconds tickDurationMs;
};


#endif //TETRIS_APPLICATION_H
