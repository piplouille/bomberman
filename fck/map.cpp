#include "map.hpp"

Map::Map() {
    width = 4; // premier indice longueur
    length = 4; // deuxième indice largeur
    
    area = new Bloc* [ width ];
    for (int i=0; i < width; i++)
        area[i] = new Bloc[ length ];

    for (int i=0 ; i<4 ; i++) {
        positions[i] = NULL;
    }
}

void Map::init_player(Player &player, int x, int y) {
    Bloc suivant;
    std::cout << "je vais consulter area" << std::endl;
    suivant = area[x][y];
    std::cout << "On commence la mise en place" << std::endl;
    move_player(player, x, y); // dans map
}

void Map::move_player(Player &player, int x, int y) {
    // on veut que player aille en x, y
    Bloc suivant;
    suivant = area[x][y];

    std::cout << "On demande à déplacer le joueur" << std::endl;
    // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
    bool move_done = suivant.set_player(player);

    if (move_done) {
        std::cout << "Le mouvement a réussi" << std::endl;
        // mise à joueur des coordonnées de player
        player.set_x(x);
        player.set_y(y);
        if (positions[player.get_num_player()] != NULL) {
            std::cout << "Effacement position précédente" << std::endl;
            positions[player.get_num_player()]->erase_player(); // segmentation fault
        }
        positions[player.get_num_player()] = &suivant;
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }
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
            // le nouveau bloc vers le haut
            if (y == 0) {
                break;
            }
            suivant = *area[x + length * (y-1)];
            move_y--;
            break;
        case 1:
            // le nouveau bloc vers la droite
            if (x == width) {
                break;
            }
            suivant = *area[x+1 + length * y];
            move_x++;
            break;
        case 2:
            // le nouveau bloc vers le bas
            std::cout << "on rentre" << std::endl;
            if (y == length) {
                break;
            }
            std::cout << "move_y va changer" << std::endl;
            suivant = *area[x + length * (y+1)];
            move_y++;
            break;
        case 3:
            // le nouveau bloc vers la gauche
            if (x == 0) {
                break;
            }
            suivant = *area[x-1 + length * y];
            move_x--;
            break;
    }

    if (move_x != 0 || move_y != 0) {
        std::cout << "Il va essayer de bouger" << std::endl;
        // player.move(suivant, move_x, move_y);
        move_player(player, player.get_x() + move_x, player.get_y() + move_y);
    }
}

void Map::print(Player &p) {
    for (int i=0 ; i<width ; i++) {
        for (int j=0 ; j<length; j++) {
            area[i][j].print();
        }
        std::cout << std::endl;
    }


    std::cout << "Coord du joueur 1 : (" << p.get_x() << "," << p.get_y() << ")" << std::endl;
}