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

    public:
    Bloc() : type(0), item(0), player(nullptr), bomb(nullptr) {

    }

    Bloc (int n_type, int n_item, Player &n_player, Bomb &n_bomb)
        : type(n_type), item(n_item), player(&n_player), bomb(&n_bomb) {
    }

    Bloc(const Bloc &bloc) {
        type = bloc.type;
        item = bloc.item;
        player = bloc.player;
        bomb = bloc.bomb;
    }

    inline std::shared_ptr<Player> get_player() {return player;} // on récupère s'il y a un joueur sur le bloc

    bool available() {
        return ((player == nullptr) && bomb == nullptr);
    }

    bool bomb_available() {
        return (bomb == nullptr);
    }

    bool set_player(Player& n_player);
    void erase_player() {player = nullptr;}

    bool set_bomb(Bomb&);

    void print();
};

#endif