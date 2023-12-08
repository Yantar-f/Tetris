//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_ZSHAPE_HPP
#define TETRIS_ZSHAPE_HPP


#include "TetrisShape.hpp"

class ZShape : public TetrisShape {
public:
    ZShape(bool **field, int fieldWidth, int fieldHeight);

    void rotate() override;
};


#endif //TETRIS_ZSHAPE_HPP
