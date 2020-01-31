#include "map.hpp"

/*
Les constructeurs
*/

Map::Map(): Map(defaultWidth, defaultLength)
{} 

Map::Map(int aWidth, int aLength):
    width(aWidth), length(aLength),
    area(width, std::vector<Bloc>(length)) {

    for (int i=0 ; i<4 ; i++) {
        positions[i] = end();
    }
}

void Map::init_player(Player &player, int x, int y) {
    move_player(player, x, y);
}

/*
Déplacement d'un joueur
*/

void Map::move_player(Player &player, int x, int y) {
    // on veut que player aille en x, y

    // itérateur
    auto suivant = begin(x, y);

    // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
    suivant->lock();
    bool move_done = suivant->set_player(player);

    if (move_done) {
        // mise à joueur des coordonnées de player
        player.set_x(x);
        player.set_y(y);

        // Mise à jour du tableau positions
        if (positions[player.get_num_player()] != end()) {
            positions[player.get_num_player()]->erase_player();
        }
        positions[player.get_num_player()] = suivant;
    }
    else {
        // std::cout << "bitch try again" << std::endl;
    }
    suivant->unlock();
}

void Map::move_player(Player &player, int move){
    // On trouve où le joueur veut se déplacer en coordonnées

   
    int x, y;
    x = player.get_x();
    y = player.get_y();

    int move_x = 0; // le changement de mouvements
    int move_y = 0;

    switch (move) 
    {
        case 0:
            // le nouveau bloc vers le haut : ligne x - 1
            if (x == 0) {
                break;
            }
            move_x--;
            break;
        case 1:
            // le nouveau bloc vers la droite : colonne y + 1
            if (y == length - 1) {
                break;
            }
            move_y++;
            break;
        case 2:
            // le nouveau bloc vers le bas : ligne x + 1
            if (x == width - 1) {
                break;
            }
            move_x++;
            break;
        case 3:
            // le nouveau bloc vers la gauche : colonne y - 1
            if (y == 0) {
                break;
            }
            move_y--;
            break;
    }

    if (move_x != 0 || move_y != 0) {
        move_player(player, player.get_x() + move_x, player.get_y() + move_y);
    }
    else {
        std::cout << "Mouvement impossible" << std::endl;
    }
}

/*
Les bombes
*/

void Map::put_bomb(Player &p) {
    // On vérifie que joueur peut encore poser une bombe
    if (p.able_bomb()) {
        // On appelle un fonction qui init bombe de player
        Bomb bomb(p);

        // On pose la bombe sur le bloc si possible
        auto bloc = begin(p.get_x(), p.get_y());
        bloc->lock();
        bool move_done = bloc->set_bomb(bomb);

        if (move_done) {
            // Si ca marche, on doit stocker la bombe dans Map
            #pragma omp critical 
            bombs.push_back(std::make_shared<Bomb> (bomb));
        }

        else {
            // std::cout << "bitch try again" << std::endl;
        }
        bloc->unlock();
    }

}

void Map::update_bomb() {
    // On prend chaque bombe du vecteur (itérateur stp)
    std::vector<std::shared_ptr<Bomb>>::iterator it = bombs.begin();
    // Je diminue de 1 sa vie
    while (it < bombs.end()) {
        (*it)->decrease_life();
        if ((*it)->get_life() == 0) {
            std::cout << "boum bébi" << std::endl;
            // J'appelle bombe explose et touche les différents blocs : calculer ça au moment de poser ?
                // conséquences sur joueurs
            // Je remets à vide le bloc où bombe était
        }
        it++;
    }
}

/*
Fonctions de print
*/

void Map::print(Player &p) {
    std::cout << "Coord du joueur " << p.get_num_player() << " : (" << p.get_x() << "," << p.get_y() << ")" << std::endl;
}

void Map::print() {
    for (int i=0 ; i<width ; i++) {
        for (int j=0 ; j<length; j++) {
            area[i][j].print();
        }
        std::cout << std::endl;
    }
}

/*
Gestion des itérateurs
*/

auto Map::begin(int x) {
    return (area.begin() + x);
}

std::vector<Bloc>::iterator Map::begin(int x, int y) {
    return (area.begin() + x)->begin() + y;
}

auto Map::end(int x) {
    return (area.begin() + x)->end();
}
std::vector<Bloc>::iterator Map::end() {
    // Valeur par défaut si "nullptr"
    return (area.begin() + width)->end();
}

