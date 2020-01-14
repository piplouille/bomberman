#ifndef bombHPP
#define bombHPP

#include <chrono>
#include <memory>

#include "player.hpp"

class Bomb {
private:
    int x, y; // coordonnées de la bombe
    int range; // portée de la bombe
    std::chrono::time_point<std::chrono::system_clock> start,life; // activation et durée de vie de la bomb
    std::shared_ptr<Player> owner; // permet de savoir quel décompte de bombe modifier à l'explosion

public:
    public:
    Bomb(Player&);
    
    ~Bomb()
    {}

};

#endif