#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QSize>
#include <QPixmap>
#include <QGraphicsScene>
#include "Headers/player.h"

class Bomb : public QObject, public QGraphicsPixmapItem
{
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
    Bomb(char type, int x, int y, int lifespan, int power,Player* joueur1, Player* joueur2=nullptr,
        Player* joueur3=nullptr,Player* joueur4=nullptr,QGraphicsPixmapItem* parent=nullptr):
        QGraphicsPixmapItem (parent) {
        
        this->joueur1 = joueur1;
        this->joueur2 = joueur2;
        this->joueur3 = joueur3;
        this->joueur4 = joueur4;


        size = 32;
        if(type == 'C') {
            im_flashing_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_1.png");
            im_flashing_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_2.png");
            im_exploding_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_1.png");
            im_exploding_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_2.png");
            im_exploding_3 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_3.png");
            im_exploding_4 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_4.png");
            im_exploding_5 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_5.png");
            im_exploding_6 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_6.png");
            im_blast_1 = QPixmap(":/Resources/Classic_bomb/blast_2.png");
            im_blast_2_left = QPixmap(":/Resources/Classic_bomb/blast_1.png");
            im_blast_3_left = QPixmap(":/Resources/Classic_bomb/blast_3.png");
        }
        else if(type == 'B') {
            im_flashing_1 = QPixmap(":/Resources/bombitrouille/BBT_flashing_1.png");
            im_flashing_2 = QPixmap(":/Resources/bombitrouille/BBT_flashing_2.png");
            im_exploding_1 = QPixmap(":/Resources/bombitrouille/BBT_Exp_1.png");
            im_exploding_2 = QPixmap(":/Resources/bombitrouille/BBT_Exp_2.png");
            im_exploding_3 = QPixmap(":/Resources/bombitrouille/BBT_Exp_3.png");
            im_exploding_4 = QPixmap(":/Resources/bombitrouille/BBT_Exp_4.png");
            im_exploding_5 = QPixmap(":/Resources/bombitrouille/BBT_Exp_5.png");
            im_exploding_6 = QPixmap(":/Resources/bombitrouille/BBT_Exp_6.png");
            im_blast_1 = QPixmap(":/Resources/bombitrouille/BBT_Blast_1.png");
            im_blast_2_left = QPixmap(":/Resources/bombitrouille/BBT_Blast_2.png");
            im_blast_3_left = QPixmap(":/Resources/bombitrouille/BBT_Blast_3.png");
        }
        im_flashing_1 = im_flashing_1.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_flashing_2 = im_flashing_2.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_1 = im_exploding_1.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_2 = im_exploding_2.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_3 = im_exploding_3.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_4 = im_exploding_4.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_5 = im_exploding_5.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_exploding_6 = im_exploding_6.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_blast_1 = im_blast_1.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_blast_2_left = im_blast_2_left.scaled(QSize(size,size),Qt::KeepAspectRatio);
        im_blast_3_left = im_blast_3_left.scaled(QSize(size,size),Qt::KeepAspectRatio);

        this -> posX = x;
        this -> posY = y;
        this -> setPixmap(im_flashing_1);
        setPos(posX,posY);
        this->lifespan = lifespan;
        this->power = power;
        dist = 0;
        state = 0;
        QTimer::singleShot(1000, this, SLOT(flashing()));
    }
    ~Bomb(){scene() -> removeItem(this);}

signals:
    void player_touched(Player* player);

public slots:
    void blast();
    void flashing();
    void exploding();
    //void keyPressEvent(QKeyEvent *event);
};