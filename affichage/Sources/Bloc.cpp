#include "Headers/Bloc.hpp"

bool Bloc::set_player(Player &n_player) {
    if (available()) {
        // On pose le joueur sur une case
        player = std::make_shared<Player> (n_player);
        return true;
    }
    return false;
}

/**
 * @breif : Fonction d'affichage dans le terminal de la carte ; X : mur ; 0 : mur cassable ; ~ : case vide ; # : bombe ; int : joueur
 * @param : void
 * @return : void
 */
void Bloc::print() {
    if (type == 0) {
        std::cout << "X"; //mur
    }
    else if (type == 2) {
        std::cout << "O";//mur cassable
    }

    else if (player == nullptr && bomb == nullptr) {
        std::cout << "~"; //vide
    }
    
    else if (bomb != nullptr) {
        std::cout << "#"; //bombe
    }

    else if (player != nullptr) {
        std::cout << player->get_num_player(); //joueur
    }
}

bool Bloc::set_bomb(Bomb* n_bomb) {
    if (bomb_available()) {
        // bomb = std::make_shared<Bomb> (n_bomb);
        bomb = n_bomb;
        return true;
    }
    return false;
}
