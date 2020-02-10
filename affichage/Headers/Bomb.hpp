#ifndef bombHPP
#define bombHPP

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>
#include <QGraphicsScene>

#include "Headers/Player.hpp"
#include <memory>

class Bloc;
class Map;

class Bomb : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    const int size = 32;

    int posX, posY; //positions de la bombe en pixels
    int i, j; // position de la bombe en cases de map
    int lifespan; //duree de vie de la premiere animation de la bombe
    int range; //porté de la bombe
    int dist = 0; // distance deja parcourue par la déflagration
    int state = 0; // etat de l'animation

    Player* owner;
    std::vector<std::vector<Bloc>::iterator > touched; // l'ensemble des blocs que la bombe va atteindre, en 0 sa case
    
    // faire tableau statique
    QPixmap im_flashing_1;
    QPixmap im_flashing_2;
    // faire tableau statique
    QPixmap im_exploding_1;
    QPixmap im_exploding_2;
    QPixmap im_exploding_3;
    QPixmap im_exploding_4;
    QPixmap im_exploding_5;
    QPixmap im_exploding_6;
    // faire tableau statique
    QPixmap im_blast_1;
    QPixmap im_blast_2_left;
    QPixmap im_blast_3_left;

    // Utiliser le tableau de map svp
    Player* joueur1;
    Player* joueur2;
    Player* joueur3;
    Player* joueur4;

public:
    // Faire classe mère bombe
    // Et faire hériter les designs de chaque bombe : + propre
    // Utiliser touched pour trouver qui se fait toucher
    Bomb(char, int, int, int, int, Player*, Player* joueur2=nullptr,
    Player* joueur3=nullptr, Player* joueur4=nullptr, QGraphicsPixmapItem* parent=nullptr);

    // à terme : virer char et virer int et int
    Bomb(char, int, int, Player&, QGraphicsPixmapItem* parent=nullptr);
    Bomb(char, int, int, Player&, Map&, QGraphicsPixmapItem* parent=nullptr);

    // pour pouvoir compiler
    Bomb(Player&, Map&);
    
    ~Bomb();

    int get_life() {return lifespan;}
    void decrease_life() {lifespan--;}
    void set_x(int x) {posX = x;}
    void set_y(int y) {posY = y;}

signals:
    void player_touched(Player* player);

public slots:
    void blast();
    void flashing();
    void exploding();
    //void keyPressEvent(QKeyEvent *event);
};

#include "Headers/Bloc.hpp"
#include "Headers/Map.hpp"

#endif