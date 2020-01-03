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
    Bloc() : type(0), item(0), bombe(0), player(0), available(true) {

    }

    Bloc (int n_type, int n_item, Bomb &n_bombe, Player &n_player, bool n_available)
        : type(n_type), item(n_item), bombe(&n_bombe), player(&n_player), available(n_available) {
        
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
    inline void set_bombe(Bomb &n_bombe) {bombe = &n_bombe;}
    inline bool get_available() {return available;}

    inline Player* get_player() {return player;} // on récupère s'il y a un joueur sur le bloc
    bool set_player(Player& n_player);
    inline void erase_player() {player = 0; available = true;}

    void print();
    void deep_copy(Bloc&);
};

#endif