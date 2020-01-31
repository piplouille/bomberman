#include "bomb.hpp"

Bomb::Bomb(Player& p) {
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