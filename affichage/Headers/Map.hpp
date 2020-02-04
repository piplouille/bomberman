#ifndef mapHPP
#define mapHPP

#include <iostream>
#include <vector>
#include <memory>

#include "Headers/Bloc.hpp"
#include "Headers/Player.hpp"
#include "Headers/Bomb.hpp"

class Map {
    typedef std::vector<std::vector<Bloc> > area_type;

    private:
    static const int defaultLength = 16;
    static const int defaultWidth = 8;

    int length;
    int width;

    area_type area;

    std::vector<Bloc>::iterator positions[4]; // en 0, bloc où se trouve joueur 0

    void move_player(Player&, int, int); // déplace un joueur sur la case x y
    
    public:
    Map ();
    Map(int aWidth, int aLength);

    void init_player(Player&, int, int); // placer un joueur sur la map
    void move_player(Player&, int); // déplacer un joueur de manière relative
    
    void put_bomb(Player&);
    void update_bomb();

    void print(Player&);
    void print();

    int get_width() {
        return width;
    }

    int get_length() {
        return length;
    }

    area_type::iterator begin(int);
    std::vector<Bloc>::iterator begin(int, int);
    std::vector<Bloc>::iterator end(int);
    std::vector<Bloc>::iterator end();
};

#endif