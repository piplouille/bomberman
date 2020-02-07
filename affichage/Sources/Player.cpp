#include "Headers/player.h"
//#include "Headers/MainWindow.h"
#include "Headers/Bomb.h"
#include <QDebug>


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPixmap(im_left);
        if(x()>32)
            setPos(x()-32,y());
        else
            setPos(0,y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        setPixmap(im_right);
        if(x()<scene()->width()-32)
            setPos(x()+32,y());
        else
            setPos(scene()->width()-32,y());    
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPixmap(im_centre);
        if(y()>32)
            setPos(x(),y()-32);
        else
            setPos(x(),0);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPixmap(im_centre);
        if(y()<scene()->height()-32)
            setPos(x(),y()+32);
        else
            setPos(x(),scene()->height()-32);
    }
    else if(event->key() == Qt::Key_Space)
    {

        qDebug() << "Classic bomb dropped";
        Bomb*bb = new Bomb('C',x(),y(),500,20,this);
        scene() -> addItem(bb);
    }
    else if(event->key() == Qt::Key_B)
    {

        qDebug() << "Bombitrouille dropped";
        Bomb*bb = new Bomb('B',x(),y(),500,20,this);
        scene() -> addItem(bb);
    }
    else if(event->key() == Qt::Key_Q)
    {
        qApp -> quit();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
        setPixmap(im_centre);
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

void Player::desepear() {
    qDebug() << "Tout le decors a disparu, le joueur s'appraite àààà partir";
    scene() ->removeItem(this);
    qDebug() << "il est parti";
    //delete this;
}