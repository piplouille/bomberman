#include "bloc.hpp"

bool Bloc::set_player(Player &n_player) {    
    if (available) {
        // On pose le joueur sur une case
        player = &n_player;
        available = false;
        return true;
    }
    return false;
}

void Bloc::print() {
    if (player == NULL) {
        std::cout << "~";
    }
    else {
        std::cout << player->get_num_player();
    }
}
