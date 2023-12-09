#ifndef TETRIS_ISHAPE_HPP
#define TETRIS_ISHAPE_HPP


#include "TetrisShape.hpp"

class IShape : public TetrisShape{
public:
    IShape(bool** field, int fieldWidth, int fieldHeight);

    void rotate() override;
};


#endif //TETRIS_ISHAPE_HPP
