#include "Headers/Player.hpp"

/*
Constructeurs
*/

Player::Player(unsigned int num_player, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    this ->num_player = num_player;
    lives = 1;
    bomb_range = 1;
    bomb_life = 500;
    bomb_quota = 5;

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
Gestionnaire d'event concernant player
*/

// void Player::keyPressEvent(QKeyEvent *event) {
//     if(event->key() == Qt::Key_Left) {
//         setPixmap(im_left);
//         if(x()>size) {setPos(x()-size,y());}
//         else {setPos(0,y());}
//     }

//     else if(event->key() == Qt::Key_Right) {
//         setPixmap(im_right);
//         if(x()<scene()->width()-size) setPos(x()+size,y());
//         else setPos(scene()->width()-size,y());    
//     }

//     else if(event->key() == Qt::Key_Up) {
//         setPixmap(im_centre);
//         if(y()>size) setPos(x(),y()-size);
//         else setPos(x(),0);
//     }

//     else if(event->key() == Qt::Key_Down) {
//         setPixmap(im_centre);
//         if(y()<scene()->height()-size) setPos(x(),y()+size);
//         else setPos(x(),scene()->height()-size);
//     }

//     else if(event->key() == Qt::Key_Space) {
//         qDebug() << "Classic bomb dropped";
//         Bomb* bb = new Bomb('C', x(), y(), bomb_life, bomb_range, this);
//         scene() -> addItem(bb);
//     }

//     else if(event->key() == Qt::Key_B) {
//         qDebug() << "Bombitrouille dropped";
//         Bomb* bb = new Bomb('B', x(), y(), bomb_life, bomb_range, this);
//         scene() -> addItem(bb);
//     }

//     else if(event->key() == Qt::Key_Q) {
//         qApp -> quit();
//     }
// }

// void Player::keyReleaseEvent(QKeyEvent *event) {
//     if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right 
//         || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
//             setPixmap(im_centre);
//     }
// }

/*
Player pose une bombe
*/
void Player::dropBomb(char type) {
    if (type=='C') {
        qDebug() << "Classic bomb dropped";
        Bomb* bb = new Bomb('C', x(), y(), *this);
        scene() -> addItem(bb);
    }
    else if(type=='B') {
        qDebug() << "Classic bomb dropped";
        Bomb* bb = new Bomb('B', x(), y(), bomb_life, bomb_range, this);
        scene() -> addItem(bb);
    }
}

void Player::dropBomb(char type, Map& map) {
    if (type=='C') {
        qDebug() << "Classic bomb dropped";
        Bomb* bb = new Bomb('C', x(), y(), *this, map);
        scene() -> addItem(bb);
    }
    else if(type=='B') {
        qDebug() << "Classic bomb dropped";
        Bomb* bb = new Bomb('B', x(), y(), bomb_life, bomb_range, this);
        scene() -> addItem(bb);
    }
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