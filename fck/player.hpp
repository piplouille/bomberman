#ifndef playerHPP
#define playerHPP

#include <iostream>
#include <chrono>

// class Bomb; // bombe sera crée après

class Player {
private:
    unsigned int num_player; //de 0 à 3
    int x, y; //coordonnées
    unsigned int bomb_range, bomb_life, bomb_quota;
    // bomb_life;
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
        
        bomb_range = 1;
        bomb_life = 3;
        bomb_quota = 3;

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
        
        bomb_range = 1;
        bomb_life = 3;
        bomb_quota = 3;
        
        speed = 1.5;
        lives = 1;
    }

    unsigned int get_num_player() {return num_player;}
    int get_x() {return x;}
    int get_y(){return y;}
    void set_x(int n_x) {x = n_x;}
    void set_y(int n_y) {y = n_y;}
    bool able_bomb() {return ((bomb_quota) > 0);}
    void decrase_bomb_quota() {bomb_quota--;}
    int get_bomb_range() {return bomb_range;}
    int get_bomb_life() {return bomb_life;}
};

// #include "bomb.hpp"

// inline void Player::stupid_code_using_bomb(const Bomb& aBomb)
// {
//     aBomb.explode();
// }

#endif