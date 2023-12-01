#ifndef TETRIS_MAINMENUSTATE_HPP
#define TETRIS_MAINMENUSTATE_HPP

#include "State.hpp"
#include "MenuState.hpp"

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


#endif //TETRIS_MAINMENUSTATE_HPP
