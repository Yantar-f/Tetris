//
// Created by Yantar on 08/12/2023.
//

#include <random>
#include "IShape.hpp"
#include "../../CommonDefinitions.hpp"
#include "../../exceptions/NoSpawnSpaceException.hpp"

IShape::IShape(bool **field, int fieldWidth, int fieldHeight) : TetrisShape(field, fieldWidth, fieldHeight) {
    std::uniform_int_distribution<int> shapeSpawnRange {0, fieldWidth - 5};
    std::minstd_rand randEngine { static_cast<unsigned int>(TIME_POINT.time_since_epoch().count()) };
    int initialPos = shapeSpawnRange(randEngine);

    tilesPoss[0].x = initialPos;
    tilesPoss[0].y = 0;

    if (field[tilesPoss[0].x][tilesPoss[0].y]) throw NoSpawnSpaceException();

    tilesPoss[1].x = ++initialPos;
    tilesPoss[1].y = 0;

    if (field[tilesPoss[1].x][tilesPoss[1].y]) throw NoSpawnSpaceException();

    tilesPoss[2].x = ++initialPos;
    tilesPoss[2].y = 0;

    if (field[tilesPoss[2].x][tilesPoss[2].y]) throw NoSpawnSpaceException();

    tilesPoss[3].x = ++initialPos;
    tilesPoss[3].y = 0;

    if (field[tilesPoss[3].x][tilesPoss[3].y]) throw NoSpawnSpaceException();

    for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;
}

void IShape::rotate() {

}
