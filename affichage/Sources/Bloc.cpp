#include "Headers/Bloc.hpp"

bool Bloc::set_player(Player &n_player) {
    if (available()) {
        // On pose le joueur sur une case
        player = std::make_shared<Player> (n_player); // constructeur copie il panique
        return true;
    }
    return false;
}

void Bloc::print() {
    if (type == 0) {
        std::cout << "X";
    }

    else if (player == nullptr && bomb == nullptr) {
        std::cout << "~";
    }
    
    else if (bomb != nullptr) {
        std::cout << "#";
    }

    else if (player != nullptr) {
        std::cout << player->get_num_player();
    }
}

bool Bloc::set_bomb(std::shared_ptr<Bomb> n_bomb) {
    if (bomb_available()) {
        // bomb = std::make_shared<Bomb> (n_bomb);
        bomb = n_bomb;
        return true;
    }
    return false;
}
