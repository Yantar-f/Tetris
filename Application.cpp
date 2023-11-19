#include "Application.h"
#include <chrono>
#include "Log/Logger.h"

using namespace std::chrono_literals;

Application::Application() :
    mainWindow(sf::VideoMode(800,600), "Tetris", sf::Style::Close) {}

void Application::run() {
    while (mainWindow.isOpen()) {
        processEvents();
        update();
        render();

        if (stateStack.isEmpty()) {
            LOG_INFO("StateStack is empty");
            mainWindow.close();
        }
    }
}

void Application::processEvents() {
    sf::Event event {};

    while (mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            LOG_INFO("Window close request");
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
