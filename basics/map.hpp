#ifndef mapHPP
#define mapHPP

#include <iostream>
#include "bloc.hpp"
#include "player.hpp"

class Bloc;
class Player;

// On fait hériter chaque type de map de la classe Map

class Map {
    private:
    int length;
    int width;
    Bloc** area;

    public:
    Map ();

    inline int get_length();
    inline int get_width();
    inline Bloc** get_area();
    inline int get_type_bloc(int x, int y);
    inline int* get_scores();
    inline void inc_scores(int player);

    inline Player* get_players(); // on récupère les joueurs

    void init_player(Player*, int, int); // placer un joueur sur la map
    void move_player(Player*, int move); // déplacer un joueur sur la map

    void print(Player*);
};



#endif