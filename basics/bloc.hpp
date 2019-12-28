#ifndef mapHPP
#define mapHPP

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

    inline int get_type() {return type;}
    inline int get_item() {return item;}
    inline void set_item(int n_item) {item = n_item;}
    inline Bomb* get_bombe() {return bombe;}
    inline void set_bombe(Bomb* n_bombe) {bombe = n_bombe;}

    inline Player* get_player() {return player;} // on récupère s'il y a un joueur sur le bloc
    inline bool set_player(Player* n_player) {
        if (available) {
            // On pose le joueur sur une case
            player = n_player;
            available = false;
            // Modifier l'info de son emplacement dans player ?
            return true;
        }
        return false;
    }
    inline void erase_player();
    // on rechange le player et available

};

#endif