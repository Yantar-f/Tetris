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
    virtual ~TetrisShape() = default;
    virtual void rotate() = 0;
    void moveLeft();
    void moveRight();
    bool moveDown();

protected:
    TetrisShape(bool** field, int fieldWidth, int fieldHeight);

protected:
    enum class Rotation {
        Rot0,
        Rot90,
        Rot180,
        Rot270
    };

private:
    void horizontalMove(char direction);


public:
    sf::Vector2i tilesPoss[4];

protected:
    bool** field;
    int fieldWidth;
    int fieldHeight;
    Rotation currentRotationAngle = Rotation::Rot0;
};


#endif //TETRIS_TETRISSHAPE_HPP
