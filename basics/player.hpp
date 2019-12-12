#ifndef playerHPP
#define playerHPP

#include <iostream>
#include "bloc.hpp"
#include "bomb.hpp"
#include "map.hpp"

class Player{
private:
    unsigned int num_player; //de 1 à 4
    int x,y; //coordonnées
    unsigned int nbr_bomb, nbr_bomb_used; //nombre de bombe pouvant être placées par le joueur simultanément
    int range;
    char name[100]; //nom du joueur
    double speed; //en cases par secondes
    unsigned int lives; //nombre de vies

public:
    Player(int joueur) {
        num_player = joueur;
        x = joueur/3;
        y = joueur%2; //un premier moyen de faire des emplacement différents pour chaque joueurs
        range = 1;
        nbr_bomb = 0;
        nbr_bomb_used = 0;
        name = "Patrikkk";
        speed = 1.5;
        lives = 1;
    }

    ~Player(){}

    inline void move(void);
    inline void drop_bomb(void);
    inline void pick_up_object(void);
};

inline void move(void){}
inline void drop_bomb(void){}
inline void pick_up_object(void){}


#endif