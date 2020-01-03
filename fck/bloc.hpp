#ifndef blocHPP
#define blocHPP

#include "player.hpp"

class Bloc {
    private:
    int type;
    int item;
    Player* player; // NULL si personne dessus
    bool available; // qq chose peut etre dessus TRUE si tu peux y aller

    public:
    Bloc() : type(0), item(0), player(0), available(true) {

    }

    Bloc (int n_type, int n_item, Player &n_player, bool n_available)
        : type(n_type), item(n_item), player(&n_player), available(n_available) {
        
    }

    Bloc(const Bloc &bloc) {
        type = bloc.type;
        item = bloc.item;
        player = bloc.player;
        available = bloc.available;
    }

    // inline int get_type() {return type;}
    // inline int get_item() {return item;}
    // inline void set_item(int n_item) {item = n_item;}
    // inline bool get_available() {return available;}

    // inline Player* get_player() {return player;} // on récupère s'il y a un joueur sur le bloc

    bool set_player(Player& n_player);
    void erase_player() {player = 0; available = true;}

    void print();
    void deep_copy(Bloc&);
};

#endif