#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#include <SFML\Graphics.hpp>
#include "StateStack.h"
#include "CommonDefinitions.h"

class Application {
public:
    Application();
    Application(sf::VideoMode, const std::string& windowTitle, unsigned int windowStyle, const char* resourcePath);
    void run();

private:
    void registerStates();
    void initializeStates();
    void processEvents();
    void update();
    void render();

    StateStack stateStack;
    Context context;
};


#endif //TETRIS_APPLICATION_H
