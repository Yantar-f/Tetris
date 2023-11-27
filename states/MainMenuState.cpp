#include "MainMenuState.h"

MainMenuState::MainMenuState(StateStack& stateStack, Context& context) :
        State(stateStack, context),
        defaultColor(sf::Color::Cyan),
        selectionColor(sf::Color::White) {

    playOptionText.setString("Play");
    playOptionText.setFont(context.mainFont);
    playOptionText.setFillColor(selectionColor);
    playOptionText.setOutlineColor(sf::Color::Transparent);
    playOptionText.setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    exitOptionText.setString("Exit");
    exitOptionText.setFont(context.mainFont);
    exitOptionText.setFillColor(defaultColor);
    exitOptionText.setOutlineColor(sf::Color::Transparent);
    exitOptionText.setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    sf::FloatRect textRect = playOptionText.getLocalBounds();

    playOptionText.setOrigin(
            textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);

    playOptionText.setPosition(
            context.renderWindow.getView().getSize().x/2.f,
            context.renderWindow.getView().getSize().y/2.f - textRect.height);

    textRect = exitOptionText.getLocalBounds();

    exitOptionText.setOrigin(
            textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);

    exitOptionText.setPosition(
            context.renderWindow.getView().getSize().x/2.f,
            context.renderWindow.getView().getSize().y/2.f + textRect.height);
}

bool MainMenuState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {

    } else if (event.type == sf::Event::KeyReleased) {

    }

    return true;
}

bool MainMenuState::update(TimePointMs) {
    return true;
}

bool MainMenuState::draw() {
    context.renderWindow.draw(playOptionText);
    context.renderWindow.draw(exitOptionText);
    return false;
}

bool MainMenuState::isTransparent() {
    return false;
}
