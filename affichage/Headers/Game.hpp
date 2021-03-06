#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include "Headers/Player.hpp"
#include "Headers/Bomb.hpp"
#include "Headers/Map.hpp"
#include <chrono>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    QGraphicsScene* scene;

    Player* player;

    int player_selected; // pour le menu ok
    int map_width;

    QGraphicsView *fenetre;
    QGraphicsPixmapItem * character_selected;
    QGraphicsTextItem* character_name;
    QGraphicsTextItem* map_display;
    Map *map;
    int intervalle;
    std::chrono::time_point<std::chrono::system_clock> beginning, end, elapsed_time;
    
public:
    Game();

    void displayStartMenu();
    void displayImage(const char *adresse, int width, int height, int posX, int posY, QGraphicsItem* parent=NULL);

public slots:
    void start();
    void selectionMenu();
    void player_selection(int num);
    void options();
    void map_selected(int num);
    void secondGame();
    void menuGameOver(Player*);
};

#endif // GAME_H