//
// Created by Yantar on 05/11/2023.
//

#include "Application.h"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

bool isMovingUp = false;
bool isMovingDown = false;
bool isMovingLeft = false;
bool isMovingRight = false;

std::chrono::duration pressDelay = {5ms};
std::chrono::duration curDelayState = std::chrono::system_clock::now().time_since_epoch();

sf::CircleShape shape(40.f);



Application::Application() :
    mainWindow(sf::VideoMode(800,600), "Tetris", sf::Style::Close) {}

void Application::run() {
    while (mainWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event {};

    while (mainWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                mainWindow.close();
                break;
            }

            case sf::Event::KeyPressed : {
                handlePlayerInput(event.key.code, true);
                break;
            }

            case sf::Event::KeyReleased : {
                handlePlayerInput(event.key.code, false);
                break;
            }

            default: break;
        }

    }
}

void Application::update() {
    if (std::chrono::system_clock::now().time_since_epoch() > curDelayState) {
        sf::Vector2f movement {0.f, 0.f};

        if (isMovingUp) movement.y -= 1.f;
        if (isMovingDown) movement.y += 1.f;
        if (isMovingLeft) movement.x -= 1.f;
        if (isMovingRight) movement.x += 1.f;

        shape.move(movement);
        curDelayState = std::chrono::system_clock::now().time_since_epoch() + pressDelay;
    }
}

void Application::render() {
    mainWindow.clear();

    shape.setFillColor(sf::Color::Cyan);

    mainWindow.draw(shape);
    mainWindow.display();
}

void Application::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) isMovingUp = isPressed;
    else if (key == sf::Keyboard::S) isMovingDown = isPressed;
    else if (key == sf::Keyboard::A) isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D) isMovingRight = isPressed;
}
