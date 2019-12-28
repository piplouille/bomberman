// #ifndef mapHPP
// #define mapHPP

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
    Map() {
        length = 4; // i premier indice
        width = 4; // j deuxième indice
        Bloc** area = new Bloc*[length];
        Bloc* area = new Bloc[width];
    }

    inline int get_length();
    inline int get_width();
    inline Bloc** get_area();
    inline int get_type_bloc(int x, int y);
    inline int* get_scores();
    inline void inc_scores(int player);

    inline Player* get_players(); // on récupère les joueurs

    bool move_up_player(Player*);
    bool move_right_player(Player*);
    bool move_down_player(Player*);
    bool move_left_player(Player*);

    inline void print_map(Player*);
};

inline void Map::print_map(Player* p) {
    std::cout << "Coord du joueur 1 : (" << *p.get_x() << "," << *p.get_y() << ")" << std::endl;
}


// #endif