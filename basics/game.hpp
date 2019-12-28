#ifndef gameHPP
#define gameHPP

#include <chrono>
#include "player.hpp"
#include "map.hpp"

class Game {
    // Moteur du jeu
    private:
    Player** players; // La liste des joueurs
    Map* map; // La map du jeu
    std::chrono::time_point<std::chrono::system_clock> start; // temps du début de partie
    
    public:
    // Constructeur
    Game(Player**, Map*);

    Map* get_map() {return(map);}
    inline void print_map();
    inline void print_scores();
    inline void print_players();

    // grosse fonction du jeu

};

#endif