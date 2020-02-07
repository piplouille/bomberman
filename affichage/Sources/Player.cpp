#include "Headers/Player.hpp"
#include "Headers/Bomb.hpp"
#include <QDebug>

/*
Constructeurs
*/

Player::Player(int num_player, bool bombDropping, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {    this ->num_player = num_player;
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

void Player::keyPressEvent(QKeyEvent *event) {

    if(event->key() == Qt::Key_Left) {
        setPixmap(im_left);
        if(x()>32)
            setPos(x()-32,y());
        else
            setPos(0,y());
    }

    else if(event->key() == Qt::Key_Right) {
        setPixmap(im_right);

        if(x()<scene()->width()-32) setPos(x()+32,y());
        else setPos(scene()->width()-32,y());    
    }

    else if(event->key() == Qt::Key_Up) {
        setPixmap(im_centre);

        if(y()>32) setPos(x(),y()-32);
        else setPos(x(),0);
    }

    else if(event->key() == Qt::Key_Down) {
        setPixmap(im_centre);
        if(y()<scene()->height()-32) setPos(x(),y()+32);
        else setPos(x(),scene()->height()-32);
    }

    else if(event->key() == Qt::Key_Space) {
        qDebug() << "Classic bomb dropped";
        Bomb*bb = new Bomb('C',x(),y(),500,20,this);
        scene() -> addItem(bb);
    }

    else if(event->key() == Qt::Key_B) {
        qDebug() << "Bombitrouille dropped";
        Bomb*bb = new Bomb('B',x(),y(),500,20,this);
        scene() -> addItem(bb);
    }

    else if(event->key() == Qt::Key_Q) {
        qApp -> quit();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right 
        || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
        setPixmap(im_centre);
    }
}

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