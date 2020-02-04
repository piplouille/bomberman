#include "Headers/Bomb.hpp"
#include <QTimer>
/*
Constructeurs
*/

Bomb::Bomb(QGraphicsPixmapItem* parent) : QGraphicsPixmapItem (parent) {
    im_flashing_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_1.png");
    im_flashing_1 = im_flashing_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_flashing_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_2.png");
    im_flashing_2 = im_flashing_2.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_1.png");
    im_exploding_1 = im_exploding_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_2.png");
    im_exploding_2 = im_exploding_2.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_3 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_3.png");
    im_exploding_3 = im_exploding_3.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_4 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_4.png");
    im_exploding_4 = im_exploding_4.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_5 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_5.png");
    im_exploding_5 = im_exploding_5.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_6 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_6.png");
    im_exploding_6 = im_exploding_6.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_1 = QPixmap(":/Resources/Classic_bomb/blast_1.png");
    im_blast_1 = im_blast_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_2_left = QPixmap(":/Resources/Classic_bomb/blast_2.png");
    im_blast_2_left = im_blast_2_left.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_3_left = QPixmap(":/Resources/Classic_bomb/blast_3.png");
    im_blast_3_left = im_blast_2_left.scaled(QSize(24,24),Qt::KeepAspectRatio);

    dist = 0;
    state = 0;

    setPixmap(im_flashing_1);
    QTimer::singleShot(1000, this, SLOT(flashing()));
}


Bomb::Bomb(Player& p, QGraphicsPixmapItem* parent) : Bomb(parent) {
    if (p.able_bomb()) {
        // On récupère les infos de joueur pour créer la bombe
        posX = p.get_x();
        posY = p.get_y();
        range = p.get_bomb_range();
        owner = std::make_shared<Player> (p); // permet de savoir quel décompte de bombe modifier à l'explosion
        lifespan = p.get_bomb_life(); // à chaque tour ça décroit de 1

        p.decrease_bomb_quota();

        setPos(posX, posY);
    }
}

Bomb::Bomb(Player& p, Map& map, QGraphicsPixmapItem* parent) : Bomb(p, parent) {
    if (p.able_bomb()) {
        // On ajoute les pointeurs vers les blocs qui seront touchés
        int width = map.get_width();
        int length = map.get_length();

        touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY)));
        
        for (int indice = 1; indice < range; indice ++) {
            if ((posX-indice) >= 0) {
                touched.push_back(std::make_shared<Bloc> (*map.begin(posX-indice, posY)));
            }
            if ((posX+indice) < width) {
                touched.push_back(std::make_shared<Bloc> (*map.begin(posX+indice, posY)));
            }
            if ((posY-indice) >= 0) {
                touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY-indice)));
            }
            if ((posY+indice) < length) {
                touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY+indice)));
            }            
        }
    }
}


Bomb::Bomb(int x, int y, int lifespan, int power, QGraphicsPixmapItem* parent): QGraphicsPixmapItem (parent) {
    im_flashing_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_1.png");
    im_flashing_1 = im_flashing_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_flashing_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_2.png");
    im_flashing_2 = im_flashing_2.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_1 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_1.png");
    im_exploding_1 = im_exploding_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_2 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_2.png");
    im_exploding_2 = im_exploding_2.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_3 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_3.png");
    im_exploding_3 = im_exploding_3.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_4 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_4.png");
    im_exploding_4 = im_exploding_4.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_5 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_5.png");
    im_exploding_5 = im_exploding_5.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_exploding_6 = QPixmap(":/Resources/Classic_bomb/Bomb_Exploding_6.png");
    im_exploding_6 = im_exploding_6.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_1 = QPixmap(":/Resources/Classic_bomb/blast_1.png");
    im_blast_1 = im_blast_1.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_2_left = QPixmap(":/Resources/Classic_bomb/blast_2.png");
    im_blast_2_left = im_blast_2_left.scaled(QSize(24,24),Qt::KeepAspectRatio);
    im_blast_3_left = QPixmap(":/Resources/Classic_bomb/blast_3.png");
    im_blast_3_left = im_blast_2_left.scaled(QSize(24,24),Qt::KeepAspectRatio);

    posX = x;
    posY = y;
    this -> setPixmap(im_flashing_1);
    setPos(posX, posY);
    this->lifespan = lifespan;
    range = power;
    dist = 0;
    state = 0;
    //flashing(lifespan);
    QTimer::singleShot(1000, this, SLOT(flashing()));
}

/*
Affichage avant explosion
*/

void Bomb::flashing() {
    lifespan -= 50;
    if(lifespan == 0) {
        state = 1;
        QTimer::singleShot(25, this, SLOT(exploding()));
    }
    else {
        if(state==0) {
            setPixmap(im_flashing_2);
            state ++;
        }
        else {
            setPixmap(im_flashing_1); 
            state--;
        }
        QTimer::singleShot(lifespan,this,SLOT(flashing()));
    }
    return;
}

/*
Explosion
*/

void Bomb::blast() {
    //à chaque occurence on crée un QGraphicsPixmapItem que l'on positionne selon posX et posY
    //à la fin, ils sont tous enlevés et détruits
    /*option 2 : une boucle while auto suffisante */
    dist++;
    if(dist<range) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_2_left);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_2_left);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_2_left);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_2_left);
        blaU -> setRotation(90);
        blaD -> setRotation(90);
        // set their position
        blaL -> setPos(posX-dist*24,posY);
        blaR -> setPos(posX+dist*24,posY);
        blaU -> setPos(posX,posY-dist*24);
        blaD -> setPos(posX,posY+dist*24);
        // add to the scene
        scene() -> addItem(blaL);
        scene() -> addItem(blaR);
        scene() -> addItem(blaU);
        scene() -> addItem(blaD);
        QTimer::singleShot(1000,this,SLOT(blast()));

        scene() -> removeItem(blaL);
        scene() -> removeItem(blaR);
        scene() -> removeItem(blaU);
        scene() -> removeItem(blaD);
        delete blaL;
        delete blaR;
        delete blaU;
        delete blaD;
    }
    else if(dist==range) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_3_left);
        blaR -> setRotation(180);
        blaU -> setRotation(270);
        blaD -> setRotation(90);
        // set their position
        blaL -> setPos(posX-dist*24,posY);
        blaR -> setPos(posX+dist*24,posY);
        blaU -> setPos(posX,posY-dist*24);
        blaD -> setPos(posX,posY+dist*24);
        // add to the scene
        scene() -> addItem(blaL);
        scene() -> addItem(blaR);
        scene() -> addItem(blaU);
        scene() -> addItem(blaD);
        QTimer::singleShot(1000,this,SLOT(blast()));

        scene() -> removeItem(blaL);
        scene() -> removeItem(blaR);
        scene() -> removeItem(blaU);
        scene() -> removeItem(blaD);
        delete blaL;
        delete blaR;
        delete blaU;
        delete blaD;
    }
}


void Bomb::exploding() {
    state++;
    int interval = 100;
    switch(state) {
        case 2:
        setPixmap(im_exploding_1); 
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        case 3:
        setPixmap(im_exploding_2);
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        case 4:
        setPixmap(im_exploding_3);
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        case 5:
        setPixmap(im_exploding_4);
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        case 6:
        setPixmap(im_exploding_5);
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        case 7:
        setPixmap(im_exploding_1);
        QTimer::singleShot(interval,this,SLOT(exploding()));
        break;
        default:
        QTimer::singleShot(interval,this,SLOT(blast()));
        setPixmap(im_blast_1);
    }
    return;
}