#ifndef bombHPP
#define bombHPP

#include <chrono>
#include <memory>

#include "player.hpp"

class Bomb {
private:
    int x, y; // coordonnées de la bombe
    int range; // portée de la bombe
    // std::chrono::time_point<std::chrono::system_clock> start,life; // activation et durée de vie de la bomb
    int life; // à chaque action, on enlève un
    std::shared_ptr<Player> owner; // permet de savoir quel décompte de bombe modifier à l'explosion

public:
    public:
    Bomb(Player&);
    
    ~Bomb()
    {}

    int get_life() {return life;}
    void decrease_life() {life--;}

    void set_x(int x) {
        this->x = x;
    }

    void set_y(int y) {
        this->y = y;
    }

};

#endif