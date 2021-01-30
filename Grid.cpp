#include "precomp.h"

Grid::Grid(vec2 gridSize, vector<Tank> tanks)
{
    this->tanks = tanks;
    this->gridSize = gridSize;
    createGrid();
}

void Grid::createGrid() {

    for (int i = 0; i < gridSize.y; i++)
    {
        for (int j = 0; j < gridSize.x; j++)
        {
            Tile* tile = new Tile(vec2(j,i));
            tiles.push_back(tile);
        }
    }
}

vector<Tile*> Grid::getAdjacentTiles(int index) {

    vector<Tile*> adjTiles;
    adjTiles.reserve(9);
    Tile* currTile = getCurrTile(index);
    
    int currPosX = floor(currTile->getPos().x);
    int currPosY = floor(currTile->getPos().y);

    int posX;
    int posY;
    int diffX;
    int diffY;

    for (Tile* tile : tiles)
    {
        posX = tile->getPos().x;
        posY = tile->getPos().y;
      
        diffX = currPosX - posX;
        diffY = currPosY - posY;

        if ((diffX == 1 || diffX == -1 || diffX == 0) && (diffY == 1 || diffY == -1 || diffY == 0))
        {
            adjTiles.push_back(tile);
        }
    }

    return adjTiles;
}

Tile* Grid::getCurrTile(int index) {

    vec2 pos = getAllTiles()[index]->getPos();

    for (Tile* tile : tiles)
    {
        if (pos.x == tile->getPos().x && pos.y == tile->getPos().y)
        {
            return tile;
        }
    }

    return NULL;
}

int Grid::getTileIndex(vec2 pos) {
    int indexX;
    int indexY;
    int index;

    if (pos.x > SCRWIDTH)
    {
        indexX = (ROWS - 1);
    }
    else
    {
        indexX = floor(pos.x / (SCRWIDTH / gridSize.x));
    }

    if (pos.y > SCRHEIGHT)
    {
        indexY = (COLS - 1);
    }
    else
    {
        indexY = floor(pos.y / (SCRWIDTH / gridSize.x));
    }
    index = ((ROWS * indexY) + indexX);
    return index;
}

void Grid::updateTanks() {

    float tileX = SCRWIDTH / gridSize.x;
    float tileY = SCRHEIGHT / gridSize.y;

    int index;
    int indexX;
    int indexY;

    for (int i = 0; i < tiles.size(); i++)
    {
        for (Tank* tank : tiles[i]->getTanks()) {
            indexX = (tank->get_position().x / tileX);
            indexY = (tank->get_position().y / tileY);

            if (tank->get_position().x > SCRWIDTH) {
                indexX = (ROWS - 1);
            }

            if (tank->get_position().y > SCRHEIGHT) {
                indexY = (COLS - 1);
            }

            if (tiles[i]->getPos().x != indexX || tiles[i]->getPos().y != indexY) {
                index = ((ROWS * indexY) + indexX);

                tank->setCurrTileIn(index);

                tiles[index]->addTank(tank);
                tiles[i]->removeTank(tank);
            }
        }
    }
}



