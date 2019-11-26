#ifndef gameHPP
#define gameHPP

#include "player.hpp"

class Game() {
    private:
    int* scores;
    Player* players;

    public:
    inline void print_map();
    inline void print_scores();
    inline void print_players();

}

#endif