#ifndef bomb_hpp
#define bomb_hpp

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

class Bomb
{
private:
    int range, x, y;
    std::chrono::time_point<std::chrono::system_clock> start,duree_vie; // c'est quoi ?

public:

    Bomb(int amplitude, int row, int column, std::chrono::time_point<std::chrono::system_clock> elapsed_seconds):
        range(amplitude),x(row),y(column), duree_vie(elapsed_seconds)
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