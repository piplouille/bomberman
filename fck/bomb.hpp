#ifndef bombHPP
#define bombHPP

#include <chrono>

#include "player.hpp"

class Bomb {
private:
    int x, y; // coordonnées de la bombe
    int range; // portée de la bombe
    std::chrono::time_point<std::chrono::system_clock> start,life; // activation et durée de vie de la bomb
    Player* owner; // permet de savoir quel décompte de bombe modifier à l'explosion

public:
    public:

    Bomb(int amplitude, int row, int column, std::chrono::time_point<std::chrono::system_clock> elapsed_seconds):
        range(amplitude),x(row),y(column), life(elapsed_seconds)
        {}
    
    ~Bomb()
    {}

};

#endif