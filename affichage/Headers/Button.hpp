#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

// class Button : public QObject, public QGraphicsPixmapItem {
//     Q_OBJECT
// public:
//     Button(QGraphicsItem* parent=nullptr);
//     Button(const char* adresse, QGraphicsItem* parent=nullptr);
//     Button(const char* adresse, int w, int h, QGraphicsItem* parent=nullptr); //image et ses dimensions
//     ~Button(){}

//     void moussePressEvent(QGraphicsSceneMouseEvent *event);
// signals:
//     void clicked();
// };

class Button:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    // constructors
    Button(const char *adresse, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QPixmap* image;
};



#endif