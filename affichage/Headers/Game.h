#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include "Headers/Player.h"
//#include "Headers/MainWindow.h"
#include "Headers/Bomb.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=nullptr);

    void displayStartMenu();
    void displayImage(const char *adresse, int width, int height, int posX, int posY, QGraphicsItem* parent=NULL);

    QGraphicsScene * scene;
    int player_selected;
    QGraphicsView *fenetre;
    QGraphicsPixmapItem * character_selected;
    QGraphicsTextItem* character_name;


public slots:
    void start();
    void selectionMenu();
    void player_selection(int num);


};

#endif // GAME_H