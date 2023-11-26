#include "PreloadAppState.h"

PreloadAppState::PreloadAppState(StateStack& stackStack, Context& context) : State(stackStack, context), color(sf::Color::White) {
    color.a = 0;

    preloadText.setString("Press any key to continue");
    preloadText.setFont(context.mainFont);
    preloadText.setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);
    preloadText.setFillColor(color);
    preloadText.setOutlineColor(sf::Color::Transparent);

    sf::FloatRect textRect = preloadText.getLocalBounds();

    preloadText.setOrigin(
        textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);

    preloadText.setPosition(
        context.renderWindow.getView().getSize().x/2.f,
        context.renderWindow.getView().getSize().y/2.f);
}

bool PreloadAppState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) requestStackPop();
    return false;
}

bool PreloadAppState::update(TimePointMs timePoint) {
    if (timePoint - prevTick < tickDuration) return false;
    prevTick = timePoint;

    if (preloadText.getFillColor().a == 0) {
        isIncrement = true;
    } else if (preloadText.getFillColor().a == 255) {
        isIncrement = false;
        prevTick += 500ms;
    }

    if (isIncrement) {
        tickDuration += 1ms;
        color.a += 5;
    } else {
        tickDuration -= 1ms;
        color.a -= 5;
    }

    preloadText.setFillColor(color);

    return false;
}

bool PreloadAppState::draw() {
    context.renderWindow.draw(preloadText);
    return false;
}

bool PreloadAppState::isTransparent() {
    return false;
}
