#ifndef mapHPP
#define mapHPP

#include <iostream>
#include <vector>

#include "bloc.hpp"
#include "player.hpp"

// On fait hériter chaque type de map de la classe Map

class Map {
    private:
    int length;
    int width;
    Bloc** area;

    // IL FAUT QUE MAP DISE OU SE TROUVE UN JOUEUR AVEC SON ID FCK
    Bloc* positions[4]; // en 0, bloc où se trouve joueur 0

    public:
    Map ();

    // inline int get_length();
    // inline int get_width();
    // inline Bloc** get_area(); // a modifier avec des vecteurs
    // std::vector<Bloc> get_area();
    // inline int get_type_bloc(int x, int y);
    // inline int* get_scores();
    // inline void inc_scores(int player);

    void init_player(Player&, int, int); // placer un joueur sur la map
    void move_player(Player&, int move); // déplacer un joueur de manière relative
    void move_player(Player&, int, int); // déplace un joueur sur la case x y

    void print(Player&);
};



#endif