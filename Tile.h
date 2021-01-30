#pragma once
class Tile
{
    private:  
    vec2 pos;
    vector<Tank*> tanks;
    
    public:
    Tile(vec2 pos);
    vector<Tank*> getTanks() { return tanks; };
    vec2 getPos() { return pos; };
    void addTank(Tank* tank);
    void removeTank(Tank* tank);
};
