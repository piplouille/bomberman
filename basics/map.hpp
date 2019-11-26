#ifndef mapHPP
#define mapHPP

#include <iostream>
#include "bloc.hpp"
#include "player.hpp"

class Map {
    private:
    int length;
    int width;
    Bloc** area;

    public:
    inline int get_length();
    inline int get_width();
    inline Bloc** get_area();
    inline int get_type_bloc(int x, int y);
    inline int* get_scores();
    inline void inc_scores(int player);
    inline Player* get_players();

    inline void print_map();
}

#endif