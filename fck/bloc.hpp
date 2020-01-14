#ifndef blocHPP
#define blocHPP

#include <memory>
#include <mutex>

#include "player.hpp"

/*
C'est ça que je veux ?

struct AnotherStruct : public std::mutex
{

    int a;
    int b;
};

And now I can do (for example):

AnotherStruct bar = { };

bar.lock ().
bar.a++;
bar.b++;
bar.unlock ();

*/

class Bloc : public std::mutex {
    /*
    Maintenant, je peux bloquer l'accès au bloc quand je veux
    */
    private:
    int type;
    int item;
    std::shared_ptr<Player> player; // nullptr si personne dessus ; shared_ptr permet aux autres blocs etc de lire
    bool available; // qq chose peut etre dessus TRUE si tu peux y aller

    public:
    Bloc() : type(0), item(0), player(nullptr), available(true) {

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

    inline std::shared_ptr<Player> get_player() {return player;} // on récupère s'il y a un joueur sur le bloc

    bool set_player(Player& n_player);
    void erase_player() {player = nullptr; available = true;}

    void print();
};

#endif