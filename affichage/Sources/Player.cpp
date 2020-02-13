#include "Headers/Player.hpp"

/*
Constructeurs
*/

/**
 * @brief Constructeur de Player
 * @param unsigned int num_player : type de bombe pour son apparence
 * @param QGraphicsItem *parent : si besoin d'être liée à un autre QGraphicsPixmapItem
 * @return void
 */
Player::Player(unsigned int num_player, QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    this->num_player = num_player;
    lives = 2;
    bomb_range = 4;
    bomb_life = 500;
    bomb_quota = 15;
    bomb_dropped_by_player = 0;

    QString path = ":/Resources/Player/Player_" + QString::number(num_player, 10);

    im_centre = QPixmap(path + "_centre.png");
    im_left = QPixmap(path + "_left.png");
    im_right = QPixmap(path + "_right.png");
    im_dead = QPixmap(path + "_dead.png");

    im_centre = im_centre.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_left = im_left.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_right = im_right.scaled(QSize(size,size), Qt::KeepAspectRatio);
    im_dead = im_dead.scaled(QSize(size,size), Qt::KeepAspectRatio);

    setPixmap(im_centre);
    setPos(0,10*size);
}

/*Constructeur de recopie*/

/**
 * @brief Constructeur de recopie de Player
 * @param const Player& anotherPlayer : référence du Player à recopier
 * @return void
 */
Player::Player(const Player& anotherPlayer) : QGraphicsPixmapItem(anotherPlayer.parentItem()) {
    im_centre = anotherPlayer.im_centre;
    im_left = anotherPlayer.im_left;
    im_right = anotherPlayer.im_right;
    im_dead = anotherPlayer.im_dead;

    num_player = anotherPlayer.num_player;
    lives = anotherPlayer.lives;

    bomb_range = anotherPlayer.bomb_range;
    bomb_quota = anotherPlayer.bomb_quota;
    bomb_life = anotherPlayer.bomb_life;
}

/*
Player pose une bombe
*/

/**
 * @breif : Player crée et pose sur sa case actuelle une bombe à son image
 * @param : char type : Type de bombe ; 'C' : classique ; 'B' : bombitrouille
 * @param : Map* map : Pointeur vers la carte du jeu
 * @return : void
 */
void Player::dropBomb(char type, Map* map) {
    if (type=='C') {
        Bomb* bb = new Bomb('C', bomb_life, bomb_range, this, map);
        scene() -> addItem(bb);
        bool move_done = map -> begin(this->get_x(),this->get_y())->set_bomb(bb);
    }
    else if(type=='B') {
        Bomb* bb = new Bomb('B', bomb_life, bomb_range, this, map);
        scene() -> addItem(bb);
        bool move_done = map -> begin(this->get_x(),this->get_y())->set_bomb(bb);
    }
    increase_bomb_dropped_by_player();
}
