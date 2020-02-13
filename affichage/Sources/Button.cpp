#include "Headers/Button.hpp"
#include <QPixmap>
#include <QSize>
#include <QIcon>
#include <QGraphicsTextItem>


/**
 * @brief Constructeur de Button
 * @param onst char *adresse : l'adresse de l'image du bouton
 * @param QGraphicsItem *parent : l'item parent
 * @return void
 */
Button::Button(const char *adresse, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    image = new QPixmap(adresse);
    setPixmap(*image);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

/*
Events
*/

/**
 * @brief Ce qui se passe lorqu'on clique
 * @param QGraphicsSceneMouseEvent *event
 * @return void
 */
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

/**
 * @brief Le bouton grossit lorsqu'on passe la sourie dessus
 * @param QGraphicsSceneMouseEvent *event
 * @return void
 */
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    *image = image->scaled(QSize(image->width()+10,image->height()+10),Qt::KeepAspectRatio);
    setPixmap(*image);
    setPos(x()-5,y()-2.5);
}

/**
 * @brief Le bouton rapetisse lorqu'on enlève la sourie
 * @param QGraphicsSceneMouseEvent *event
 * @return void
 */
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    *image = image->scaled(QSize(image->width()-5,image->height()-5),Qt::KeepAspectRatio);
    setPos(x()+5,y()+2.5);
    setPixmap(*image);
}