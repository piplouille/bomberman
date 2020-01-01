#include "player.hpp"

void Player::move(Bloc* suivant, int move_x, int move_y) {
    Bloc precedent;
    //precedent = Bloc(*location); // ce n'est pas une deep copy lol
    precedent = Bloc(location->get_type(), location->get_item(), location->get_bombe(), location->get_player(), location->get_available);


    //bool move_done = suivant->set_player(this);

    // if (move_done) {
    //     x += move_x;
    //     y += move_y;
    //     if (&precedent != NULL)
    //         precedent.erase_player();
    // }
    // else {
    //     std::cout << "bitch try again" << std::endl;
    // }
}
