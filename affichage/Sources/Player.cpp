#include "Headers/Player.hpp"

// TODO : Gérer le quota de bombes
// TODO : créer des objets ou augmenter la portée des bombes régulièrement


/*
Constructeurs
*/

Player::Player(unsigned int num_player, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    this ->num_player = num_player;
    lives = 2;
    bomb_range = 1;
    bomb_life = 500;
    bomb_quota = 5;
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
    // setFlag(QGraphicsItem::ItemIsFocusable);
    // setFocus();
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

/*
Player pose une bombe
*/
// void Player::dropBomb(char type) {
//     if (type=='C') {
//         qDebug() << "Classic bomb dropped";
//         Bomb* bb = new Bomb('C', x(), y(), *this);
//         scene() -> addItem(bb);
//     }
//     else if(type=='B') {
//         qDebug() << "Classic bomb dropped";
//         Bomb* bb = new Bomb('B', x(), y(), *this);
//         scene() -> addItem(bb);
//     }
//     decrease_bomb_quota();
//     qDebug() << "Nouveau quota : " << bomb_quota;
// }

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
    decrease_bomb_dropped_by_player();
    qDebug() << "Nouveau quota : " << bomb_dropped_by_player << "/" << bomb_quota;
}

/*
Mort
A checker ?
*/

void Player::death() {
    qDebug() << "Le joueur est entré dans la mort";
    setPixmap(im_dead);
    //scene() -> addItem(this);
    clearFocus();
    qDebug() << "Le joueur est décédé, ne reste plus que son corps";
    QTimer::singleShot(3000,this,SLOT(desepear()));
    //desepear();
}

void Player::disappear() {
    qDebug() << "Tout le decors a disparu, le joueur s'apprête àààà partir";
    scene() ->removeItem(this);
    qDebug() << "il est parti";
    //delete this;
}