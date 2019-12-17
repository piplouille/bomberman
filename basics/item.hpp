#ifndef itemHPP
#define itemHPP

#include <iostream>
#include "bloc.hpp"
#include "player.hpp"
#include "bomb.hpp"
#include "map.hpp"

/*
Effets pouvant être déclanchés :
1 : range++
2 : speed += 0.5
3 : nbr_bomb++

4 : range--
5 : speed -= 0.5
6 : nbr_bomb--
*/

// Il faut faire hériter chaque item de la classe Item

class Item{
private:
    int x,y; //coordonnée des objets
    unsigned int power; //le numéro de l'effet déclanché
    int counter;

public:
    Item(){}
    ~Item(){}

    inline int get_x(void){return x;}
    inline int get_y(void){return y;}
    inline unsigned int get_power(void){return power;}
    inline int get_counter(void){return counter;}
};

#endif