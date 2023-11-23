#ifndef TETRIS_PRELOADAPPSTATE_H
#define TETRIS_PRELOADAPPSTATE_H

#include "State.h"

using namespace std::chrono_literals;

class PreloadAppState : public State {
public:
    PreloadAppState(StateStack &stackStack, Context context);
    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    sf::Text preloadText;
    sf::Font font;
    sf::Color color;
    TimePointMs prevTick { TIME_POINT };
    std::chrono::milliseconds tickDuration { 0ms };
    bool isIncrement = true;
};

#endif //TETRIS_PRELOADAPPSTATE_H
