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
    unsigned int nbr_bomb, nbr_bomb_used; //nombre de bombes pouvant être placées par le joueur simultanément
    int range; // portée de la bombe
    char name[13] = {'P', 'a', 't', 'r', 'i', 'c', 'k', 'k', 'k', 'k', ' ',(char) num_player,'\0'}; //nom du joueur
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
        speed = 1.5;
        lives = 1;
    }

    ~Player(){}

    inline int get_x() {return x;}
    inline int get_y(){return y;}
    inline int get_lives(){return lives;}
    inline unsigned int get_num_player() {return num_player;}
    inline unsigned int get_nbr_bomb() {return nbr_bomb;}
    inline unsigned int get_nbr_bomb_used() {return nbr_bomb_used;}
    inline int get_range() {return range;}

    inline void move(void);
    inline void drop_bomb(void);
    inline void pick_up_object(void);
};

inline void move(void){}
inline void drop_bomb(void){}
inline void pick_up_object(void){}


#endif