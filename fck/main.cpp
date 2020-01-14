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
    int i = 0;
    while (i<10) {
        move = rand() % 4;
        map.move_player(player, move);
        i++;
        #pragma omp critical
        map.print();
        // std::cout << "~-~-~fin du tour de " << player.get_num_player() << "~-~-~" << std::endl;
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
    map.init_player(maxence, 1, 0);
    map.print(maxence);

    std::cout << "Placement de Laetitia en (3,3)" << std::endl;
    map.init_player(laetitia, 3, 3);
    map.print(laetitia);

    std::cout << "Placement de Gerard en (3,6)" << std::endl;
    map.init_player(gerard, 3, 6);
    map.print(gerard);

    std::cout << "Placement de Patrick en (2,7)" << std::endl;
    map.init_player(patrick, 2, 7);
    map.print(patrick);

    map.print();

    std::thread laetitiaThread;
    std::thread maxenceThread;
    std::thread gerardThread;
    std::thread patrickThread;

    laetitiaThread = std::thread(random_move, std::ref(map), std::ref(laetitia));
    maxenceThread = std::thread(random_move, std::ref(map), std::ref(maxence));
    gerardThread = std::thread(random_move, std::ref(map), std::ref(gerard));
    patrickThread = std::thread (random_move, std::ref(map), std::ref(patrick));

    laetitiaThread.join();
    maxenceThread.join();
    gerardThread.join();
    patrickThread.join();
    
    std::cout << "~-~-~fin du jeu~-~-~" << std::endl;
    map.print();

    return 0;
}