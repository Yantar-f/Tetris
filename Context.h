#ifndef TETRIS_CONTEXT_H
#define TETRIS_CONTEXT_H

#include "SFML/Graphics.hpp"

class Context {
public:
    Context(sf::VideoMode, const sf::String& windowTitle, sf::Uint32 windowStyle);
    sf::RenderWindow renderWindow;
};


#endif //TETRIS_CONTEXT_H
