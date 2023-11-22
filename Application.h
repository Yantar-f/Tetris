#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#include <SFML\Graphics.hpp>
#include "StateStack.h"
#include "CommonDefinitions.h"

class Application {
public:
    Application();
    void run();

private:
    void registerStates();
    void initializeStates();
    void processEvents();
    void update();
    void render();

    sf::RenderWindow mainWindow;
    StateStack stateStack;
};


#endif //TETRIS_APPLICATION_H
