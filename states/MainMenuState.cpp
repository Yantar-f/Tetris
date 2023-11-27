#include "MainMenuState.h"

MainMenuState::MainMenuState(StateStack& stateStack, Context& context) :
        State(stateStack, context),
        defaultColor(sf::Color::White),
        selectionColor(sf::Color::Cyan),
        selectedOption(Play) {

    options[Play].setString("Play");
    options[Play].setFont(context.mainFont);
    options[Play].setFillColor(selectionColor);
    options[Play].setOutlineColor(sf::Color::Transparent);
    options[Play].setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    options[Exit].setString("Exit");
    options[Exit].setFont(context.mainFont);
    options[Exit].setFillColor(defaultColor);
    options[Exit].setOutlineColor(sf::Color::Transparent);
    options[Exit].setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    sf::FloatRect textRect = options[Play].getLocalBounds();

    options[Play].setOrigin(
            textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);

    options[Play].setPosition(
            context.renderWindow.getView().getSize().x/2.f,
            context.renderWindow.getView().getSize().y/2.f - textRect.height);

    textRect = options[Exit].getLocalBounds();

    options[Exit].setOrigin(
            textRect.left + textRect.width/2.0f,
            textRect.top  + textRect.height/2.0f);

    options[Exit].setPosition(
            context.renderWindow.getView().getSize().x/2.f,
            context.renderWindow.getView().getSize().y/2.f + textRect.height);
}

bool MainMenuState::handleEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed: {
            switch (event.key.code) {
                case sf::Keyboard::Enter: {
                    switch (selectedOption) {
                        case Play: {
                            stateStack.popState();
                            stateStack.pushState(StateName::Game);
                        }break;

                        case Exit: {
                            stateStack.clearStates();
                        }break;

                        default:;
                    }
                }break;

                case sf::Keyboard::Up: {
                    isUp = true;
                }break;

                case sf::Keyboard::Down: {
                    isDown = true;
                }break;

                default:;
            }
        }break;

        case sf::Event::KeyReleased: {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
                previousTick -= tickDuration;
            }
        }break;

        default:;
    }

    return true;
}

bool MainMenuState::update(TimePointMs timePoint) {
    if (isUp) {
        isUp = false;

        if (timePoint - previousTick < tickDuration) return false;

        options[selectedOption].setFillColor(defaultColor);

        if (selectedOption == Count - 1) {
            selectedOption = 0;
        } else {
            ++selectedOption;
        }

        options[selectedOption].setFillColor(selectionColor);
    }

    if (isDown) {
        isDown = false;

        if (timePoint - previousTick < tickDuration) return false;

        options[selectedOption].setFillColor(defaultColor);

        if (selectedOption == 0) {
            selectedOption = Count - 1;
        } else {
            --selectedOption;
        }

        options[selectedOption].setFillColor(selectionColor);
    }


    return false;
}

bool MainMenuState::draw() {
    for (auto& option : options) {
        context.renderWindow.draw(option);
    }

    return false;
}

bool MainMenuState::isTransparent() {
    return false;
}
