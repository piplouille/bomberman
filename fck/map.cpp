#include "map.hpp"

Map::Map() {
    width = 4; // premier indice hauteur nb de lignes
    length = 8; // deuxième indice largeur nb de colonnes
    
    area = new Bloc* [ width ];
    for (int i=0; i < width; i++)
        area[i] = new Bloc[ length ];

    for (int i=0 ; i<4 ; i++) {
        positions[i] = NULL;
    }
}

void Map::init_player(Player &player, int x, int y) {
    Bloc suivant;
    suivant = area[x][y];
    move_player(player, x, y);
}

void Map::move_player(Player &player, int x, int y) {
    // on veut que player aille en x, y

    // mutex ici svp pour bloquer lecture de area[x][y]

    // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
    bool move_done = area[x][y].set_player(player);

    if (move_done) {
        // mise à joueur des coordonnées de player
        player.set_x(x);
        player.set_y(y);
        if (positions[player.get_num_player()] != NULL) {
            positions[player.get_num_player()]->erase_player();
        }
        positions[player.get_num_player()] = &area[x][y];
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }

    // je libère la case area[x][y]
}

void Map::move_player(Player &player, int move){
    // J'ai changé le type de move pcq si on fait plsrs joueurs, ce ne sera pas forcément la touche zqsd
    // dsl j'ai mis l'origine en haut à gauche, un affichage naturel se fait comme ça :(
    
    /*
    On regarde le bloc où le joueur veut aller
    On demande à joueur d'y aller
    */
   
    int x, y;
    x = player.get_x();
    y = player.get_y();

    int move_x = 0; // le changement de mouvements
    int move_y = 0;

    Bloc suivant;

    switch (move) 
    {
        case 0:
            // le nouveau bloc vers le haut : ligne x - 1
            if (x == 0) {
                break;
            }
            suivant = area[x-1][y];
            move_x--;
            break;
        case 1:
            // le nouveau bloc vers la droite : colonne y + 1
            if (y == length - 1) {
                break;
            }
            suivant = area[x][y+1];
            move_y++;
            break;
        case 2:
            // le nouveau bloc vers le bas : ligne x + 1
            if (x == width - 1) {
                break;
            }
            suivant = area[x+1][y];
            move_x++;
            break;
        case 3:
            // le nouveau bloc vers la gauche : colonne y - 1
            if (y == 0) {
                break;
            }
            suivant = area[x][y-1];
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

void Map::print(Player &p) {
    // for (int i=0 ; i<width ; i++) {
    //     for (int j=0 ; j<length; j++) {
    //         area[i][j].print();
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << "Coord du joueur " << p.get_num_player() << " : (" << p.get_x() << "," << p.get_y() << ")" << std::endl;
}