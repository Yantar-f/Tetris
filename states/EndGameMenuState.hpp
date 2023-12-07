#ifndef TETRIS_ENDGAMEMENUSTATE_HPP
#define TETRIS_ENDGAMEMENUSTATE_HPP

#include "MenuState.hpp"

class EndGameMenuState : public MenuState {
public:
    EndGameMenuState(StateStack &stateStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    enum Options {
        Retry,
        MainMenu,
        Exit,

        Count
    };

private:
    sf::RectangleShape backgroundShape;
};


#endif //TETRIS_ENDGAMEMENUSTATE_HPP
