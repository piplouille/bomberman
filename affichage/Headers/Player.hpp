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

#include <QString>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    const int size = 32;

    QPixmap im_centre;
    QPixmap im_left;
    QPixmap im_right;
    QPixmap im_dead;
    unsigned int num_player; //numéro du joueur

    int posX, posY; //coordonnées => Voir si je peux m'en passer et prendre la fonction x() de Qt
    unsigned int bomb_range, bomb_life, bomb_quota;
    unsigned int lives; //nombre de vies    

public:
    Player(unsigned int num_player, QGraphicsItem *parent=nullptr);
    Player(const Player&);

    ~Player(){}

    //void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    void death();
    void dropBomb(char type);

    int getNum_Player(){return num_player;}
    unsigned int get_num_player() {return num_player;}
    int get_x() {return (posX/size);}
    int get_y(){return (posY/size);}
    void set_left(){setPixmap(im_left); posX-=size; setPos(posX,posY);}
    void set_right(){setPixmap(im_right); posX+=size; setPos(posX,posY);}
    void set_up(){setPixmap(im_centre); posY-=size; setPos(posX,posY);}
    void set_down(){setPixmap(im_centre); posY-=size; setPos(posX,posY);}
    void set_centre(){setPixmap(im_centre);}
    void set_x(int n_x) {posX = n_x;}
    void set_y(int n_y) {posY = n_y;}
    void move(int up, int left) {posX+=(left*size);posY+=(up*size);}
    bool able_bomb() {return ((bomb_quota) > 0);}
    void decrease_bomb_quota() {bomb_quota--;}
    int get_bomb_range() {return bomb_range;}
    int get_bomb_life() {return bomb_life;}

public slots:
    void disappear();
};

/*------------------------------------------------*/

#endif