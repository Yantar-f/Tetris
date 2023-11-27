//
// Created by Yantar on 27/11/2023.
//

#ifndef TETRIS_MENUSTATE_H
#define TETRIS_MENUSTATE_H

#include "State.h"

using namespace std::chrono_literals;

class MenuState : public State {
protected:
    MenuState(StateStack&, Context&, sf::Color selectionColor, sf::Color defaultColor, char selectedOption, char optionsCount);

protected:
    std::vector<sf::Text> options;
    sf::Color selectionColor;
    sf::Color defaultColor;
    TimePointMs previousTick { TIME_POINT };
    std::chrono::milliseconds tickDuration { 100ms };
    bool isUp { false };
    bool isDown { false };
    char selectedOption;
};


#endif //TETRIS_MENUSTATE_H
