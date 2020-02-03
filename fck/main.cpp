#include <stdlib.h>
#include <thread>
#include <mutex>
#include <unistd.h>

#include "player.hpp"
#include "map.hpp"

// std::mutex lock;

// on compile avec
// g++ main.cpp player.cpp bloc.cpp map.cpp bomb.hpp -o main.x -lpthread

void random_move(Map &map, Player &player) {
    int move;
    int i = 0;
    while (i<10) {
        move = rand() % 4;
        map.move_player(player, move);
        if (i%2 == 0) {
            map.put_bomb(player);
        }
        i++;
        // map.print ();
        std::cout << "~-~-~-Fin du tour-~-~-~" << std::endl;
        // std::cout << "~-~-~fin du tour de " << player.get_num_player() << "~-~-~" << std::endl;
    }
}

void check_bomb(Map &map) {
    // vérifie et met à jour les bombes sur Map
    int i = 0;
    while (i<20) {
        map.update_bomb(); // => crée soucis de seg fault : on ajoute bomb à bombs tout en les regardant
        sleep(0.1);
        i++;
    }
}

int main () {
    Player maxence, laetitia, gerard, patrick;
    maxence = Player(0);
    laetitia = Player(1);
    gerard = Player(2);
    patrick = Player(3);    

    Map map;
    map = Map();

    std::cout << "Placement de Maxence en (1,0)" << std::endl;
    map.init_player(maxence, 3, 3);
    map.print(maxence);

    // std::cout << "Placement de Laetitia en (3,3)" << std::endl;
    // map.init_player(laetitia, 3, 3);
    // map.print(laetitia);

    // std::cout << "Placement de Gerard en (3,6)" << std::endl;
    // map.init_player(gerard, 3, 6);
    // map.print(gerard);

    // std::cout << "Placement de Patrick en (2,7)" << std::endl;
    // map.init_player(patrick, 2, 7);
    // map.print(patrick);

    map.print();

    std::thread maxenceThread;
    // std::thread laetitiaThread;
    // std::thread gerardThread;
    // std::thread patrickThread;

    std::thread checkThread;
    checkThread = std::thread(check_bomb, std::ref(map));

    maxenceThread = std::thread(random_move, std::ref(map), std::ref(maxence));
    // laetitiaThread = std::thread(random_move, std::ref(map), std::ref(laetitia));
    // gerardThread = std::thread(random_move, std::ref(map), std::ref(gerard));
    // patrickThread = std::thread (random_move, std::ref(map), std::ref(patrick));

    maxenceThread.join();
    // laetitiaThread.join();
    // gerardThread.join();
    // patrickThread.join();
    checkThread.join();
    
    std::cout << "~-~-~fin du jeu~-~-~" << std::endl;
    map.print();

    return 0;
}