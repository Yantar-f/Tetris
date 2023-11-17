#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#include <SFML\Graphics.hpp>
#include "ApplicationStates/StateStack.h"
#include "CommonTypedefs.h"

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();
    TimePointMs stampTimePoint();

    sf::RenderWindow mainWindow;
    StateStack stateStack;
};


#endif //TETRIS_APPLICATION_H
