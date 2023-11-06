//
// Created by Yantar on 05/11/2023.
//
#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#pragma once
#include <SFML\Graphics.hpp>
#include <chrono>

typedef std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> TimePointMs;

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update(TimePointMs timePoint);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    TimePointMs stampTimePoint();

    sf::RenderWindow mainWindow;
    TimePointMs previousTickTimePointMs;
    std::chrono::milliseconds tickDurationMs;
};


#endif //TETRIS_APPLICATION_H
