#ifndef mapHPP
#define maphPP

#include <iostream>
#include "bloc.hpp"
#include "player.hpp"

class Map {
    private:
    int length;
    int width;
    Bloc** area;
    int* scores;
    Player* players;

    public:
    inline int get_length();
    inline int get_width();
    inline Bloc** get_area();
    inline int get_type_bloc(int x, int y);
    inline int* get_scores();
    inline void inc_scores(int player);
    inline Player* get_players();

    inline void print_map();
    inline void print_scores();
    inline void print_players();
}

#endif