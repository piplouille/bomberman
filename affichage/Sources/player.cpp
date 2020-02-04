#include "Headers/player.h"
//#include "Headers/MainWindow.h"
#include "Headers/Bomb.h"
#include <QDebug>


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPixmap(im_left);
        if(x()>10)
            setPos(x()-16,y());
        else
            setPos(0,y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        setPixmap(im_right);
        if(x()<585)
            setPos(x()+16,y());
        else
            setPos(590,y());    
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPixmap(im_centre);
        if(y()>10)
            setPos(x(),y()-16);
        else
            setPos(x(),0);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPixmap(im_centre);
        if(y()<585)
            setPos(x(),y()+16);
        else
            setPos(x(),590);
    }
    else if(event->key() == Qt::Key_Space)
    {
        qDebug() << "Bomb dropped";
        Bomb*bb = new Bomb(x()+4,y()+4,1000,3);
        scene() -> addItem(bb);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_Right || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
        setPixmap(im_centre);
}