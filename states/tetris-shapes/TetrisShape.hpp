//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_TETRISSHAPE_HPP
#define TETRIS_TETRISSHAPE_HPP

#include <SFML/System/Vector2.hpp>
#include "ShapeType.hpp"

#include <memory>

class TetrisShape {
public:
    static std::unique_ptr<TetrisShape> createShape(ShapeType, bool** field, int fieldWidth, int fieldHeight);

public:
    TetrisShape(bool** field, int fieldWidth, int fieldHeight);

    virtual void rotate() = 0;
    void moveLeft();
    void moveRight();

private:
    void horizontalMove(char direction);

public:
    sf::Vector2i tilesPoss[4];

private:
    bool** field;
    int fieldWidth;
    int fieldHeight;
};


#endif //TETRIS_TETRISSHAPE_HPP
