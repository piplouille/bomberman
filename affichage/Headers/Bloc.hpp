#ifndef blocHPP
#define blocHPP

#include <memory>
#include <mutex>

#include "Headers/Player.hpp"
#include "Headers/Bomb.hpp"

class Bloc : public std::mutex, public QGraphicsPixmapItem {
    /*
    Maintenant, je peux bloquer l'accès au bloc quand je veux
    */
    private:
    int type; // 0 pour mur, 1 pour herbe
    int item;
    std::shared_ptr<Player> player; // nullptr si personne dessus ; shared_ptr permet aux autres blocs etc de lire
    Bomb* bomb;
    QPixmap image;

    public:
    Bloc(QGraphicsPixmapItem* parent=nullptr) : type(1), item(0), player(nullptr), bomb(nullptr), QGraphicsPixmapItem(parent) {
        qDebug() << "bloc créée";
        setPos(0,0);
        setPixmap(QPixmap(":/Resources/PLayer/Plyer_1_centre.png"));
    }

    Bloc(int x, int y, QGraphicsPixmapItem* parent=nullptr) : type(1), item(0), player(nullptr), bomb(nullptr), QGraphicsPixmapItem(parent) {
        qDebug() << "bloc créée";
        setPos(y*32,x*32);
        setPixmap(QPixmap(":/Resources/Land/Sol.png").scaled(QSize(32,32),Qt::KeepAspectRatio));
    }

    Bloc (int n_type, int n_item, Player &n_player, Bomb &n_bomb)
        : type(n_type), item(n_item), player(&n_player), bomb(&n_bomb) {
    }

    Bloc(const Bloc &bloc) {
        type = bloc.type;
        item = bloc.item;
        player = bloc.player;
        bomb = bloc.bomb;
    }

    inline std::shared_ptr<Player> get_player() {return player;} // on récupère s'il y a un joueur sur le bloc
    inline Bomb* get_bomb() {return bomb;}

    bool available() {
        return ((player == nullptr) && bomb == nullptr && type == 1);
    }

    bool bomb_available() {
        return (bomb == nullptr);
    }

    void set_type(int x) {
        type = x;
        if(type==0){
            image = QPixmap(":/Resources/Land/Mur_16.png");
            image = image.scaled(QSize(32,32), Qt::KeepAspectRatio);
            setPixmap(image);
        }
    }
    void set_type(int type,int x,int y) {
        this -> type = type;
        if(type==0){
            image = QPixmap(":/Resources/Land/MurBlanc_16.png");
            image = image.scaled(QSize(32,32), Qt::KeepAspectRatio);
            setPos(y*32,x*32);
            setPixmap(image);
        }
    }

    bool set_player(Player& n_player);
    void erase_player() {player = nullptr;}

    bool set_bomb(Bomb*);
    void remove_bomb() {bomb = nullptr;}
    bool hit_player() {return (player != nullptr);} //true if there is a player
    Player* getPlayer() {return player.get();}
    void print();
};

#endif