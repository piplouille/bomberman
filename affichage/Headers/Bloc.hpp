#ifndef blocHPP
#define blocHPP

#include <memory>
#include <mutex>

#include "Headers/Player.hpp"
#include "Headers/Bomb.hpp"

class Bloc : public std::mutex {
    /*
    Maintenant, je peux bloquer l'accès au bloc quand je veux
    */
    private:
    int type; // 0 pour mur, 1 pour herbe
    int item;
    std::shared_ptr<Player> player; // nullptr si personne dessus ; shared_ptr permet aux autres blocs etc de lire
    std::shared_ptr<Bomb> bomb;

    public:
    Bloc() : type(1), item(0), player(nullptr), bomb(nullptr) {

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
    inline std::shared_ptr<Bomb> get_bomb() {return bomb;}

    bool available() {
        return ((player == nullptr) && bomb == nullptr && type == 1);
    }

    bool bomb_available() {
        return (bomb == nullptr);
    }

    void set_type(int x) {
        type = x;
    }

    bool set_player(Player& n_player);
    void erase_player() {player = nullptr;}

    bool set_bomb(std::shared_ptr<Bomb>);
    void remove_bomb() {bomb = nullptr;}

    void print();
};

#endif