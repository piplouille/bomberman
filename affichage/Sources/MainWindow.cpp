#include "Headers/MainWindow.h"
#include <QDebug>
#include <QGraphicsItem>



/*MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) { //QMainwindow est une classe innée à QT


    QPixmap hellopixmap = QPixmap("../coolkid.jpeg");
    this->hellobox = new QLabel(this);
    this->setCentralWidget(this->hellobox);
    hellobox->setPixmap(hellopixmap);

 
}

MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(400,400);
    //std::shared_ptr<QPushButton> bouton_start;
    //std::shared_ptr<QPushButton> bouton_quit;

    QFont titre("Gunplay",20,80,true);

    bouton_start_presentation = new QPushButton("Let's go !",this);
    //bouton_start = std::make_shared<QPushButton>("Let's go !",this);
    bouton_start_presentation -> setToolTip("Click here to start the game");
    bouton_start_presentation -> setGeometry(0,0,200,400);
    bouton_start_presentation -> setFont(titre);

    bouton_quit_presentation = new QPushButton("Not now...",this);
    //bouton_quit = std::make_shared<QPushButton>("Not now...", this);
    bouton_quit_presentation -> setToolTip("Click here to leave the game");
    bouton_quit_presentation -> setGeometry(200,0,200,400);
    bouton_quit_presentation -> setFont(titre);

    //connect(bouton_quit.get(), SIGNAL(clicked()), qApp, SLOT(quit())); //get() pour passer le pointeur natif, le pointeur sous jassant
    connect(bouton_quit_presentation, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(bouton_start_presentation, SIGNAL(clicked()), this, SLOT(menuselection()));
}

void MaFenetre::menuselection()
{
    delete bouton_start_presentation;
    delete bouton_quit_presentation;
    setFixedSize(800,150);
    move(width()/2,height()/2);

    bouton_quit_menu = new QPushButton("Quit",this);
    bouton_quit_menu -> setToolTip("Click here to leave the game");
    bouton_quit_menu -> setGeometry(100,100,800,50);
    bouton_quit_menu -> setFont(QFont("Gunplay",15,80,true));

    connect(bouton_quit_menu, SIGNAL(clicked()), qApp, SLOT(quit()));
}*/

void MyPlayer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(x()>10)
            setPos(x()-10,y());
        else
            setPos(0,y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x()<585)
            setPos(x()+10,y());
        else
            setPos(590,y());    
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y()>10)
            setPos(x(),y()-10);
        else
            setPos(x(),0);
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(y()<585)
            setPos(x(),y()+10);
        else
            setPos(x(),590);
    }
    else if(event->key() == Qt::Key_Space)
    {
        qDebug() << "Bomb dropped";
        BombDropped *bb = new BombDropped(x()+2,y()+2);
        scene() -> addItem(bb);
    }
}
