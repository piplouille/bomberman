#ifndef playerHPP
#define playerHPP

#include <iostream>

// class Bomb; // bombe sera crée après

class Player {
private:
    unsigned int num_player; //de 0 à 3
    int x, y; //coordonnées
    unsigned int nbr_bomb, nbr_bomb_used; //nombre de bombes pouvant être placées par le joueur simultanément
    int range; // portée de la bombe
    char name[13] = {'P', 'a', 't', 'r', 'i', 'c', 'k', 'k', 'k', 'k', ' ',(char)num_player,'\0'}; //nom du joueur
    double speed; //en cases par secondes
    unsigned int lives; //nombre de vies

public:
    Player() {
        // joueur : id du joueur de 0 à 3 pour se conformer à l'indexation du tableau
        num_player = 0;
        // x = joueur/3;
        // y = joueur%2; //un premier moyen de faire des emplacement différents pour chaque joueurs
        x = 0;
        y = 0;
        
        range = 1;
        nbr_bomb = 1;
        nbr_bomb_used = 0;
        speed = 1.5;
        lives = 1;
    }
    Player(int joueur) {
        // joueur : id du joueur de 0 à 3 pour se conformer à l'indexation du tableau
        num_player = joueur;
        // x = joueur/3;
        // y = joueur%2; //un premier moyen de faire des emplacement différents pour chaque joueurs
        x = 0;
        y = 0;
        
        range = 1;
        nbr_bomb = 1;
        nbr_bomb_used = 0;
        speed = 1.5;
        lives = 1;
    }

    int get_x() {return x;}
    int get_y(){return y;}
    void set_x(int n_x) {x = n_x;}
    void set_y(int n_y) {y = n_y;}
    unsigned int get_num_player() {return num_player;}
};

// #include "bomb.hpp"

// inline void Player::stupid_code_using_bomb(const Bomb& aBomb)
// {
//     aBomb.explode();
// }

#endif