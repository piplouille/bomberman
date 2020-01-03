#include "player.hpp"
#include "map.hpp"

int main () {
    Player maxence;
    maxence = Player(0);

    /*
    La création d'un joueur fonctionne ALLELUIA
    */

    Map map;
    map = Map();

    // Il faut mettre Maxence sur la map

    std::cout << "On demande à se déplacer" << std::endl;
    map.init_player(maxence, 0, 2);

    // map.print(maxence);

    // map.move_player(maxence, 2);

    // map.print(maxence);
    // on va mettre maxence sur bloc (0, 0)
    
    // il faut thread dédié en while(1)
    
    // map.init_player(&maxence, 0, 0);

    std::cout << "yoyoyo" << std::endl;

    return 0;
}