#include "Application.h"
#include <chrono>
#include "Log/Logger.h"
#include "states/PreloadAppState.h"
#include "states/MainMenuState.h"
#include "states/GameState.h"
#include "states/GamePauseState.h"

using namespace std::chrono_literals;

Application::Application() :
    context(
        sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT),
        DEFAULT_WINDOW_TITLE,
        DEFAULT_WINDOW_STYLE,
        DEFAULT_RESOURCE_PATH),
    stateStack(context) {
    LOG_INFO("Application initiated with default parameters");
}

Application::Application(sf::VideoMode videoMode, const std::string& windowTitle, sf::Uint32 windowStyle, const char* resourcePath) :
    context(videoMode, windowTitle, windowStyle, resourcePath),
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


