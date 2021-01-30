#include "precomp.h"

Tile::Tile(vec2 pos) {
    this->pos = pos;
}

void Tile::addTank(Tank* tank) {
    tanks.push_back(tank);
}

void Tile::removeTank(Tank* tank) {
    for (int i = 0; i < tanks.size(); i++)
    {
        if (tank == tanks[i])
        {
            tanks.erase(tanks.begin() + i);
        }
    }
}