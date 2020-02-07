#pragma once // <=> DEF IFNDEF

#include <QMainWindow>
#include <QApplication>
//#include <QLabel>  //Header pour avoir une boite de texte
//#include <QPixmap> //Header pour une image
//#include <QPushButton> //Headerr pour les boutton de Qt
//#include <memory> //pour les std::make_unique
#include <QObject>
#include <QWidget>
//#include <QGraphicsRectItem> //Header pour les formes rectangulaires de Qt
//#include <QGraphicsEllipseItem> //Header pour les formes arrondies de Qt
#include <QKeyEvent> //Header pour les evenements issus de la pression d'une touche du clavier/sourie
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
/*
    - QImage is designed and optimized for I/O, and for direct pixel access and manipulation
    - QPixmap is designed and optimized for showing images on screen
    - QBitmap is only a convenience class that inherits QPixmap, ensuring a depth of 1
    - QPicture class is a paint device that records and replays QPainter commands.
*/




/*idées :
bool QGraphicsItem::contains(const QPointF &point) const --> te dit si un point est dans l'elipse
*/
/*class MainWindow : public QMainWindow{ // Classe héritée d'une classe de QT QMainWindow

    Q_OBJECT // Macro de QT qu'il faut mettre pour que ça fonctionne

    public:
        MainWindow(QWidget *parent = 0); // constructeur
        QLabel *hellobox;
};

class MaFenetre : public QWidget
{
    Q_OBJECT //permeet d'indiquer au qmake qu'on va utiliser nos propres slots

    public:
    MaFenetre();
    ~MaFenetre() {
        delete bouton_start_presentation;
        delete bouton_quit_presentation;
        delete bouton_quit_menu;
    }

    public slots:
    void menuselection();

    private:
    //std::shared_ptr<QPushButton> bouton_start;
    //std::shared_ptr<QPushButton> bouton_quit;
    QPushButton *bouton_start_presentation;
    QPushButton *bouton_quit_presentation;
    QPushButton *bouton_quit_menu;
};*/


class MyPlayer : public QGraphicsPixmapItem
{
    public:
    void keyPressEvent(QKeyEvent *event);
};

class BombDropped : public QObject, public QGraphicsPixmapItem
{
    public:
    BombDropped(int x, int y) {
        setPixmap(QPixmap(":/Resources/Classic_bomb/Bomb_Flashing_1.png"));
        setPos(x,y);

        //setRect(x,y,5,5);
    }
    //void keyPressEvent(QKeyEvent *event);
};