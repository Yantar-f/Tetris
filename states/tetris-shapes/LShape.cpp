#include <random>
#include "LShape.hpp"
#include "../../CommonDefinitions.hpp"
#include "../../exceptions/NoSpawnSpaceException.hpp"

LShape::LShape(bool **field, int fieldWidth, int fieldHeight) : TetrisShape(field, fieldWidth, fieldHeight) {
    std::uniform_int_distribution<int> shapeSpawnRange {0, fieldWidth - 4};
    std::minstd_rand randEngine { static_cast<unsigned int>(TIME_POINT.time_since_epoch().count()) };
    int initialPos = shapeSpawnRange(randEngine);

    tilesPoss[0].x = initialPos;
    tilesPoss[0].y = 1;

    if (field[tilesPoss[0].x][tilesPoss[0].y]) throw NoSpawnSpaceException();

    tilesPoss[1].x = ++initialPos;
    tilesPoss[1].y = 1;

    if (field[tilesPoss[1].x][tilesPoss[1].y]) throw NoSpawnSpaceException();

    tilesPoss[2].x = ++initialPos;
    tilesPoss[2].y = 1;

    if (field[tilesPoss[2].x][tilesPoss[2].y]) throw NoSpawnSpaceException();

    tilesPoss[3].x = initialPos;
    tilesPoss[3].y = 0;

    if (field[tilesPoss[3].x][tilesPoss[3].y]) throw NoSpawnSpaceException();

    for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;
}

void LShape::rotate() {
    switch (currentRotationAngle) {
        case Rotation::Rot0: {
            if (tilesPoss[1].y + 1 >= fieldHeight) return;
            if (field[tilesPoss[1].x][tilesPoss[1].y - 1]) return;
            if (field[tilesPoss[1].x][tilesPoss[1].y + 1]) return;
            if (field[tilesPoss[1].x + 1][tilesPoss[1].y + 1]) return;

            currentRotationAngle = Rotation::Rot90;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = false;

            tilesPoss[0].x = tilesPoss[1].x;
            tilesPoss[2].x = tilesPoss[1].x;
            tilesPoss[3].x = tilesPoss[1].x + 1;

            tilesPoss[0].y = tilesPoss[1].y - 1;
            tilesPoss[2].y = tilesPoss[1].y + 1;
            tilesPoss[3].y = tilesPoss[1].y + 1;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;

            break;
        }

        case Rotation::Rot90: {
            if (tilesPoss[1].x - 1 < 0) return;
            if (field[tilesPoss[1].x - 1][tilesPoss[1].y + 1]) return;
            if (field[tilesPoss[1].x - 1][tilesPoss[1].y]) return;
            if (field[tilesPoss[1].x + 1][tilesPoss[1].y]) return;

            currentRotationAngle = Rotation::Rot180;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = false;

            tilesPoss[0].x = tilesPoss[1].x + 1;
            tilesPoss[2].x = tilesPoss[1].x - 1;
            tilesPoss[3].x = tilesPoss[1].x - 1;

            tilesPoss[0].y = tilesPoss[1].y;
            tilesPoss[2].y = tilesPoss[1].y;
            tilesPoss[3].y = tilesPoss[1].y + 1;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;

            break;
        }

        case Rotation::Rot180: {
            if (tilesPoss[1].y - 1 < 0) return;
            if (field[tilesPoss[1].x][tilesPoss[1].y + 1]) return;
            if (field[tilesPoss[1].x][tilesPoss[1].y - 1]) return;
            if (field[tilesPoss[1].x - 1][tilesPoss[1].y - 1]) return;

            currentRotationAngle = Rotation::Rot270;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = false;

            tilesPoss[0].x = tilesPoss[1].x;
            tilesPoss[2].x = tilesPoss[1].x;
            tilesPoss[3].x = tilesPoss[1].x - 1;

            tilesPoss[0].y = tilesPoss[1].y + 1;
            tilesPoss[2].y = tilesPoss[1].y - 1;
            tilesPoss[3].y = tilesPoss[1].y - 1;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;

            break;
        }

        case Rotation::Rot270: {
            if (tilesPoss[1].x + 1 >= fieldWidth) return;
            if (field[tilesPoss[1].x - 1][tilesPoss[1].y]) return;
            if (field[tilesPoss[1].x + 1][tilesPoss[1].y]) return;
            if (field[tilesPoss[1].x + 1][tilesPoss[1].y - 1]) return;

            currentRotationAngle = Rotation::Rot0;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = false;

            tilesPoss[0].x = tilesPoss[1].x - 1;
            tilesPoss[2].x = tilesPoss[1].x + 1;
            tilesPoss[3].x = tilesPoss[1].x + 1;

            tilesPoss[0].y = tilesPoss[1].y;
            tilesPoss[2].y = tilesPoss[1].y;
            tilesPoss[3].y = tilesPoss[1].y - 1;

            for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;

            break;
        }
    }
}
