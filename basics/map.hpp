// #ifndef mapHPP
// #define mapHPP

#include <iostream>
#include "bloc.hpp"
#include "player.hpp"

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
        area = new Bloc*[length];
        *area = new Bloc[width];
    }

    inline int get_length();
    inline int get_width();
    inline Bloc** get_area();
    inline int get_type_bloc(int x, int y);
    inline int* get_scores();
    inline void inc_scores(int player);

    inline Player* get_players(); // on récupère les joueurs

    inline bool move_player(Bloc*, Bloc*, Player*);
    /* on move le joueur d'un bloc 
    on teste available sur nouvelle case
    on met sur nouvelle case
    on supprime de l'ancienne case
    */
    // on déplace un joueur
    // on bloque tout déplacement et action pendant
    // on pose le joueur sur le bloc suivant
    // on supprime le joueur du bloc actuel
    // on retun un bool pour savoir si ça a marché

    inline void print_map();
};



// #endif