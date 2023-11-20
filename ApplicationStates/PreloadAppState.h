#ifndef TETRIS_PRELOADAPPSTATE_H
#define TETRIS_PRELOADAPPSTATE_H

#include "State.h"

class PreloadAppState : public State {
public:
    explicit PreloadAppState(StateStack&);
    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
};

#endif //TETRIS_PRELOADAPPSTATE_H
