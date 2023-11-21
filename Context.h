#ifndef TETRIS_CONTEXT_H
#define TETRIS_CONTEXT_H

#include "SFML/Graphics.hpp"

class Context {
public:
    explicit Context(sf::RenderWindow&);
    Context(Context&) = default;
    sf::RenderWindow& renderWindow;
};


#endif //TETRIS_CONTEXT_H
