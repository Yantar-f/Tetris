#ifndef TETRIS_CONTEXT_H
#define TETRIS_CONTEXT_H

#include "SFML/Graphics.hpp"

class Context {
public:
    Context(sf::VideoMode, const std::string& windowTitle, sf::Uint32 windowStyle, const char* resourcePath);

public:
    sf::RenderWindow renderWindow;
    std::string resourcePath;
};


#endif //TETRIS_CONTEXT_H
