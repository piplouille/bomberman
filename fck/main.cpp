#include <stdlib.h>
#include <thread>
#include <mutex>

#include "player.hpp"
#include "map.hpp"

std::mutex lock;

// on compile avec
// g++ main.cpp player.cpp bloc.cpp map.cpp -o main.x -lpthread

void random_laetitia(Map &map, Player &laetitia) {
    int move;
    // move = rand() % 4;
    move = 2; // le mvt 2 fait seg fault
    lock.lock();
    map.move_player(laetitia, move);
    map.print(laetitia);
    lock.unlock();
}

void random_maxence(Map &map, Player &maxence) {
    int move;
    move = rand() % 4;
    lock.lock();
    map.move_player(maxence, move);
    map.print(maxence);
    lock.unlock();
}

int main () {
    Player maxence, laetitia;
    maxence = Player(0);
    laetitia = Player(1);

    Map map;
    map = Map();

    map.print(maxence);

    std::cout << "Placement de Maxence en (0,2)" << std::endl;
    map.init_player(maxence, 0, 2);
    map.print(maxence);

    std::cout << "Placement de Laetitia en (3,3)" << std::endl;
    map.init_player(laetitia, 3, 3);
    map.print(laetitia);

    // random_laetitia(map, laetitia);
    int i = 0;
    while (i<5) {
        std::thread laetitiaThread(random_laetitia, std::ref(map), std::ref(laetitia));
        // std::thread maxenceThread(random_maxence, std::ref(map), std::ref(maxence));
        laetitiaThread.join();
        // maxenceThread.join();
        i++;
    }

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