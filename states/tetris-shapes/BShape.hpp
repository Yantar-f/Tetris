//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_BSHAPE_HPP
#define TETRIS_BSHAPE_HPP


#include "TetrisShape.hpp"

class BShape : public TetrisShape{
public:
    BShape(bool** field, int fieldWidth, int fieldHeight);

    void rotate() override;
};


#endif //TETRIS_BSHAPE_HPP
