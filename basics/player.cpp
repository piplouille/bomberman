#include "player.hpp"

void Player::move(Bloc &suivant, int move_x, int move_y) {
    // location peut être de type NULL => ne pas deep copy avant de vérifier
    Bloc* precedent;
    if (location != 0) {
        std::cout << "On a un ancien" << std::endl;
        // *precedent = Bloc(*location);
        precedent->deep_copy(&location); // segmentation fault
        std::cout << "deep copy done" << std::endl;
    }
    else {
        std::cout << "On n'a pas d'ancienne position" << std::endl;
        precedent = 0;
    }
    
    bool move_done = suivant.set_player(*this);

    std::cout << suivant.get_type() << std::endl;

    if (move_done) {
        std::cout << "Le mouvement a réussi" << std::endl;
        x += move_x;
        y += move_y;
        // int joueur = location->get_type();
        // Il faut dire au player sa référence de bloc débile
        // (*location).deep_copy(suivant); // on recréee deep_copy ?
        // location = suivant; // segmentation fault
        if (precedent != 0) {
            std::cout << "Effacement position précédente" << std::endl;
            (*precedent).erase_player(); // segmentation fault
        }
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }
}
