#include "map.hpp"

void Map::move_player(Player* player, int move){
    // J'ai changé le type de move pcq si on fait plsrs joueurs, ce ne sera pas forcément la touche zqsd
    
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
        case '0':
            // le nouveau bloc vers le haut
            suivant = &(area[x][y+1]);
            move_y++;
            break;
        case '1':
            // le nouveau bloc vers la droite
            suivant = &(area[x+1][y]);
            move_x++;
            break;
        case '2':
            // le nouveau bloc vers le bas
            suivant = &(area[x][y-1]);
            move_y--;
            break;
        case '3':
            // le nouveau bloc vers la gauche
            suivant = &(area[x-1][y]);
            move_x--;
            break;
    }

    player->move(suivant, move_x, move_y);
}
