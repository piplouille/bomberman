#include "bloc.hpp"

bool Bloc::set_player(Player* n_player) {
    if (available) {
        // On pose le joueur sur une case
        player = n_player;
        available = false;
        return true;
    }
    return false;
}