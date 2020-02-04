#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>
#include <QGraphicsScene>

#include "Headers/Player.h"
#include <memory>

class Bloc;
class Map;

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int posX, posY; //positions de la bombe
    int lifespan; //duree de vie de la premiere animation de la bombe
    int power; //porté de la bombe
    int dist; // distance deja parcourue par la déflagration
    int state; // etat de l'animation
    QPixmap im_flashing_1;
    QPixmap im_flashing_2;
    QPixmap im_exploding_1;
    QPixmap im_exploding_2;
    QPixmap im_exploding_3;
    QPixmap im_exploding_4;
    QPixmap im_exploding_5;
    QPixmap im_exploding_6;
    QPixmap im_blast_1;
    QPixmap im_blast_2_left;
    QPixmap im_blast_3_left;

    int range; // portée de la bombe
    int life; // à chaque action, on enlève un
    std::shared_ptr<Player> owner; // permet de savoir quel décompte de bombe modifier à l'explosion
    std::vector<std::shared_ptr<Bloc> > touched; // l'ensemble des blocs que la bombe va atteindre, en 0 sa case


public:
    Bomb(int, int, int, int,QGraphicsPixmapItem* parent = nullptr);

    ~Bomb(){};



public slots:
    void blast();
    void flashing();
    void exploding();
    //void keyPressEvent(QKeyEvent *event);
};