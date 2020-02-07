#include "Headers/Button.hpp"
#include <QPixmap>
#include <QSize>
#include <QIcon>
#include <QGraphicsTextItem>


Button::Button(const char *adresse, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    image = new QPixmap(adresse);
    setPixmap(*image);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    *image = image->scaled(QSize(image->width()+10,image->height()+10),Qt::KeepAspectRatio);
    setPixmap(*image);
    setPos(x()-5,y()-2.5);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    *image = image->scaled(QSize(image->width()-5,image->height()-5),Qt::KeepAspectRatio);
    setPos(x()+5,y()+2.5);
    setPixmap(*image);
}