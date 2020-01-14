#include "bloc.hpp"

bool Bloc::set_player(Player &n_player) {
    // std::cout << available << std::endl;
    if (available) {
        std::cout << "on peut déplacer joueur" << std::endl;
        // On pose le joueur sur une case
        player = std::make_shared<Player> (n_player);
        std::cout << player << std::endl;
        available = false;
        return true;
    }
    return false;
}

void Bloc::print() {
    if (player == nullptr) {
        std::cout << "~";
    }
    else {
        std::cout << player->get_num_player();
    }
}
