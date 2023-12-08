//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_LSHAPE_HPP
#define TETRIS_LSHAPE_HPP


#include "TetrisShape.hpp"

class LShape : public TetrisShape {
public:
    LShape(bool** field, int fieldWidth, int fieldHeight);

    void rotate() override;
};


#endif //TETRIS_LSHAPE_HPP
