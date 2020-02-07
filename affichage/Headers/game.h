#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include "Headers/player.h"
//#include "Headers/MainWindow.h"
#include "Headers/Bomb.h"
#include <chrono>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=nullptr);

    void displayStartMenu();
    void displayImage(const char *adresse, int width, int height, int posX, int posY, QGraphicsItem* parent=NULL);

    QGraphicsScene * scene;
    Player* player;
    int player_selected;
    QGraphicsView *fenetre;
    QGraphicsPixmapItem * character_selected;
    QGraphicsTextItem* character_name;
    int intervalle;
    std::chrono::time_point<std::chrono::system_clock> beginning, end, elapsed_time;



public slots:
    void start();
    void selectionMenu();
    void player_selection(int num);
    void secondGame();
    void bombDropped();
    void mort(Player* p);
    //void menuGameOver()
};

#endif // GAME_H