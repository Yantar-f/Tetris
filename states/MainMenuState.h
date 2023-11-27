#ifndef TETRIS_MAINMENUSTATE_H
#define TETRIS_MAINMENUSTATE_H

#include "State.h"

using namespace std::chrono_literals;

class MainMenuState : public State {
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

private:
    std::array<sf::Text, Options::Count> options;
    sf::Color selectionColor;
    sf::Color defaultColor;
    TimePointMs previousTick { TIME_POINT };
    std::chrono::milliseconds tickDuration { 100ms };
    bool isUp { false };
    bool isDown { false };
    char selectedOption;
};


#endif //TETRIS_MAINMENUSTATE_H
