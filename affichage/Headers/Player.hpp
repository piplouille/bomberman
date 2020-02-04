#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>

#include <iostream>
#include <chrono>

class Player : public QGraphicsPixmapItem {
private:
    QPixmap im_centre;
    QPixmap im_left;
    QPixmap im_right;
    QPixmap im_dead;

    unsigned int num_player; //de 0 à 3
    int coord_x, coord_y; //coordonnées
    unsigned int bomb_range, bomb_life, bomb_quota;
    // bomb_life;
    char name[13] = {'P', 'a', 't', 'r', 'i', 'c', 'k', 'k', 'k', 'k', ' ',(char)num_player,'\0'}; //nom du joueur
    double speed; //en cases par secondes
    unsigned int lives; //nombre de vies

public:
    Player(int n_num_player,QGraphicsItem *parent=nullptr): QGraphicsPixmapItem(parent) {
        switch(n_num_player) {
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
        setPos(0,380);
        setFlag(QGraphicsItem::ItemIsFocusable);
        setFocus();

        num_player = n_num_player;
        coord_x = -1;
        coord_y = -1;

        bomb_range = 2;
        bomb_life = 1000;
        bomb_quota = 3;
        
        lives = 1;
    }

    ~Player(){}

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    unsigned int get_num_player() {return num_player;}
    int get_x() {return coord_x;}
    int get_y(){return coord_y;}
    void set_x(int n_x) {coord_x = n_x;}
    void set_y(int n_y) {coord_y = n_y;}
    bool able_bomb() {return ((bomb_quota) > 0);}
    void decrease_bomb_quota() {bomb_quota--;}
    int get_bomb_range() {return bomb_range;}
    int get_bomb_life() {return bomb_life;}

};

/*------------------------------------------------*/

#endif