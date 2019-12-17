#include "map.hpp"

bool Map::move_up_player(Player* you) {
    // on récupère bloc suivant
    int x, y;
    x = (*you).get_x();
    y = (*you).get_y();

    Bloc* suivant;
    suivant = &(area[x][y+1]);
    // on demande a bloc de set
    // on teste si bloc suivant est libre
    bool available;
    available = (*suivant).set_player(you);

    if (available) {
        // on récupère bloc actuel
        Bloc *previous;
        previous = &(area[x][y]);
        // on supprime le joueur du bloc actuel
        (*previous).erase_player();
        // on return bool
        return true;
    }
    
    return false;
}

bool Map::move_right_player(Player* you) {
    // on récupère bloc suivant
    int x, y;
    x = (*you).get_x();
    y = (*you).get_y();

    Bloc* suivant;
    suivant = &(area[x+1][y]);
    // on demande a bloc de set
    // on teste si bloc suivant est libre
    bool available;
    available = (*suivant).set_player(you);

    if (available) {
        // on récupère bloc actuel
        Bloc *previous;
        previous = &(area[x][y]);
        // on supprime le joueur du bloc actuel
        (*previous).erase_player();
        // on return bool
        return true;
    }
    
    return false;
}

bool Map::move_down_player(Player* you) {
    // on récupère bloc suivant
    int x, y;
    x = (*you).get_x();
    y = (*you).get_y();

    Bloc* suivant;
    suivant = &(area[x][y-1]);
    // on demande a bloc de set
    // on teste si bloc suivant est libre
    bool available;
    available = (*suivant).set_player(you);

    if (available) {
        // on récupère bloc actuel
        Bloc *previous;
        previous = &(area[x][y]);
        // on supprime le joueur du bloc actuel
        (*previous).erase_player();
        // on return bool
        return true;
    }
    
    return false;
}

bool Map::move_left_player(Player* you) {
    // on récupère bloc suivant
    int x, y;
    x = (*you).get_x();
    y = (*you).get_y();

    Bloc* suivant;
    suivant = &(area[x-1][y]);
    // on demande a bloc de set
    // on teste si bloc suivant est libre
    bool available;
    available = (*suivant).set_player(you);

    if (available) {
        // on récupère bloc actuel
        Bloc *previous;
        previous = &(area[x][y]);
        // on supprime le joueur du bloc actuel
        (*previous).erase_player();
        // on return bool
        return true;
    }
    
    return false;
}