#include "Headers/Bomb.hpp"
#include <QTimer>
#include <QDebug>

void Bomb::blast() {

    dist++;
    if(dist<power) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_2_left,this);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_2_left,this);
        blaU -> setRotation(90);
        blaD -> setRotation(90);
        // set their position
        blaL -> setPos(-dist*size,0);
        blaR -> setPos(dist*size,0);
        blaU -> setPos(size,-dist*size);
        blaD -> setPos(size,dist*size);

        blaL -> setParentItem(this);
        blaR -> setParentItem(this);
        blaU -> setParentItem(this);
        blaD -> setParentItem(this);
        // add to the scene
        
        QTimer::singleShot(40,this,SLOT(blast()));
        if(blaL -> collidesWithItem(joueur1)==true || blaR -> collidesWithItem(joueur1)==true || blaU -> collidesWithItem(joueur1)==true || blaD -> collidesWithItem(joueur1)==true){
            emit player_touched(joueur1);
        }
        if(blaL -> collidesWithItem(joueur2)==true || blaR -> collidesWithItem(joueur2)==true || blaU -> collidesWithItem(joueur2)==true || blaD -> collidesWithItem(joueur2)==true){
            emit player_touched(joueur2);
        }
        if(blaL -> collidesWithItem(joueur3)==true || blaR -> collidesWithItem(joueur3)==true || blaU -> collidesWithItem(joueur3)==true || blaD -> collidesWithItem(joueur3)==true){
            emit player_touched(joueur3);
        }
        if(blaL -> collidesWithItem(joueur4)==true || blaR -> collidesWithItem(joueur4)==true || blaU -> collidesWithItem(joueur4)==true || blaD -> collidesWithItem(joueur4)==true){
            emit player_touched(joueur4);
        }
    }
    if(dist>power) {delete this;}
    else if(dist==power) {
        // create image objects that shall be destroyed
        QGraphicsPixmapItem *blaL = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaR = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaU = new QGraphicsPixmapItem(im_blast_3_left);
        QGraphicsPixmapItem *blaD = new QGraphicsPixmapItem(im_blast_3_left);
        blaR -> setRotation(180);
        blaU -> setRotation(90);
        blaD -> setRotation(270);
        // set their position

        blaL -> setPos(-dist*size,0);
        blaR -> setPos((dist+1)*size,size);
        blaU -> setPos(size,-dist*size);
        blaD -> setPos(0,dist*size+size);


        blaL -> setParentItem(this);
        blaR -> setParentItem(this);
        blaU -> setParentItem(this);
        blaD -> setParentItem(this);
        QTimer::singleShot(300,this,SLOT(blast()));
        if(blaL -> collidesWithItem(joueur1)==true || blaR -> collidesWithItem(joueur1)==true || blaU -> collidesWithItem(joueur1)==true || blaD -> collidesWithItem(joueur1)==true){
            emit player_touched(joueur1);
        }
        if(blaL -> collidesWithItem(joueur2)==true || blaR -> collidesWithItem(joueur2)==true || blaU -> collidesWithItem(joueur2)==true || blaD -> collidesWithItem(joueur2)==true){
            emit player_touched(joueur2);
        }
        if(blaL -> collidesWithItem(joueur3)==true || blaR -> collidesWithItem(joueur3)==true || blaU -> collidesWithItem(joueur3)==true || blaD -> collidesWithItem(joueur3)==true){
            emit player_touched(joueur3);
        }
        if(blaL -> collidesWithItem(joueur4)==true || blaR -> collidesWithItem(joueur4)==true || blaU -> collidesWithItem(joueur4)==true || blaD -> collidesWithItem(joueur4)==true){
            emit player_touched(joueur4);
        }
    }
    
    // TODO trouver comment afficher les enfants
}

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