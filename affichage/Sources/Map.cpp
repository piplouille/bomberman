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

    // for (int i=0 ; i<4 ; i++) {
    //     positions[i] = end();
    // }
    // on va dire que le contour de la map sont des murs
    for (int i = 0 ; i < width ; i++) {
        begin(i, 0)->set_type(0,i,0);
        begin(i, length - 1)->set_type(0,i,length-1);
    }
    for (int j = 0; j < length ; j++) {
        begin(0, j)->set_type(0,0,j);
        begin(width - 1, j)->set_type(0,width-1,j);
    }

    player1 = n_player1;

    init_player(*player1, 1, 1);
    // if(player2!=nullptr){init_player(*player2, width-1, length-1);}

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qDebug() <<"Position joueur 1 à la fin de l'initialisaiton ("<< player1->get_x() <<", " << player1->get_y()<<")";
    print();
}

void Map::init_player(Player &player, int x, int y) {
    bool move_done;
    move_player(player, x, y, true);
}


/*
----------Déplacement d'un joueur--------------
*/


void Map::move_player(Player &player, int x, int y, bool init) {
    // on veut que player aille en x, y

    qDebug() << player.get_num_player();
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
        qDebug() <<"("<< player.get_x() <<", " << player.get_y()<<")";
    }
    else {
        std::cout << "bitch try again" << std::endl;
    }
    suivant->unlock();
}


void Map::keyPressEvent(QKeyEvent *event) {
    int new_x = player1-> get_x();
    int new_y = player1-> get_y();

    qDebug() << "Avant de se déplacer la position est ("<< player1-> get_x() <<", " << (player1-> get_y())-1<<")";

    auto actuel = begin(player1->get_x(), player1->get_y());

    if(event->key() == Qt::Key_Left) {
        qDebug() << "vous avez pressé left";
        qDebug() <<"Position visée : ("<< player1-> get_x() <<", " << (player1-> get_y())-1<<")";
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
        qDebug() << "vous avez pressé right";
        qDebug() <<"Position visée : ("<< player1-> get_x() <<", " << (player1-> get_y())+1 <<")";
        auto suivant = begin(player1-> get_x(), (player1-> get_y())+1);
        qDebug() << "Ici";
        suivant->lock();
        // demander à bloc en x,y s'il est libre pour accueuillir joueur et bouger
        bool move_done = suivant->set_player(*player1);
        qDebug() << "La";
        if (move_done) {
            // mise à joueur des coordonnées de player
            player1->set_right();
            actuel->erase_player();
        } 
        suivant->unlock();
    }

    else if(event->key() == Qt::Key_Up) {
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

    else if(event->key() == Qt::Key_Space) {
        //player1 -> dropBomb('C');
        put_bomb(*player1);
    }

    else if(event->key() == Qt::Key_B) {
        player1 -> dropBomb('B');
    }

    else if(event->key() == Qt::Key_Q) {
        qApp -> quit();
    }
    print();
    qDebug() << "premier mouvement fait";
}

void Map::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right 
        || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
            player1 -> set_centre();
    }
}

void Map::move_player(Player &player, int move) {
    // On trouve où le joueur veut se déplacer en coordonnées

    int x, y;
    x = player.get_x();
    y = player.get_y();

    int move_x = 0; // le changement de mouvements
    int move_y = 0;

    switch (move) 
    {
        case 0:
            // le nouveau bloc vers le haut : ligne x - 1
            if (x == 0) {
                break;
            }
            move_x--;
            break;
        case 1:
            // le nouveau bloc vers la droite : colonne y + 1
            if (y == length - 1) {
                break;
            }
            move_y++;
            break;
        case 2:
            // le nouveau bloc vers le bas : ligne x + 1
            if (x == width - 1) {
                break;
            }
            move_x++;
            break;
        case 3:
            // le nouveau bloc vers la gauche : colonne y - 1
            if (y == 0) {
                break;
            }
            move_y--;
            break;
    }

    if (move_x != 0 || move_y != 0) {
        bool move_done;
        move_player(player, player.get_x() + move_x, player.get_y() + move_y);
    }
    else {
        std::cout << "Mouvement impossible" << std::endl;
    }
}


/*
-------------Les bombes---------------
*/


void Map::put_bomb(Player &p) {
    p.dropBomb('C', *this);

    // // On vérifie que joueur peut encore poser une bombe
    // if (p.able_bomb()) {
    //     // On appelle un fonction qui init bombe de player
    //     // Bomb bomb(p, *this);
    //     std::shared_ptr<Bomb> bomb(new Bomb(p, *this));

    //     // On pose la bombe sur le bloc si possible
    //     // auto bloc = begin(p.get_x(), p.get_y());
    //     // bloc->lock();
    //     // bool move_done = bloc->set_bomb(bomb);
    //     // if (!move_done) {
    //     //     // On détruit la bombe
    //     //     delete(&bomb);
    //     //     p.increase_bomb_quota();
    //     //     std::cout << "Pas possible de poser" << std::endl;
    //     // }
    //     // else {
    //     //     player1 -> dropBomb('C', *this);
    //     //     std::cout << "J'ai posé" << std::endl;
    //     // }
    //     // bloc->unlock();
    // }
}

void Map::update_bomb() {
    // On prend chaque bloc de la map
    int total = 0;
    for (int i = 0; i < width ; i++) {
        for (int j = 0 ; j < length ; j++) {
            auto bloc = begin(i, j);
            if (!bloc->bomb_available()) {
                // On décrémente
                auto bomb = bloc->get_bomb();
                bomb->decrease_life();
                if (bomb->get_life() == 0) {
                    // On doit faire exploser la bombe !
                    std::cout << "aïe" << std::endl;
                    // delete(&bomb);
                }
                total++;
            }
        }
    }
    // std::cout << "IL Y A " << total << " BOMBES ICI" << std::endl;
}

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

