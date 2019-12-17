#ifndef playerHPP
#define playerHPP

#include <iostream>

#include "bloc.hpp"
#include "bomb.hpp"
#include "map.hpp"
#include "game.hpp"

// On fait hériter chaque type de joueur de la classe Player (humain, IA)

class Player{
private:
    unsigned int num_player; //de 1 à 4
    int x,y; //coordonnées
    unsigned int nbr_bomb, nbr_bomb_used; //nombre de bombes pouvant être placées par le joueur simultanément
    int range; // portée de la bombe
    char name[13] = {'P', 'a', 't', 'r', 'i', 'c', 'k', 'k', 'k', 'k', ' ',(char)num_player,'\0'}; //nom du joueur
    double speed; //en cases par secondes
    unsigned int lives; //nombre de vies
    Bloc* location;

public:
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

    ~Player(){}

    int get_x() {return x;}
    int get_y(){return y;}
    int get_lives(){return lives;}
    unsigned int get_num_player() {return num_player;}
    unsigned int get_nbr_bomb() {return nbr_bomb;}
    unsigned int get_nbr_bomb_used() {return nbr_bomb_used;}
    int get_range() {return range;}

    inline void move(char move); // get move => Map qui gère déplacement

    inline void drop_bomb(void);
    inline void pick_up_object(void);
};

inline void Player::move(char move){
    //On regarde si le mouvmeent souhaité est exécutable et on met à jour les coordonnées
    //En fonction du résultat
    bool move_autorized = false;
    int move_x = 0; //le changement de mouvements
    int move_y = 0;
    switch(move)
    {
        case 'z':
            move_done = move_up_player(this);
            move_y++;
            break;
        case 'd':
            move_done = move_right_player(this);
            move_x++;
            break;
        case 's':
            move_done = move_down_player(this);
            move_y--;
            break;
        case 'q':
            move_done = move_left_player(this);
            move_x--;
            break;
        default:
            break;
    }
    if (move_done==true)
    {
        x+=move_x;
        y+=move_y;
    }
}

inline void Player::drop_bomb(void){}
inline void Player::pick_up_object(void){}


#endif