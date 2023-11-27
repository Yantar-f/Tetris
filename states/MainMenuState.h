#ifndef TETRIS_MAINMENUSTATE_H
#define TETRIS_MAINMENUSTATE_H

#include "State.h"
#include "MenuState.h"

using namespace std::chrono_literals;

class MainMenuState : public MenuState {
public:
    MainMenuState(StateStack&, Context&);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    enum Options {
        Play,
        Exit,

        Count
    };
};


#endif //TETRIS_MAINMENUSTATE_H
