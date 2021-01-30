#pragma once
class Grid
{
    private:
    vector<Tank> tanks;
    vec2 gridSize;
    vector<Tile*> tiles;

    public:
    Grid(vec2 gridSize, vector<Tank> tanks);
    void createGrid();
    vec2 getGridSize() { return gridSize; };
    vector<Tile*> getAdjacentTiles(int index);
    vector<Tile*> getAllTiles() { return tiles; };
    Tile* getCurrTile(int index);
    int getTileIndex(vec2 pos);
    void updateTanks();
};



