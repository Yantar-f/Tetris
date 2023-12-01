#ifndef TETRIS_GAMEPAUSESTATE_HPP
#define TETRIS_GAMEPAUSESTATE_HPP

#include "MenuState.hpp"

class GamePauseState : public MenuState {
public:
    GamePauseState(StateStack &stateStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    enum Options {
        Continue,
        MainMenu,
        Exit,

        Count
    };
};


#endif //TETRIS_GAMEPAUSESTATE_HPP
