#ifndef bomb_hpp
#define bomb_hpp

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include "bloc.hpp"
#include "bomb.hpp"
#include "map.hpp"

class Bomb
{
private:
    int x, y; // coordonnées de la bombe
    int range; // portée de la bombe
    std::chrono::time_point<std::chrono::system_clock> start,life; // activation et durée de vie de la bomb

public:

    Bomb(int amplitude, int row, int column, std::chrono::time_point<std::chrono::system_clock> elapsed_seconds):
        range(amplitude),x(row),y(column), life(elapsed_seconds)
        {}
    
    ~Bomb()
    {}

protected:

    inline void explose(void); //quand la bombe se delete, elle execute la fonction explose
    inline void destruction(void);
};

inline void destruction(void){}
inline void explose(void){}

#endif