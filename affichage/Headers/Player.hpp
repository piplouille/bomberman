#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QString>

class Bomb;
class Map;

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    const int size = 32;

    QPixmap im_centre;
    QPixmap im_left;
    QPixmap im_right;
    QPixmap im_dead;
    unsigned int num_player; //numéro du joueur

    int posX, posY; //coordonnées en cases
    unsigned int bomb_range, bomb_life, bomb_quota;
    unsigned int bomb_dropped_by_player;
    unsigned int lives; //nombre de vies    

public:
    Player(unsigned int num_player, QGraphicsItem *parent=nullptr);
    Player(const Player&);

    ~Player(){}

    //void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    //void death();
    void dropBomb(char type);
    void dropBomb(char, Map*);

    unsigned int get_num_player() {return num_player;}
    int get_x() {return posY;}
    int get_y(){ return posX;}
    void set_left(){setPixmap(im_left); posX--; setPos(posX*size,posY*size);}
    void set_right(){setPixmap(im_right); posX++; setPos(posX*size,posY*size);}
    void set_up(){setPixmap(im_centre); posY--; setPos(posX*size,posY*size);}
    void set_down(){setPixmap(im_centre); posY++; setPos(posX*size,posY*size);}
    void set_centre(){setPixmap(im_centre);}
    void set_x(int n_x) {posY = n_x;}
    void set_y(int n_y) {posX = n_y;}
    void set_xy(int n_x, int n_y) {posY = n_x; posX = n_y;setPos(posX*size,posY*size); }
    bool able_bomb() {return ((bomb_quota-bomb_dropped_by_player) > 0);}
    int get_bomb_quota() {return bomb_quota;}
    void decrease_bomb_quota() {bomb_quota--;}
    void increase_bomb_quota() {bomb_quota++;}
    void decrease_bomb_dropped_by_player() {bomb_dropped_by_player--;}
    void increase_bomb_dropped_by_player() {bomb_dropped_by_player++;}
    int get_bomb_range() {return bomb_range;}
    int get_bomb_life() {return bomb_life;}
    void decrease_life() {
        lives--;
        qDebug() << "Il reste " << lives << " vies.";
        if(lives == 0) {
            setPixmap(im_dead);
            emit dead(this);
            qDebug() << "Le joueur " << num_player << " est mort";
        }
    }
    unsigned int getLives() {return lives;}

signals:
    void dead(Player* this_player);


public slots:
    void disappear();
};

#include "Headers/Bomb.hpp"
#include "Headers/Map.hpp"

/*------------------------------------------------*/

#endif