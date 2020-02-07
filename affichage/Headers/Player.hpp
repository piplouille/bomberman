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
    int num_player; //numéro du joueur

    // int x, y; //coordonnées
    unsigned int bomb_range, bomb_life, bomb_quota;
    unsigned int lives; //nombre de vies    

public:
    Player(int num_player, bool bombDropping, QGraphicsItem *parent=nullptr);

    ~Player(){}

public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int getNum_Player(){return num_player;}
    void death();

public slots:
    void disappear();
};

/*------------------------------------------------*/

#endif