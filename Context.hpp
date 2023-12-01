#ifndef TETRIS_CONTEXT_HPP
#define TETRIS_CONTEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Context {
public:
    Context(sf::VideoMode, const std::string& windowTitle, sf::Uint32 windowStyle, const char* resourcePath);

public:
    sf::RenderWindow renderWindow;
    std::string resourcePath;
    sf::Font mainFont;
};


#endif //TETRIS_CONTEXT_HPP
