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

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap im_centre;
    QPixmap im_left;
    QPixmap im_right;
    QPixmap im_dead;
    int num_player; //numéro du joueur


public:
    Player(int num_player, bool bombDropping, QGraphicsItem *parent=nullptr): QGraphicsPixmapItem(parent) {
        this ->num_player = num_player;
        switch(num_player){
            case 1:
            im_centre = QPixmap(":/Resources/Player/Player_1_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_1_left.png");
            im_right = QPixmap(":/Resources/Player/Player_1_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_1_dead.png");
            break;
            
            case 2:
            im_centre = QPixmap(":/Resources/Player/Player_2_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_2_left.png");
            im_right = QPixmap(":/Resources/Player/Player_2_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_2_dead.png");
            break;

            case 3:
            im_centre = QPixmap(":/Resources/Player/Player_3_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_3_left.png");
            im_right = QPixmap(":/Resources/Player/Player_3_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_3_dead.png");
            break;

            case 4:
            im_centre = QPixmap(":/Resources/Player/Player_4_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_4_left.png");
            im_right = QPixmap(":/Resources/Player/Player_4_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_4_dead.png");
            break;

            case 5:
            im_centre = QPixmap(":/Resources/Player/Player_5_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_5_left.png");
            im_right = QPixmap(":/Resources/Player/Player_5_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_5_dead.png");
            break;

            default:
            im_centre = QPixmap(":/Resources/Player/Player_1_centre.png");
            im_left = QPixmap(":/Resources/Player/Player_1_left.png");
            im_right = QPixmap(":/Resources/Player/Player_1_right.png");
            im_dead = QPixmap(":/Resources/Player/Player_1_dead.png");
        }

        im_centre = im_centre.scaled(QSize(32,32), Qt::KeepAspectRatio);
        im_left = im_left.scaled(QSize(32,32), Qt::KeepAspectRatio);
        im_right = im_right.scaled(QSize(32,32), Qt::KeepAspectRatio);
        im_dead = im_dead.scaled(QSize(32,32), Qt::KeepAspectRatio);
        setPixmap(im_centre);
        setPos(0,320);
        setFlag(QGraphicsItem::ItemIsFocusable);
        setFocus();
    }
    ~Player(){}

public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int getNum_Player(){return num_player;}
    void death();
    //void desepear();

public slots:
    void desepear();
};

/*------------------------------------------------*/

#endif