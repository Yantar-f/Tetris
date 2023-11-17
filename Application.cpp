#include "Application.h"
#include <chrono>

using namespace std::chrono_literals;

Application::Application() :
    mainWindow(sf::VideoMode(800,600), "Tetris", sf::Style::Close) {}

void Application::run() {
    while (mainWindow.isOpen()) {
        processEvents();
        update();
        render();

        if (stateStack.isEmpty()) mainWindow.close();
    }
}

void Application::processEvents() {
    sf::Event event {};

    while (mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mainWindow.close();
            return;
        }

        stateStack.handleEvent(event);
    }
}

void Application::update() {
    stateStack.update(stampTimePoint());
}

void Application::render() {
    stateStack.draw();
}

TimePointMs Application::stampTimePoint() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now());
}
