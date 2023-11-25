#include "Application.h"
#include <chrono>
#include "Log/Logger.h"
#include "states/PreloadAppState.h"
#include "states/MainMenuState.h"
#include "states/GameState.h"
#include "states/GamePauseState.h"

using namespace std::chrono_literals;

Application::Application(sf::VideoMode videoMode, const std::string& windowTitle, sf::Uint32 windowStyle) :
    context(videoMode, windowTitle, windowStyle),
    stateStack(context) {}

void Application::run() {
    registerStates();
    initializeStates();

    while (context.renderWindow.isOpen()) {
        processEvents();
        update();
        render();

        if (stateStack.isEmpty()) {
            LOG_INFO("StateStack is empty");
            context.renderWindow.close();
        }
    }
}

void Application::processEvents() {
    sf::Event event {};

    while (context.renderWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            LOG_INFO("Window close request");
            stateStack.clearStates();
            context.renderWindow.close();
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
    stateStack.registerState<PreloadAppState>(StateName::PreloadApp);
    stateStack.registerState<MainMenuState>(StateName::MainMenu);
    stateStack.registerState<GameState>(StateName::Game);
    stateStack.registerState<GamePauseState>(StateName::GamePause);
}

void Application::initializeStates() {
    stateStack.pushState(StateName::MainMenu);
    stateStack.pushState(StateName::PreloadApp);
}


