#ifndef TETRIS_PRELOADAPPSTATE_HPP
#define TETRIS_PRELOADAPPSTATE_HPP

#include "State.hpp"

using namespace std::chrono_literals;

class PreloadAppState : public State {
public:
    PreloadAppState(StateStack &stackStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    sf::Text preloadText;
    sf::Color color;
    TimePointMs prevTick { TIME_POINT };
    std::chrono::milliseconds tickDuration { 0ms };
    bool isIncrement = true;
};

#endif //TETRIS_PRELOADAPPSTATE_HPP
