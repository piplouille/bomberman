#include "Headers/Game.hpp"
#include "Headers/Button.hpp"
//#include <QTimer>
#include <QGraphicsPixmapItem>
//#include <QFont>
//#include <QMediaPlayer>
//#include <QImage>
#include <QRadioButton>
#include <QButtonGroup>
#include <QColor>
#include <QFont>

// TODO : repositionner les widgets avec layout en non plus en position absolue

Game::Game(QWidget* parent){
    // create the view
    fenetre = new QGraphicsView();
    fenetre -> resize(640,480);

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,640,480); // make the scene 600x400 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/Resources/Land/Sol.png")));
    setScene(scene);
}

void Game::displayImage(const char *adresse, int width, int height, int posX, int posY, QGraphicsItem* parent) {
    QGraphicsPixmapItem * title2 = new QGraphicsPixmapItem(QPixmap(adresse).scaled(QSize(width,height), Qt::KeepAspectRatio));
    title2->setPos(posX,posY);
    scene -> addItem(title2);
    return;
}

/*----------------------------------------------------------------------------------*/



void Game::displayStartMenu() {
    // play background music
    // QMediaPlayer * music = new QMediaPlayer();
    // music->setMedia(QUrl("qrc:/Resources/Music/01_The_Day_Is_My_Enemy.m4a"));
    // music->play();

    //display title
    // QGraphicsPixmapItem * title2 = new QGraphicsPixmapItem(QPixmap(":/Resources/Menu/Title.png").scaled(QSize(this->width()/2-20,this->height()/2-20), Qt::KeepAspectRatio));
    // title2->setPos(this->width()/2 - title2->boundingRect().width()/2,30);
    // scene -> addItem(title2);
    displayImage(":/Resources/Menu/Title.png",this->width()/2-20,this->height()/2-20,this->width()/2 - (this->width()/2-20)/2,30);

    // create the play button
    Button* playButton = new Button(":/Resources/Menu/Start.png");
    int bxPos = this->width()/4 - playButton->boundingRect().width()/2;
    int byPos = 300;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(selectionMenu()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(":/Resources/Menu/Quit.png");
    int qxPos = this->width()*3/4 - quitButton->boundingRect().width()/2;
    int qyPos = 300;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}


/*----------------------------------------------------------------------------------*/
/* Display the character currently selected and his name in the menu */
void Game::player_selection(int num) {
    player_selected = num;
    switch(num){
        case 1:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_1_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Po"));
        break;
        
        case 2:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_2_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Laaa-La"));
        break;

        case 3:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_3_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Dipsy"));
        break;

        case 4:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_4_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Tinky Winky"));
        break;

        case 5:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_5_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Couille"));
        break;

        default:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_1_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Po"));
    }
    character_name -> setPos(this->width()/2-character_name->boundingRect().width()/2,165);
}


/*----------------------------------------------------------------------------------*/



void Game::selectionMenu(){
    //set the scene and the view
    scene -> clear();
    this->resize(240,360);
    fenetre -> resize(240,360); //changes the view
    scene->setSceneRect(0,0,240,360); // changes the scene

    //Bouton pour démarrer
    Button* playButton = new Button(":/Resources/Menu/Start.png");
    int bxPos = fenetre->width()/2 - playButton->boundingRect().width()/2;
    int byPos = fenetre->height()- playButton->boundingRect().height()-20;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //set character <3
    player_selected = 1;
    character_selected = new QGraphicsPixmapItem(QPixmap(":/Resources/Player/Player_1_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
    character_selected -> setPos(this->width()/2-80,10);
    character_name = new QGraphicsTextItem(QString("Po"));
    character_name -> setDefaultTextColor(QColor(Qt::white));
    character_name -> setFont(QFont("System",30,85,false));
    character_name -> setPos(this->width()/2-character_name->boundingRect().width()/2,165);
    scene -> addItem(character_name);
    scene -> addItem(character_selected);

    QButtonGroup* selection = new QButtonGroup();

    QRadioButton* perso1 = new QRadioButton();
    perso1 -> move(30,220);
    scene -> addWidget(perso1);
    QRadioButton* perso2 = new QRadioButton();
    perso2 -> move(70,220);
    scene -> addWidget(perso2);
    QRadioButton* perso3 = new QRadioButton();
    perso3 -> move(110,220);
    scene -> addWidget(perso3);
    QRadioButton* perso4 = new QRadioButton();
    perso4 -> move(150,220);
    scene -> addWidget(perso4);
    QRadioButton* perso5 = new QRadioButton();
    perso5 -> move(190,220);
    scene -> addWidget(perso5);
    selection -> addButton(perso1,1);
    selection -> addButton(perso2,2);
    selection -> addButton(perso3,3);
    selection -> addButton(perso4,4);
    selection -> addButton(perso5,5);
    perso1 -> setChecked(true);

    connect(selection,SIGNAL(buttonClicked(int)),this,SLOT(player_selection(int)));
    
// TODO pour le second menu
    //QAbstractButton Class
    //Changer le QPixmap au dessus des bouttons en fonction de celui qui est selectionné

}


/*----------------------------------------------------------------------------------*/



void Game::start() {
    
    // clear the scene
    scene -> clear();
    fenetre->resize(640,480);
    this->resize(640,480);
    scene->setSceneRect(0,0,640,480); // changes the scene
    // play background music
    // QMediaPlayer * music = new QMediaPlayer();
    // music->setMedia(QUrl("qrc:/Resources/Music/01_The_Day_Is_My_Enemy.m4a"));
    // music->play();

    // create the player
    Player* player = new Player(player_selected);
    scene->addItem(player);
    // add the player to the scene
}