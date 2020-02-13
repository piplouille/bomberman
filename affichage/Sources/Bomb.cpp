#include "Headers/Bomb.hpp"
#include <QTimer>
#include <QDebug>

/*
Constructeurs
*/

/**
 * @brief Constructeur des bombes
 * @param char type : type de bombe pour son apparence
 * @param int lifespan : durée du premier clignotement de la bombe
 * @param int range : portée de la bombe
 * @param Player* poseur : joueur ayant posé la bombe
 * @param Map* map : carte sur laquelle est posée la bombe
 * @param QGraphicsPixmapItem* parent : si besoin d'être liée à un autre QGraphicsPixmapItem
 * @return void
 */
Bomb::Bomb(char type, int lifespan, int range, Player* poseur, Map* map, QGraphicsPixmapItem* parent) :
    QGraphicsPixmapItem (parent) {
    this->map = map;
    this->owner = poseur;
    i = owner->get_x();
    j = owner->get_y();
    posX = j*32;
    posY = i*32;

    
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

    this -> setPixmap(im_flashing_1);
    setPos(posX,posY);
    this->lifespan = lifespan;
    this->range = range;
    QTimer::singleShot(1000, this, SLOT(flashing()));
}

/**
 * @breif : Destructeur qui suprime la bombe de la carte et de l'affichage
 * @param : void
 * @return : void
 */
Bomb::~Bomb() {
    scene() -> removeItem(this);
    map->begin(i,j)->remove_bomb();
    owner->decrease_bomb_dropped_by_player();
}



/**
 * @breif : Fonction d'affichage du clignotement de la bombe
 * @param : void
 * @return : void
 */
void Bomb::flashing() {
    lifespan -= 30;
    if(lifespan <= 0) {
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


/**
 * @breif : Fonction d'affichage de la déflagration de la bombe en fonction de sa portée
 * @param : void
 * @return : void
 */
void Bomb::blast() {
    dist++;
    distL++;
    distR++;
    distU++;
    distD++;
    if(dist<range) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_2_left,this);
        blaU -> setRotation(90);
        blaD -> setRotation(90);
        // set their position
        blaL -> setPos(-distL*size,0);
        blaR -> setPos(distR*size,0);
        blaU -> setPos(size,-distU*size);
        blaD -> setPos(size,distD*size);

        blaL -> setParentItem(this);
        blaR -> setParentItem(this);
        blaU -> setParentItem(this);
        blaD -> setParentItem(this);
        

        if(map->begin(i+distD,j)->hit_player() || map->begin(i+distD,j)->getGround()==2 || map->begin(i+distD,j)->getGround()==0) {
            if( map->begin(i+distD,j)->getGround()==2 || map->begin(i+distD,j)->getGround()==0) {distD--;}
            else {
                qDebug() << "Joueur " << map->begin(i+distD,j)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i+distD,j)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i-distU,j)->hit_player() || map->begin(i-distU,j)->getGround()==2 || map->begin(i-distU,j)->getGround()==0) {
            if( map->begin(i-distU,j)->getGround()==2 || map->begin(i-distU,j)->getGround()==0) {distU--;}
            else {
                qDebug() << "Joueur " << map->begin(i-distU,j)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i-distU,j)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i,j+distR)->hit_player() || map->begin(i,j+distR)->getGround()==2 || map->begin(i,j+distR)->getGround()==0) {
            if( map->begin(i,j+distR)->getGround()==2 || map->begin(i,j+distR)->getGround()==0) {distR--;}
            else {
                qDebug() << "Joueur " << map->begin(i,j+distR)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i,j+distR)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i,j-distL)->hit_player() || map->begin(i,j-distL)->getGround()==0 ||  map->begin(i,j-distL)->getGround()==2) {
            if(map->begin(i,j-distL)->getGround()==2 || map->begin(i,j-distL)->getGround()==0) {distL--;}
            else {
                qDebug() << "Joueur " << map->begin(i,j-distL)->getPlayer()->get_num_player() << " touché !!!";
                map->begin(i,j-distL)->getPlayer()->decrease_life();
            }
        }

        QTimer::singleShot(40,this,SLOT(blast()));
    }

    if(dist>range) {delete this;}

    else if(dist==range) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_3_left);
        blaR -> setRotation(180);
        blaU -> setRotation(90);
        blaD -> setRotation(270);
        // set their position

        blaL -> setPos(-distL*size,0);
        blaR -> setPos((distR+1)*size,size);
        blaU -> setPos(size,-distU*size);
        blaD -> setPos(0,distD*size+size);


        blaL -> setParentItem(this);
        blaR -> setParentItem(this);
        blaU -> setParentItem(this);
        blaD -> setParentItem(this);

        
        if(map->begin(i+distD,j)->hit_player() || map->begin(i+distD,j)->getGround()==2 || map->begin(i+distD,j)->getGround()==0) {
            if( map->begin(i+distD,j)->getGround()==2) {
                map->begin(i+distD,j)->set_type(1);
                distD--;
            }
            else if( map->begin(i+distD,j)->getGround()==0) {
                distD--;
            }
            else {
                qDebug() << "Joueur " << map->begin(i+distD,j)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i+distD,j)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i-distU,j)->hit_player() || map->begin(i-distU,j)->getGround()==2 || map->begin(i-distU,j)->getGround()==0) {
            if( map->begin(i-distU,j)->getGround()==2) {
                map->begin(i-distU,j)->set_type(1);
                distU--;
            }
            else if( map->begin(i-distU,j)->getGround()==0) {
                distU--;
            }
            else {
                qDebug() << "Joueur " << map->begin(i-distU,j)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i-distU,j)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i,j+distR)->hit_player() || map->begin(i,j+distR)->getGround()==2 || map->begin(i,j+distR)->getGround()==0) {
            if( map->begin(i,j+distR)->getGround()==2) {
                map->begin(i,j+distR)->set_type(1);
                distR--;
            }
            else if( map->begin(i,j+distR)->getGround()==0) {
                distR--;
            }
            else {
                qDebug() << "Joueur " << map->begin(i,j+distR)->getPlayer()->get_num_player() << "touché !!!";
                map->begin(i,j+distR)->getPlayer()->decrease_life();
            }
        }
        if(map->begin(i,j-distL)->hit_player() || map->begin(i,j-distL)->getGround()==0 ||  map->begin(i,j-distL)->getGround()==2) {
            if(map->begin(i,j-distL)->getGround()==2) {
                map->begin(i,j-distL)->set_type(1);
                distL--;
            }
            else if(map->begin(i,j-distL)->getGround()==0) {
                distL--;
            }
            else {
                qDebug() << "Joueur " << map->begin(i,j-distL)->getPlayer()->get_num_player() << " touché !!!";
                map->begin(i,j-distL)->getPlayer()->decrease_life();
            }
        }

        QTimer::singleShot(300,this,SLOT(blast()));
    }
}

/**
 * @breif : Fonction d'affichage de l'explosion de la bombe
 * @param : void
 * @return : void
 */
void Bomb::exploding() {
    state++;
    int interval = 50;
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
        setPixmap(im_exploding_6);
        QTimer::singleShot(40,this,SLOT(exploding()));
        break;
        default:
        QTimer::singleShot(interval,this,SLOT(blast()));
        setPixmap(im_blast_1);
    }
    return;
}