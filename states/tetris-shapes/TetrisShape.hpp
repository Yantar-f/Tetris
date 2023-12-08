//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_TETRISSHAPE_HPP
#define TETRIS_TETRISSHAPE_HPP


#include <SFML/System/Vector2.hpp>
#include "ShapeType.hpp"

class TetrisShape {
public:
    static TetrisShape createShape(ShapeType);

    sf::Vector2i tilesPoss[4];
};


#endif //TETRIS_TETRISSHAPE_HPP
