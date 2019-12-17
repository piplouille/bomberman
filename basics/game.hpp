#ifndef gameHPP
#define gameHPP

// #include <chrono>
#include "player.hpp"
#include "map.hpp"

class Game {
    // Moteur du jeu
    private:
    Player* players; // La liste des joueurs
    Map* map; // La map du jeu
    // std::chrono::time_point <std::chrono::system_clock> start; // Temps du début de la partie

    public:
    Game(){} // Par défaut
    // Constructeur

    inline void print_map();
    inline void print_scores();
    inline void print_players();

};

#endif