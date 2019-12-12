#ifndef mapHPP
#define mapHPP

#include "bomb.hpp"

class Bloc {
    private:
    int type;
    int item;
    Bomb* bombe; // NULL si aucune bombe dessus
    Player* player; // NULL si personne dessus

    public:
    inline int get_type();
    inline int get_item();
    inline int set_item();
    inline Bomb* get_bombe();
    inline void set_bombe(Bomb*);
    inline Player* get_player();
    inline void set_player(Player*);
}

#endif