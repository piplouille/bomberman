#include <stdlib.h>
#include <thread>
#include <mutex>

#include "player.hpp"
#include "map.hpp"

// std::mutex lock;

// on compile avec
// g++ main.cpp player.cpp bloc.cpp map.cpp -o main.x -lpthread

void random_move(Map &map, Player &player) {
    int move;
    move = rand() % 4;
    // lock.lock();
    // map.move_player(player, move);
    map.move_player(player, 0 , 0);
    map.print(player);
    // lock.unlock();
}

int main () {
    Player maxence, laetitia, gerard, patrick;
    maxence = Player(0);
    laetitia = Player(1);
    gerard = Player(2);
    patrick = Player(3);

    Map map;
    map = Map();

    map.print(maxence);

    std::cout << "Placement de Maxence en (1,0)" << std::endl;
    map.init_player(maxence, 1, 0);
    map.print(maxence);

    std::cout << "Placement de Laetitia en (3,3)" << std::endl;
    map.init_player(laetitia, 0, 1);
    map.print(laetitia);

    std::cout << "Placement de Gerard en (6,3)" << std::endl;
    map.init_player(gerard, 2, 1);
    map.print(gerard);

    std::cout << "Placement de Patrick en (7,2)" << std::endl;
    map.init_player(patrick, 1, 2);
    map.print(patrick);

    map.print();

    std::thread laetitiaThread;
    std::thread maxenceThread;
    std::thread gerardThread;
    std::thread patrickThread;

    int i = 0;
    while (i<3) {
        // sémaphore
        laetitiaThread = std::thread(random_move, std::ref(map), std::ref(laetitia));
        std::thread maxenceThread(random_move, std::ref(map), std::ref(maxence));
        std::thread gerardThread(random_move, std::ref(map), std::ref(gerard));
        std::thread patrickThread(random_move, std::ref(map), std::ref(patrick));
        laetitiaThread.join();
        maxenceThread.join();
        gerardThread.join();
        patrickThread.join();
        std::cout << "~-~-~fin du tour~-~-~" << std::endl;
        i++;
    }

    map.print();

    // std::cout << "Déplacement de Maxence vers la gauche" << std::endl;
    // map.move_player(maxence, 3);
    // map.print(maxence);

    // std::cout << "Déplacement de Maxence vers le bas" << std::endl;
    // map.move_player(maxence, 2);
    // map.print(maxence);

    // std::cout << "Déplacement de Maxence vers le haut" << std::endl;
    // map.move_player(maxence, 0);
    // map.print(maxence);

    // std::cout << "Déplacement de Maxence vers la droite" << std::endl;
    // map.move_player(maxence, 1);
    // map.print(maxence);

    // std::cout << "Ajout d'un joueur" << std::endl;
    // Player laetitia;
    // laetitia = Player(1);


    // std::cout << "Déplacement de Laetitia vers la gauche" << std::endl;
    // map.move_player(laetitia, 0);
    // map.print(laetitia); 

    return 0;
}