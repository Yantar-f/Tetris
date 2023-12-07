#include "MenuState.hpp"

MenuState::MenuState(
        StateStack& stateStack,
        Context& context,
        sf::Color selectionColor,
        sf::Color defaultColor,
        char selectedOption,
        char optionsCount) :
        State(stateStack, context),
        selectionColor(selectionColor),
        defaultColor(defaultColor),
        selectedOption(selectedOption),
        options(optionsCount) {}
