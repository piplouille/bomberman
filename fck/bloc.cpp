#include "bloc.hpp"

bool Bloc::set_player(Player &n_player) {    
    if (available) {
        // On pose le joueur sur une case
        player = &n_player;
        std::cout << "Je modifie le bloc" << std::endl;
        available = false;
        return true;
    }
    return false;
}

void Bloc::print() {
    // std::cout << type;
    std::cout << available;
}

void Bloc::deep_copy(Bloc& ancien) {
    std::cout << "j suis la deep copy" << std::endl;
    // item = ancien->item;
    // bombe = ancien->bombe;
    // player = ancien->player;
    // available = ancien->available;
}