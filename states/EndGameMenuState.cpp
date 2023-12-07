#include "EndGameMenuState.hpp"

EndGameMenuState::EndGameMenuState(StateStack &stateStack, Context &context) :
    MenuState(stateStack, context, sf::Color::Cyan, sf::Color::White, Retry, Count) {

    options[Retry].setString("Retry");
    options[Retry].setFont(context.mainFont);
    options[Retry].setFillColor(selectionColor);
    options[Retry].setOutlineColor(sf::Color::Transparent);
    options[Retry].setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    options[MainMenu].setString("Main menu");
    options[MainMenu].setFont(context.mainFont);
    options[MainMenu].setFillColor(defaultColor);
    options[MainMenu].setOutlineColor(sf::Color::Transparent);
    options[MainMenu].setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    options[Exit].setString("Exit");
    options[Exit].setFont(context.mainFont);
    options[Exit].setFillColor(defaultColor);
    options[Exit].setOutlineColor(sf::Color::Transparent);
    options[Exit].setCharacterSize(static_cast<unsigned int>(context.renderWindow.getView().getSize().y)/30);

    sf::FloatRect textRect = options[Retry].getLocalBounds();

    options[Retry].setOrigin(
        textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);

    textRect = options[MainMenu].getLocalBounds();

    options[MainMenu].setOrigin(
        textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);

    textRect = options[Exit].getLocalBounds();

    options[Exit].setOrigin(
        textRect.left + textRect.width/2.0f,
        textRect.top  + textRect.height/2.0f);

    options[Retry].setPosition(
        context.renderWindow.getView().getSize().x/2.f,
        context.renderWindow.getView().getSize().y/2.f - 2 * textRect.height);

    options[MainMenu].setPosition(
        context.renderWindow.getView().getSize().x/2.f,
        context.renderWindow.getView().getSize().y/2.f);

    options[Exit].setPosition(
        context.renderWindow.getView().getSize().x/2.f,
        context.renderWindow.getView().getSize().y/2.f + 2 * textRect.height);

    sf::Color backgroundColor = sf::Color::Black;
    backgroundColor.a = 120;

    backgroundShape.setSize(sf::Vector2f (context.renderWindow.getSize()));
    backgroundShape.setFillColor(backgroundColor);
}

bool EndGameMenuState::handleEvent(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed: {
            switch (event.key.code) {
                case sf::Keyboard::Enter: {
                    switch (selectedOption) {
                        case Retry: {
                            stateStack.clearStates();
                            stateStack.pushState(StateName::Game);
                            break;
                        }

                        case MainMenu: {
                            stateStack.clearStates();
                            stateStack.pushState(StateName::MainMenu);
                            break;
                        }

                        case Exit: {
                            stateStack.clearStates();
                            break;
                        }

                        default:;
                    }

                    break;
                }

                case sf::Keyboard::Escape: {
                    stateStack.clearStates();
                    stateStack.pushState(StateName::MainMenu);
                    break;
                }

                case sf::Keyboard::Up: {
                    isUp = true;
                    break;
                }

                case sf::Keyboard::Down: {
                    isDown = true;
                    break;
                }

                default:;
            }

            break;
        }

        case sf::Event::KeyReleased: {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
                previousTick -= tickDuration;
            }

            break;
        }

        default:;
    }

    return false;
}

bool EndGameMenuState::update(TimePointMs timePoint) {
    if (isUp) {
        isUp = false;

        if (timePoint - previousTick < tickDuration) return false;
        previousTick = TIME_POINT;

        options[selectedOption].setFillColor(defaultColor);

        if (selectedOption == 0) {
            selectedOption = Count - 1;
        } else {
            --selectedOption;
        }

        options[selectedOption].setFillColor(selectionColor);
    }

    if (isDown) {
        isDown = false;

        if (timePoint - previousTick < tickDuration) return false;
        previousTick = TIME_POINT;

        options[selectedOption].setFillColor(defaultColor);

        if (selectedOption == options.size() - 1) {
            selectedOption = 0;
        } else {
            ++selectedOption;
        }

        options[selectedOption].setFillColor(selectionColor);
    }


    return false;
}

bool EndGameMenuState::draw() {
    context.renderWindow.draw(backgroundShape);

    for (auto& option : options) {
        context.renderWindow.draw(option);
    }

    return true;
}

bool EndGameMenuState::isTransparent() {
    return true;
}
