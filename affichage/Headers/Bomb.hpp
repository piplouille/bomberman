#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>
#include <QGraphicsScene>
#include "Headers/Player.hpp"

class Bomb : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

private:
    int posX, posY; //positions de la bombe
    int lifespan; //duree de vie de la premiere animation de la bombe
    int power; //porté de la bombe
    int dist; // distance deja parcourue par la déflagration
    int state; // etat de l'animation
    int size;
    
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
    Player* joueur1;
    Player* joueur2;
    Player* joueur3;
    Player* joueur4;

public:
    // Faire classe mère bombe
    // Et faire hériter les designs de chaque bombe : + propre
    Bomb(char, int, int, int, int, Player*, Player* joueur2=nullptr,
    Player* joueur3=nullptr, Player* joueur4=nullptr, QGraphicsPixmapItem* parent=nullptr);
    ~Bomb(){scene() -> removeItem(this);}

signals:
    void player_touched(Player* player);

public slots:
    void blast();
    void flashing();
    void exploding();
    //void keyPressEvent(QKeyEvent *event);
};