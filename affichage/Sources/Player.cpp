#include "Headers/Player.hpp"


/*
Constructeurs
*/

Player::Player(unsigned int num_player, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    this->num_player = num_player;
    lives = 2;
    bomb_range = 4;
    bomb_life = 500;
    bomb_quota = 15;
    bomb_dropped_by_player = 0;

    QString path = ":/Resources/Player/Player_" + QString::number(num_player, 10);

    im_centre = QPixmap(path + "_centre.png");
    im_left = QPixmap(path + "_left.png");
    im_right = QPixmap(path + "_right.png");
    im_dead = QPixmap(path + "_dead.png");

    im_centre = im_centre.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_left = im_left.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_right = im_right.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_dead = im_dead.scaled(QSize(size,size), Qt::KeepAspectRatio);

    setPixmap(im_centre);
    setPos(0,10*size);
}

/*Constructeur de recopie*/
Player::Player(const Player& anotherPlayer) : QGraphicsPixmapItem(anotherPlayer.parentItem()) {
    im_centre = anotherPlayer.im_centre;
    im_left = anotherPlayer.im_left;
    im_right = anotherPlayer.im_right;
    im_dead = anotherPlayer.im_dead;

    num_player = anotherPlayer.num_player;
    lives = anotherPlayer.lives;

    bomb_range = anotherPlayer.bomb_range;
    bomb_quota = anotherPlayer.bomb_quota;
    bomb_life = anotherPlayer.bomb_life;
}


void Player::dropBomb(char type, Map* map) {
    if (type=='C') {
        Bomb* bb = new Bomb('C', bomb_life, bomb_range, this, map);
        scene() -> addItem(bb);
        bool move_done = map -> begin(this->get_x(),this->get_y())->set_bomb(bb);
    }
    else if(type=='B') {
        Bomb* bb = new Bomb('B', bomb_life, bomb_range, this, map);
        scene() -> addItem(bb);
        bool move_done = map -> begin(this->get_x(),this->get_y())->set_bomb(bb);
    }
    increase_bomb_dropped_by_player();
}

/*
Mort
A checker ?
*/

// void Player::death() {
//     qDebug() << "Le joueur est entré dans la mort";
//     setPixmap(im_dead);
//     //scene() -> addItem(this);
//     //clearFocus();
//     //qDebug() << "Le joueur est décédé, ne reste plus que son corps";
//     //QTimer::singleShot(3000,this,SLOT(desepear()));
//     //desepear();
// }

void Player::disappear() {
    qDebug() << "Tout le decors a disparu, le joueur s'apprête àààà partir";
    scene() ->removeItem(this);
    qDebug() << "il est parti";
    //delete this;
}