#include "player.hpp"

void Player::move(Bloc* suivant, int move_x, int move_y) {
    Bloc* precedent;
    precedent = location;

    bool move_done = suivant->set_player(this);

    if (move_done) {
        x += move_x;
        y += move_y;
        precedent->erase_player();
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }
}
