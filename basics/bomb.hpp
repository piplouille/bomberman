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
    std::chrono::time_point<std::chrono::system_clock> start; // c'est quoi ?
    double temps; // c'est quoi ?

public:
    void destruction() {
        while(std::chrono::system_clock::now()<start+temps) // tu dois définir l'opérateur + entre un temps et un double
        {/*ne rien faire*/}
        delete this;
    }

    Bomb(int amplitude, int row, int column, double elapsed_seconds):
        range(amplitude),x(row),y(column), temps(elapsed_seconds)
        {
            start = std::chrono::system_clock::now();
        }
    
    ~Bomb()
    {
        explose(joueurs_coord);
    }

protected:

    inline void explose(int joueurs_coord){}; //quand la bombe se delete, elle execute la fonction explose

};

#endif