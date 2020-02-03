#include "bomb.hpp"

Bomb::Bomb(Player& p) {
    if (p.able_bomb()) {
        // On récupère les infos de joueur pour créer la bombe
        x = p.get_x();
        y = p.get_y();
        range = p.get_bomb_range();
        owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
        life = p.get_bomb_life(); // à chaque tour ça décroit de 1

        p.decrease_bomb_quota();
    }
}

Bomb::Bomb(Player& p, Map& map) {
    if (p.able_bomb()) {
        // On récupère les infos de joueur pour créer la bombe
        x = p.get_x();
        y = p.get_y();
        range = p.get_bomb_range();
        owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
        life = p.get_bomb_life(); // à chaque tour ça décroit de 1

        // On ajoute les pointeurs vers les blocs qui seront touchés
        int width = map.get_width();
        int length = map.get_length();

        touched.push_back(std::make_shared<Bloc> (*map.begin(x, y)));
        
        for (int indice = 1; indice < range; indice ++) {
            if ((x-indice) >= 0) {
                map.begin(x-indice, y)->set_type();
                touched.push_back(std::make_shared<Bloc> (*map.begin(x-indice, y)));
            }
            if ((x+indice) < width) {
                map.begin(x+indice, y)->set_type();
                touched.push_back(std::make_shared<Bloc> (*map.begin(x+indice, y)));
            }
            if ((y-indice) >= 0) {
                map.begin(x, y-indice)->set_type();
                touched.push_back(std::make_shared<Bloc> (*map.begin(x, y-indice)));
            }
            if ((y+indice) < length) {
                map.begin(x, y+indice)->set_type();
                touched.push_back(std::make_shared<Bloc> (*map.begin(x, y+indice)));
            }            
        }

        // std::cout << "JAI WIDTH et LENGTH : " << width << ", " << length << std::endl;
        // std::cout << "JE POSE EN : (" << x << ", " << y << ")" << std::endl; 
        // J'AI UN RANGE DE ";
        // std::cout << range << "LE NOMBRE DE CASES TOUCHEES :" << touched.size() << std::endl;
        // map.print();

        p.decrease_bomb_quota();
    }
}

Bomb::~Bomb() {
    std::cout << "aïe" << std::endl;
}