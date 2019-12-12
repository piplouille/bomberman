#ifndef gameHPP
#define gameHPP

#include <chrono>
#include "player.hpp"
#include "map.hpp"

class Game {
    private:
    Player* players;
    Map* map;
    std::chrono::time_point <std::chrono::system_clock> start;

    public:
    inline void print_map();
    inline void print_scores();
    inline void print_players();

};

#endif