#include "Headers/Map.hpp"
#include <QKeyEvent>

/*
Les constructeurs
*/

// Map::Map(): Map(defaultWidth, defaultLength,&defaultPlayer)
// {}

Map::Map(int aWidth, int aLength,Player* n_player1,Player* n_player2, QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent),
    width(aWidth), length(aLength),
    area(width, std::vector<Bloc>(length)) {

    for (int i = 0 ; i < width ; i++) {
            for (int j = 0; j < length ; j++) {
                begin(i,j)->setParentItem(this);
                begin(i,j) -> setPos(j*32,i*32);
            }
    }
    for (int i = 0 ; i < width ; i++) {
            for (int j = 0; j < length ; j++) {
                if(i%2==0 && j%2==0) {begin(i, j)->set_type(0,i,j);}
            }
    }

    for (int i = 0 ; i < width ; i++) {
        begin(i, 0)->set_type(0,i,0);
        begin(i, length - 1)->set_type(0,i,length-1);
    }
    for (int j = 0; j < length ; j++) {
        begin(0, j)->set_type(0,0,j);
        begin(width - 1, j)->set_type(0,width-1,j);
    }

    player1 = n_player1;
    player2 = n_player2;

    init_player(*player1, 1, 1);
    if(n_player2!=nullptr) {player2 = n_player2; init_player(*player2, width-2, length-2);}

    for (int i = 1 ; i < width-1 ; i++) {
            for (int j = 1; j < length-1 ; j++) {
                if(begin(i, j)->available() && (rand()-RAND_MAX/2)>0) {
                    begin(i, j)->set_type(2,i,j);
                }
            }
    

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qDebug() <<"Position joueur 1 à la fin de l'initialisaiton ("<< player1->get_x() <<", " << player1->get_y()<<")";
    print();
    }
}

void Map::init_player(Player &player, int x, int y) {
    move_player(player, x, y, true);
}


/*
----------Déplacement d'un joueur--------------
*/


void Map::move_player(Player &player, int x, int y, bool init) {
    // on veut que player aille en x, y
    // itérateur
    std::vector<Bloc>::iterator actuel;
    if (!init) {actuel = begin(player.get_x(), player.get_y());}
    auto suivant = begin(x, y);

    // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
    suivant->lock();
    bool move_done = suivant->set_player(player);

    if (move_done) {
        // mise à joueur des coordonnées de player
        player.set_xy(x,y);
        if (!init) {
            actuel->erase_player();
        }
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }
    suivant->unlock();
}



void Map::keyPressEvent(QKeyEvent *event) {

    if(event->key() == Qt::Key_Left) {
        auto actuel = begin(player1->get_x(), player1->get_y());
        auto suivant = begin(player1-> get_x(), (player1-> get_y())-1);
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player1);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player1->set_left();
            actuel->erase_player();
        }
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_Right) {
        auto actuel = begin(player1->get_x(), player1->get_y());
        auto suivant = begin(player1-> get_x(), (player1-> get_y())+1);
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player1);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player1->set_right();
            actuel->erase_player();
        } 
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_Up) {
        auto actuel = begin(player1->get_x(), player1->get_y());
        auto suivant = begin(player1->get_x()-1, player1->get_y());
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player1);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player1->set_up();
            actuel->erase_player();
        }
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_Down) {
        auto actuel = begin(player1->get_x(), player1->get_y());
        auto suivant = begin(player1->get_x() + 1, player1->get_y());
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player1);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player1->set_down();
            actuel->erase_player();
        }
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_M) {
        auto actuel = begin(player1->get_x(), player1->get_y());
        //player1 -> dropBomb('C');
        put_bomb('C', *player1);
    }
//---------MOVES-OF-PKAYER-2----------------------------------------------------------------------------------

    if(event->key() == Qt::Key_Q) {
        auto actuel = begin(player2->get_x(), player2->get_y());
        auto suivant = begin(player2-> get_x(), (player2-> get_y())-1);
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player2);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player2->set_left();
            actuel->erase_player();
        }
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_D) {
        auto actuel = begin(player2->get_x(), player2->get_y());
        auto suivant = begin(player2-> get_x(), (player2-> get_y())+1);
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player2);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player2->set_right();
            actuel->erase_player();
        } 
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_Z) {
        auto actuel = begin(player2->get_x(), player2->get_y());
        auto suivant = begin(player2->get_x()-1, player2->get_y());
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player2);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player2->set_up();
            actuel->erase_player();
        }
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_S) {
        auto actuel = begin(player2->get_x(), player2->get_y());
        auto suivant = begin(player2->get_x() + 1, player2->get_y());
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player2);
        if (move_done) {
            // mise à joueur des coordonnées de player
            player2->set_down();
            actuel->erase_player();
        }
        suivant->unlock();
    }
    else if(event->key() == Qt::Key_C) {
        auto actuel = begin(player2->get_x(), player2->get_y());
        // player1 -> dropBomb('B');
        put_bomb('B', *player2);
    }

    else if(event->key() == Qt::Key_Escape) {
        qApp -> quit();
    }
    // print();
    qDebug() << player1->isVisible();
}

void Map::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right 
        || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
            player1 -> set_centre();
        }
    else if(event->key() == Qt::Key_Q || event->key() == Qt::Key_D 
        || event->key() == Qt::Key_Z || event->key() == Qt::Key_S) {
            player2 -> set_centre();
        }
}

// void Map::move_player(Player &player, int move) {
//     // On trouve où le joueur veut se déplacer en coordonnées

//     int x, y;
//     x = player.get_x();
//     y = player.get_y();

//     int move_x = 0; // le changement de mouvements
//     int move_y = 0;

//     switch (move) 
//     {
//         case 0:
//             // le nouveau bloc vers le haut : ligne x - 1
//             if (x == 0) {
//                 break;
//             }
//             move_x--;
//             break;
//         case 1:
//             // le nouveau bloc vers la droite : colonne y + 1
//             if (y == length - 1) {
//                 break;
//             }
//             move_y++;
//             break;
//         case 2:
//             // le nouveau bloc vers le bas : ligne x + 1
//             if (x == width - 1) {
//                 break;
//             }
//             move_x++;
//             break;
//         case 3:
//             // le nouveau bloc vers la gauche : colonne y - 1
//             if (y == 0) {
//                 break;
//             }
//             move_y--;
//             break;
//     }

//     if (move_x != 0 || move_y != 0) {
//         bool move_done;
//         move_player(player, player.get_x() + move_x, player.get_y() + move_y);
//     }
//     else {
//         std::cout << "Mouvement impossible" << std::endl;
//     }
// }


/*
-------------Les bombes---------------
*/


void Map::put_bomb(char type, Player &p) {
    
    auto bloc = begin(p.get_x(), p.get_y());
    bloc->lock();
    if (bloc->bomb_available() && p.able_bomb()) {
        p.dropBomb(type, this);
    }
    bloc->unlock();
}

// void Map::update_bomb() {
//     // On prend chaque bloc de la map
//     int total = 0;
//     for (int i = 0; i < width ; i++) {
//         for (int j = 0 ; j < length ; j++) {
//             auto bloc = begin(i, j);
//             if (!bloc->bomb_available()) {
//                 // On décrémente
//                 auto bomb = bloc->get_bomb();
//                 bomb->decrease_life();
//                 if (bomb->get_life() == 0) {
//                     // On doit faire exploser la bombe !
//                     std::cout << "aïe" << std::endl;
//                     // delete(&bomb);
//                 }
//                 total++;
//             }
//         }
//     }
//     // std::cout << "IL Y A " << total << " BOMBES ICI" << std::endl;
// }

/*
Fonctions de print
*/

void Map::print(Player &p) {
    std::cout << "Coord du joueur " << p.get_num_player() << " : (" << p.get_x() << "," << p.get_y() << ")" << std::endl;
}

void Map::print() {
    for (int i=0 ; i<width ; i++) {
        for (int j=0 ; j<length; j++) {
            area[i][j].print();
        }
        std::cout << std::endl;
    }
}

/*
Gestion des itérateurs
*/

Map::area_type::iterator Map::begin(int x) {
    return (area.begin() + x);
}

std::vector<Bloc>::iterator Map::begin(int x, int y) {
    // qDebug() << "On arrive dans le begin(x,y)";
    return (area.begin() + x)->begin() + y;
}

std::vector<Bloc>::iterator Map::end(int x) {
    return (area.begin() + x)->end();
}
std::vector<Bloc>::iterator Map::end() {
    // Valeur par défaut si "nullptr"
    return (area.begin() + width)->end();
}

