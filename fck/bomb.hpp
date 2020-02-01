#ifndef bombHPP
#define bombHPP

#include <chrono>
#include <memory>
#include <vector>

#include "player.hpp"

class Bloc;

class Bomb {
private:
    int x, y; // coordonnées de la bombe
    int range; // portée de la bombe
    // std::chrono::time_point<std::chrono::system_clock> start,life; // activation et durée de vie de la bomb
    int life; // à chaque action, on enlève un
    std::shared_ptr<Player> owner; // permet de savoir quel décompte de bombe modifier à l'explosion
    std::vector<std::shared_ptr<Bloc>> touched; // l'ensemble des blocs que la bombe va atteindre

public:
    public:

    Bomb() {
        x = 0;
        y = 0;
        range = 1;
        life = 1;
    }
    Bomb(Player& p) {
        if (p.able_bomb()) {
            // On récupère les infos de joueur pour créer la bombe
            x = p.get_x();
            y = p.get_y();
            range = p.get_bomb_range();
            owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
            life = p.get_bomb_life(); // à chaque tour ça décroit de 1

            p.decrase_bomb_quota();
        }
    }
    
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

#include "bloc.hpp"

/*
        // on va aller chercher les blocs qui correspondent au range touché

        touched.push_back(std::make_shared<Bloc> (map.begin(x, y)));
*/

#endif