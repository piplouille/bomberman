#include "Headers/Bomb.hpp"
#include <QTimer>
#include <QDebug>

/*
Constructeurs
*/

    /* Constructeur que Laetitia n'aime pas */
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

    /* Constructeur nouveau sans map*/
Bomb::Bomb(char type, int x, int y, Player& p, QGraphicsPixmapItem* parent) : QGraphicsPixmapItem (parent) {
    joueur1 = nullptr;
    joueur2 = nullptr;
    joueur3 = nullptr;
    joueur4 = nullptr;
    if (p.able_bomb()) {
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

        // On récupère les infos de joueur pour créer la bombe
        posX = x;
        posY = y;
        i = p.get_x();
        j = p.get_y();
        range = p.get_bomb_range();
        lifespan = p.get_bomb_life(); // à chaque tour ça décroit de 1
        owner = &p; // permet de savoir quel décompte de bombe modifier à l'explosion
        
        this -> setPixmap(im_flashing_1);
        setPos(posX,posY);
        QTimer::singleShot(1000, this, SLOT(flashing()));

        p.decrease_bomb_quota();
    }
}

    /* Constructeur nouveau AVEC map */
// Bomb::Bomb(char type, int x, int y, Player& p, Map& map, QGraphicsPixmapItem* parent): Bomb(type, x, y, p, parent) {
//     qDebug() << x << " et " << y;
//     if (p.able_bomb()) {
//         // On ajoute les pointeurs vers les blocs qui seront touchés
//         int width = map.get_width();
//         int length = map.get_length();

//         qDebug() << "AVANT : " << QString("0x%1").arg((quintptr)&(map.get_area()[i][j]), QT_POINTER_SIZE * 2, 16, QChar('0'));
//         // touched.push_back(&(*map.begin(i, j)));
//         touched.push_back(&(map.get_area()[i][j]));
//         // touched.push_back(&(*(map.get_area()).front()));
//         qDebug() << "APRES : " << QString("0x%1").arg((quintptr)touched[0], QT_POINTER_SIZE * 2, 16, QChar('0'));

//         for (int indice = 1; indice < range; indice ++) {
//             if ((i-indice) >= 0) {
//                 touched.push_back(&(*map.begin(i-indice, j)));
//             }
//             if ((i+indice) < width) {
//                 touched.push_back(&(*map.begin(i+indice, j)));
//             }
//             if ((j-indice) >= 0) {
//                 touched.push_back(&(*map.begin(i, j-indice)));
//             }
//             if ((j+indice) < length) {
//                 touched.push_back(&(*map.begin(i, j+indice)));
//             }            
//         }
//     }
// }

// Bomb::Bomb(char type, int x, int y, Player& p, Bloc& bloc, QGraphicsPixmapItem* parent): Bomb(type, x, y, p, parent) {
//     if (p.able_bomb()) {
//         current = &bloc;
//     }
// }

    /* Constructeur ancien de fck */
Bomb::Bomb(Player& p, Map& map) {
    if (p.able_bomb()) {
        // On récupère les infos de joueur pour créer la bombe
        posX = p.get_x();
        posY = p.get_y();
        range = p.get_bomb_range();
        owner = &p; // permet de savoir quel décompte de bombe modifier à l'explosion
        lifespan = p.get_bomb_life(); // à chaque tour ça décroit de 1

        // On ajoute les pointeurs vers les blocs qui seront touchés
        int width = map.get_width();
        int length = map.get_length();

        // touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY)));
        
        // for (int indice = 1; indice < range; indice ++) {
        //     if ((posX-indice) >= 0) {
        //         touched.push_back(std::make_shared<Bloc> (*map.begin(posX-indice, posY)));
        //     }
        //     if ((posX+indice) < width) {
        //         touched.push_back(std::make_shared<Bloc> (*map.begin(posX+indice, posY)));
        //     }
        //     if ((posY-indice) >= 0) {
        //         touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY-indice)));
        //     }
        //     if ((posY+indice) < length) {
        //         touched.push_back(std::make_shared<Bloc> (*map.begin(posX, posY+indice)));
        //     }            
        // }

        p.decrease_bomb_quota();
    }
}

Bomb::~Bomb() {
    // qDebug() << "JE SUIS EN : " << QString("0x%1").arg((quintptr)touched[0], QT_POINTER_SIZE * 2, 16, QChar('0'));
    // qDebug() << "MON NUM EST : " << QString("0x%1").arg((quintptr)this, QT_POINTER_SIZE * 2, 16, QChar('0'));
    scene() -> removeItem(this);
    //current->remove_bomb();
    map->begin(i,j)->remove_bomb();
    owner->increase_bomb_quota();
}

/*
Affichage bombe
*/

void Bomb::flashing() {
    qDebug() << "debut flashing";
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

/*
Explosion
*/

void Bomb::blast() {
    qDebug() << "début blast";
    dist++;
    if(dist<range) {
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

        if(map->begin(i+dist,j)->hit_player() || map->begin(i-dist,j)->hit_player() || map->begin(i,j+dist)->hit_player() || map->begin(i,j-dist)->hit_player()) {
            qDebug() << "player hitted!!!!!!!!!!!!!!!!";
        }

        QTimer::singleShot(40,this,SLOT(blast()));
        // if(blaL -> collidesWithItem(joueur1)==true || blaR -> collidesWithItem(joueur1)==true || blaU -> collidesWithItem(joueur1)==true || blaD -> collidesWithItem(joueur1)==true){
        //     emit player_touched(joueur1);
        // }
        // if(blaL -> collidesWithItem(joueur2)==true || blaR -> collidesWithItem(joueur2)==true || blaU -> collidesWithItem(joueur2)==true || blaD -> collidesWithItem(joueur2)==true){
        //     emit player_touched(joueur2);
        // }
        // if(blaL -> collidesWithItem(joueur3)==true || blaR -> collidesWithItem(joueur3)==true || blaU -> collidesWithItem(joueur3)==true || blaD -> collidesWithItem(joueur3)==true){
        //     emit player_touched(joueur3);
        // }
        // if(blaL -> collidesWithItem(joueur4)==true || blaR -> collidesWithItem(joueur4)==true || blaU -> collidesWithItem(joueur4)==true || blaD -> collidesWithItem(joueur4)==true){
        //     emit player_touched(joueur4);
        // }
    }
    if(dist>range) {owner-> increase_bomb_quota();delete this;}
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

        blaL -> setPos(-dist*size,0);
        blaR -> setPos((dist+1)*size,size);
        blaU -> setPos(size,-dist*size);
        blaD -> setPos(0,dist*size+size);


        blaL -> setParentItem(this);
        blaR -> setParentItem(this);
        blaU -> setParentItem(this);
        blaD -> setParentItem(this);

        if(map->begin(i+dist,j)->hit_player() || map->begin(i-dist,j)->hit_player() || map->begin(i,j+dist)->hit_player() || map->begin(i,j-dist)->hit_player()) {
            qDebug() << "player hitted!!!!!!!!!!!!!!!!";
        }

        QTimer::singleShot(300,this,SLOT(blast()));
        // if(blaL -> collidesWithItem(joueur1)==true || blaR -> collidesWithItem(joueur1)==true || blaU -> collidesWithItem(joueur1)==true || blaD -> collidesWithItem(joueur1)==true){
        //     emit player_touched(joueur1);
        // }
        // if(blaL -> collidesWithItem(joueur2)==true || blaR -> collidesWithItem(joueur2)==true || blaU -> collidesWithItem(joueur2)==true || blaD -> collidesWithItem(joueur2)==true){
        //     emit player_touched(joueur2);
        // }
        // if(blaL -> collidesWithItem(joueur3)==true || blaR -> collidesWithItem(joueur3)==true || blaU -> collidesWithItem(joueur3)==true || blaD -> collidesWithItem(joueur3)==true){
        //     emit player_touched(joueur3);
        // }
        // if(blaL -> collidesWithItem(joueur4)==true || blaR -> collidesWithItem(joueur4)==true || blaU -> collidesWithItem(joueur4)==true || blaD -> collidesWithItem(joueur4)==true){
        //     emit player_touched(joueur4);
        // }
    }
}


void Bomb::exploding() {
    qDebug() << "exploding";
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