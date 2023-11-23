#include <iostream>
#include "PreloadAppState.h"
#include "../FatalTerminationManager.h"



PreloadAppState::PreloadAppState(StateStack& stackStack, Context context) : State(stackStack, context), color(sf::Color::Cyan) {
    if (!font.loadFromFile("../resources/fonts/arial.ttf")) {
        LOG_FATAL("Loading font error");
        TERMINATE(EXIT_FAILURE);
    }

    color.a = 0;

    preloadText.setString("Press any key to continue");
    preloadText.setFont(font);
    preloadText.setCharacterSize(20);

    sf::FloatRect textRect = preloadText.getLocalBounds();

    preloadText.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    preloadText.setFillColor(color);
    preloadText.setOutlineColor(sf::Color::Transparent);
    preloadText.setPosition(DEFAULT_WINDOW_WIDTH/2.f, DEFAULT_WINDOW_HEIGHT/2.f);
}

bool PreloadAppState::handleEvent(sf::Event event) {
    /*
    if (event.type == sf::Event::KeyPressed) {
        requestStackPop();
        requestStackPush(StateName::MainMenu);
    }
*/
    return true;
}

bool PreloadAppState::update(TimePointMs timePoint) {
    if (timePoint - prevTick < tickDuration) return true;
    prevTick = timePoint;

    if (preloadText.getFillColor().a == 0) {
        isIncrement = true;
    } else if (preloadText.getFillColor().a == 255) {
        isIncrement = false;
    }

    if (isIncrement) {
        tickDuration += 1ms;
        color.a += 5;
    } else {
        tickDuration -= 1ms;
        color.a -= 5;
    }

    preloadText.setFillColor(color);

    return true;
}

bool PreloadAppState::draw() {
    context.renderWindow.draw(preloadText);
    return true;
}

bool PreloadAppState::isTransparent() {
    return false;
}
