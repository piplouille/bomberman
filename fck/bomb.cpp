#include "bomb.hpp"

Bomb::Bomb(Player& p) {
    // On récupère les infos de joueur pour créer la bombe
    x = p.get_x();
    y = p.get_y();
    range = p.get_bomb_range();
    //  life; // activation et durée de vie de la bomb
    owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
    life = p.get_bomb_life();
}