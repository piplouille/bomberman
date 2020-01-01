#include "map.hpp"

Map::Map() {
    width = 4; // premier indice longueur
    length = 4; // deuxième indice largeur
    area = new Bloc* [width]; // nb de lignes
    for (int i=0 ; i<width ; i++) {
        area[i] = new Bloc [length]; // nb de colonnes
    }
}

void Map::init_player(Player* player, int x, int y) {
    Bloc* suivant;
    suivant = &(area[x][y]);
    player->move(suivant, x, y);
}

void Map::move_player(Player* player, int move){
    // J'ai changé le type de move pcq si on fait plsrs joueurs, ce ne sera pas forcément la touche zqsd
    // dsl j'ai mis l'origine en haut à gauche, un affichage naturel se fait comme ça :(
    
    /*
    On regarde le bloc où le joueur veut aller
    On demande à joueur d'y aller
    */
   
    int x, y;
    x = player->get_x();
    y = player->get_y();

    int move_x = 0; // le changement de mouvements
    int move_y = 0;

    Bloc* suivant;

    switch (move) 
    {
        case 0:
            // le nouveau bloc vers le haut
            if (y == 0) {
                break;
            }
            suivant = &(area[x][y-1]);
            move_y--;
            break;
        case 1:
            // le nouveau bloc vers la droite
            if (x == width) {
                break;
            }
            suivant = &(area[x+1][y]);
            move_x++;
            break;
        case 2:
            // le nouveau bloc vers le bas
            std::cout << "on rentre" << std::endl;
            if (y == length) {
                break;
            }
            std::cout << "move_y va changer" << std::endl;
            suivant = &(area[x][y+1]);
            move_y++;
            break;
        case 3:
            // le nouveau bloc vers la gauche
            if (x == 0) {
                break;
            }
            suivant = &(area[x-1][y]);
            move_x--;
            break;
    }

    if (move_x != 0 || move_y != 0) {
        std::cout << "Il va bouger" << std::endl;
        player->move(suivant, move_x, move_y);
    }
}

void Map::print(Player* p) {
    for (int i=0 ; i<width ; i++) {
        for (int j=0 ; j<length; j++) {
            area[i][j].print();
        }
        std::cout << std::endl;
    }


    std::cout << "Coord du joueur 1 : (" << p->get_x() << "," << p->get_y() << ")" << std::endl;
}