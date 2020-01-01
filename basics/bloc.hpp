#ifndef blocHPP
#define blocHPP

#include "bomb.hpp"
#include "player.hpp"

class Bloc {
    private:
    int type;
    int item;
    Bomb* bombe; // NULL si aucune bombe dessus
    Player* player; // NULL si personne dessus
    bool available; // qq chose peut etre dessus TRUE si tu peux y aller

    public:
    Bloc() {
        type = 0; // bloc vide
        item =  0; // aucun item
        bombe = NULL; // aucune bombe
        player = NULL; // aucun joueur sur la case
        available = true; // la case est libre
    }

    Bloc (int n_type, int n_item, Bomb* n_bombe, Player* n_player, bool n_available) {
        type = n_type;
        item = n_item;
        bombe = n_bombe;
        player = n_player;
        available = n_available;
    }

    Bloc(const Bloc &bloc) {
        type = bloc.type;
        item = bloc.item;
        bombe = bloc.bombe;
        player = bloc.player;
        available = bloc.available;
    }

    inline int get_type() {return type;}
    inline int get_item() {return item;}
    inline void set_item(int n_item) {item = n_item;}
    inline Bomb* get_bombe() {return bombe;}
    inline void set_bombe(Bomb* n_bombe) {bombe = n_bombe;}
    inline void get_available() {return available;}

    inline Player* get_player() {return player;} // on récupère s'il y a un joueur sur le bloc
    bool set_player(Player* n_player);
    inline void erase_player() {player = NULL; available = true;}

    void print();
    void deep_copy(Bloc*);
};

#endif