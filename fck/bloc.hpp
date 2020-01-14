#ifndef blocHPP
#define blocHPP

#include <memory>
#include <mutex>

#include "player.hpp"
#include "bomb.hpp"

class Bloc : public std::mutex {
    /*
    Maintenant, je peux bloquer l'accès au bloc quand je veux
    */
    private:
    int type;
    int item;
    std::shared_ptr<Player> player; // nullptr si personne dessus ; shared_ptr permet aux autres blocs etc de lire
    std::shared_ptr<Bomb> bomb;
    bool available; // qq chose peut etre dessus, TRUE si tu peux y aller
    bool bomb_available;

    public:
    Bloc() : type(0), item(0), player(nullptr), available(true), bomb_available(true) {

    }

    Bloc (int n_type, int n_item, Player &n_player, bool n_available)
        : type(n_type), item(n_item), player(&n_player), available(n_available), bomb_available(true) {
        
    }

    Bloc(const Bloc &bloc) {
        type = bloc.type;
        item = bloc.item;
        player = bloc.player;
        available = bloc.available;
        bomb_available = bloc.bomb_available;
    }

    inline std::shared_ptr<Player> get_player() {return player;} // on récupère s'il y a un joueur sur le bloc

    bool set_player(Player& n_player);
    void erase_player() {player = nullptr; available = true;}

    bool set_bomb(Bomb&);

    void print();
};

#endif