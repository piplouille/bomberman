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

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    const int size = 32;

    QPixmap im_centre;
    QPixmap im_left;
    QPixmap im_right;
    QPixmap im_dead;
    unsigned int num_player; //numéro du joueur

    // int x, y; //coordonnées => Voir si je peux m'en passer et prendre la fonction x() de Qt
    unsigned int bomb_range, bomb_life, bomb_quota;
    unsigned int lives; //nombre de vies    

public:
    Player(unsigned int num_player, bool bombDropping, QGraphicsItem *parent=nullptr);
    Player(const Player&);

    ~Player(){}

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void death();

    int getNum_Player(){return num_player;}
    unsigned int get_num_player() {return num_player;}
    // int get_x() {return x;}
    // int get_y(){return y;}
    // void set_x(int n_x) {x = n_x;}
    // void set_y(int n_y) {y = n_y;}
    bool able_bomb() {return ((bomb_quota) > 0);}
    void decrease_bomb_quota() {bomb_quota--;}
    int get_bomb_range() {return bomb_range;}
    int get_bomb_life() {return bomb_life;}

public slots:
    void disappear();
};

/*------------------------------------------------*/

#endif