#include "bomb.hpp"

Bomb::Bomb(Player& p) {
    // On récupère les infos de joueur pour créer la bombe
    range = p.get_bomb_range();
    //  life; // activation et durée de vie de la bomb
    owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
}