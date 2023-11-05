//
// Created by Yantar on 05/11/2023.
//
#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#pragma once
#include <SFML\Graphics.hpp>

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mainWindow;
};


#endif //TETRIS_APPLICATION_H
