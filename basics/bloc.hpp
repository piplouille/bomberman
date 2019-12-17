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
    inline int get_type();
    inline int get_item();
    inline int set_item();
    inline Bomb* get_bombe();
    inline void set_bombe(Bomb*);

    inline Player* get_player(); // on récupère s'il y a un joueur sur le bloc
    inline bool set_player(Player*); 
    /* on pose le joueur sur une case 
    On vérifie si available == true
    on modifie available et player ensuite
    */
   inline void erase_player();
   // on rechange le player et available

};

#endif