#ifndef TETRIS_MAINMENUSTATE_H
#define TETRIS_MAINMENUSTATE_H

#include "State.h"

class MainMenuState : public State {
public:
    MainMenuState(StateStack&, Context&);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    sf::Text playOptionText;
    sf::Text exitOptionText;
    sf::Color selectionColor;
    sf::Color defaultColor;
};


#endif //TETRIS_MAINMENUSTATE_H
