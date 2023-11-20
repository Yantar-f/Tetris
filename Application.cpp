#include "Application.h"
#include <chrono>
#include "Log/Logger.h"
#include "ApplicationStates/MainMenuState.h"
#include "ApplicationStates/PreloadAppState.h"
#include "ApplicationStates/GameState.h"
#include "ApplicationStates/GamePauseState.h"

using namespace std::chrono_literals;

Application::Application() :
    mainWindow(sf::VideoMode(DEFAULT_WINDOW_WIDTH,DEFAULT_WINDOW_HEIGHT), DEFAULT_WINDOW_TITLE, sf::Style::Close) {}

void Application::run() {
    registerStates();
    initializeStates();

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
    stateStack.update(TIME_POINT);
}

void Application::render() {
    stateStack.draw();
}


void Application::registerStates() {
    stateStack.registerState<PreloadAppState>(StateType::PreloadApp);
    /*stateStack.registerState<MainMenuState>(StateType::MainMenu);
    stateStack.registerState<GameState>(StateType::Game);
    stateStack.registerState<GamePauseState>(StateType::GamePause);*/
}

void Application::initializeStates() {
    stateStack.pushState(StateType::PreloadApp);
}

