#ifndef TETRIS_MAINMENUSTATE_H
#define TETRIS_MAINMENUSTATE_H


#include "State.h"

class MainMenuState : public State {
public:
    explicit MainMenuState(StateStack&, Context);
    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
};


#endif //TETRIS_MAINMENUSTATE_H
