#include "Headers/Game.hpp"
#include "Headers/Button.hpp"
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QRadioButton>
#include <QButtonGroup>
#include <QColor>
#include <QFont>
#include <cstdlib>
#include <QDebug>

// TODO : repositionner les widgets avec layout en non plus en position absolue

Game::Game(QWidget* parent){
    // create the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Resources/Music/01_The_Day_Is_My_Enemy.m4a"));
    music->play();

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

    map_width = 19; //taille par défaut
}

/*----------------------------------------------------------------------------------*/
/*
Choix du personnage (et du mode de jeu ?)
*/

void Game::selectionMenu(){
    //set the scene and the view
    scene -> clear();
    this->resize(500,480);
    fenetre -> resize(500,480); //changes the view
    scene->setSceneRect(0,0,500,480); // changes the scene

    //Bouton pour démarrer
    Button* playButton = new Button(":/Resources/Menu/Start.png");
    int bxPos = fenetre->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 3*fenetre->height()/4- playButton->boundingRect().height()-10;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start())); //secondGame //start()
    scene->addItem(playButton);

    // Bouton d'options
    Button* optionButton = new Button(":/Resources/Menu/option.png");
    int bxPosOp = this->width()/2 - optionButton->boundingRect().width()/2;
    int byPosOp = 380;
    optionButton->setPos(bxPosOp,byPosOp);
    connect(optionButton,SIGNAL(clicked()),this,SLOT(options()));
    scene->addItem(optionButton);

    //set character <3
    player_selected = 1;
    character_selected = new QGraphicsPixmapItem(QPixmap(":/Resources/Player/Player_1_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
    character_selected -> setPos(this->width()/2-80,20);
    character_name = new QGraphicsTextItem(QString("Po"));
    character_name -> setDefaultTextColor(QColor(Qt::white));
    character_name -> setFont(QFont("System",30,85,false));
    character_name -> setPos(this->width()/2-character_name->boundingRect().width()/2,175);
    scene -> addItem(character_name);
    scene -> addItem(character_selected);

    QButtonGroup* selection = new QButtonGroup();

    QRadioButton* perso1 = new QRadioButton();
    perso1 -> move(160,this->height()/2);
    scene -> addWidget(perso1);
    QRadioButton* perso2 = new QRadioButton();
    perso2 -> move(200,this->height()/2);
    scene -> addWidget(perso2);
    QRadioButton* perso3 = new QRadioButton();
    perso3 -> move(240,this->height()/2);
    scene -> addWidget(perso3);
    QRadioButton* perso4 = new QRadioButton();
    perso4 -> move(280,this->height()/2);
    scene -> addWidget(perso4);
    QRadioButton* perso5 = new QRadioButton();
    perso5 -> move(320,this->height()/2);
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
/* Display the character currently selected and his name in the menu */
void Game::player_selection(int num) {
    player_selected = num; // ici on a le player choisi

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
        character_name -> setPlainText(QString("Bouille"));
        break;

        default:
        character_selected -> setPixmap(QPixmap(":/Resources/Player/Player_1_centre.png").scaled(QSize(160,160), Qt::KeepAspectRatio));
        character_name -> setPlainText(QString("Po"));
    }
    character_name -> setPos(this->width()/2-character_name->boundingRect().width()/2,175);
}


/*----------------------------------------------------------------------------------*/


void Game::options() {
    //set the scene and the view
    scene -> clear();
    this->resize(360,360);
    fenetre -> resize(360,360); //changes the view
    scene->setSceneRect(0,0,360,360); // changes the scene

    //The size of the map
    map_display = new QGraphicsTextItem(QString("Normal"));
    map_display -> setDefaultTextColor(QColor(Qt::white));
    map_display -> setFont(QFont("System",50,85,false));
    map_display -> setPos(this->width()/2-map_display->boundingRect().width()/2,this->height()/4-map_display->boundingRect().height()/2);
    scene -> addItem(map_display);

    // Selection buttons
    QButtonGroup* selection = new QButtonGroup();
    QRadioButton* mapSize1 = new QRadioButton(); // Small
    mapSize1 -> move(this->width()/7*2,this->height()/2);
    scene -> addWidget(mapSize1);
    QRadioButton* mapSize2 = new QRadioButton(); // Normal
    mapSize2 -> move(this->width()/7*3,this->height()/2);
    scene -> addWidget(mapSize2);
    QRadioButton* mapSize3 = new QRadioButton(); // Big
    mapSize3 -> move(this->width()/7*4,this->height()/2);
    scene -> addWidget(mapSize3);
    QRadioButton* mapSize4 = new QRadioButton(); // Huge
    mapSize4 -> move(this->width()/7*5,this->height()/2);
    scene -> addWidget(mapSize4);
    selection -> addButton(mapSize1,1);
    selection -> addButton(mapSize2,2);
    selection -> addButton(mapSize3,3);
    selection -> addButton(mapSize4,4);
    mapSize2 -> setChecked(true);

    connect(selection,SIGNAL(buttonClicked(int)),this,SLOT(map_selected(int)));

    // Boutton de retour au menu
    Button* returnToMenu = new Button(":/Resources/Menu/Menu.png");
    int bxMenu = fenetre->width()/2 - returnToMenu->boundingRect().width()/2;
    int byMenu = 3*fenetre->height()/4-returnToMenu->boundingRect().width()/4;// returnToMenu->boundingRect().height();
    returnToMenu->setPos(bxMenu,byMenu);
    connect(returnToMenu,SIGNAL(clicked()),this,SLOT(selectionMenu()));
    scene->addItem(returnToMenu);
}


/*----------------------------------------------------------------------------------*/

void Game::map_selected(int i) {
    switch(i) {
        case 1:
            map_width = 15;
            map_display -> setPlainText(QString("Small"));
            map_display -> setFont(QFont("System",25,85,false));
            break;
        case 2:
            map_width = 19;
            map_display -> setPlainText(QString("Normal"));
            map_display -> setFont(QFont("System",50,85,false));
            break;
        case 3:
            map_width = 23;
            map_display -> setPlainText(QString("Large"));
            map_display -> setFont(QFont("System",80,85,false));
            break;
        case 4:
            map_width = 27;
            map_display -> setPlainText(QString("Huge"));
            map_display -> setFont(QFont("System",110,85,false));
            break;

    }
    map_display -> setPos(this->width()/2-map_display->boundingRect().width()/2,this->height()/4-map_display->boundingRect().height()/2);
}









void Game::start() {
    
    int map_height = map_width>20 ? 19 : map_width-4;

    // clear the scene
    scene -> clear();
    fenetre->resize(32*map_width,32*map_height);
    this->resize(32*map_width,32*map_height);
    scene->setSceneRect(0,0,32*map_width,32*map_height); // changes the scene
    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Resources/Music/01_The_Day_Is_My_Enemy.m4a"));
    music->play();

    // create the player
    Player* player = new Player(player_selected);
    scene->addItem(player);
    map = new Map(map_height,map_width,player);
    scene ->addItem(map);
    // add the player to the scene
    // map.init_player(*player, 0, 0); // on place maxence en 0,0 parce que j'ai aucune info lol
    qDebug() << player->get_num_player();
    qDebug() << map -> hasFocus();
    //qDebug() << map.begin(0, 0)->get_player()->get_num_player();
    // qDebug() << map.get_positions(player->get_num_player())->get_player()->get_num_player();
}



/*----------------------------------------------------------------------------------*/


/*
void Game::secondGame() {
    
    // clear the scene
    scene -> clear();
    fenetre->resize(640,480);
    this->resize(640,480);
    scene->setSceneRect(0,0,640,480); // changes the scene

    // create the player
    //Player* player;
    player = new Player(player_selected);
    scene->addItem(player);

    //Initialisation
    //std::chrono::time_point<std::chrono::system_clock> beginning, end, elapsed_time;

    intervalle = 500;
    beginning = std::chrono::system_clock::now();
    //elapsed_time = std::chrono::system_clock::now();
    bool touched = false;
    QTimer::singleShot(intervalle,this,SLOT(bombDropped()));
    end = std::chrono::system_clock::now();
    /*bool QGraphicsItem::collidesWithItem(const QGraphicsItem * other,
    Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const*/
    // TODO : trouver un moyen de rendre le player indépendant du jeu
/*

void Game::bombDropped() {
    int xB,yB;
    int dimX = 640/32;
    int dimY = 480/32;
    xB = rand() % (dimX);
    yB = rand() % (dimY);

    qDebug() << "Bomb dropped at [" << xB << ", " << yB << "]\nIntervalle = " << intervalle;
    Bomb *b = new Bomb('C',xB*32,yB*32,500,5,player);
    connect(b,SIGNAL(player_touched(Player*)),this,SLOT(mort(Player*)));
    scene -> addItem(b);
    intervalle -= 2;
    if (!(player->isVisible()))
        intervalle = 5;
    if (intervalle>10) {// && player->isVisible())
        QTimer::singleShot(intervalle,this,SLOT(bombDropped()));
        qDebug() << player->isVisible();
    }
    // if (intervalle<10) {
    //     QTimer::singleShot(1000,this,SLOT(bombDropped()));
    // }
}

*/
/*
void Game::mort(Player* p) {
    // Animation de la fin de partie
    //scene -> clear();
    qDebug() << "Player " << p -> getNum_Player() << " dead";
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_time = end - beginning;
    qDebug() << "score : " << elapsed_time.count();
    p -> death();
}
*/
/* void Game::menuGameOver() {
    qDebug() << "Apparition du menu";
    // Affichage du game over
    QGraphicsTextItem *displayGameOver = new QGraphicsTextItem(QString("GAME\nOVER"));
    qDebug() << "Apparition du gm";
    displayGameOver -> setDefaultTextColor(QColor(Qt::white));
    displayGameOver -> setFont(QFont("System",60,85,false));
    displayGameOver -> setPos(this->width()/2-displayGameOver->boundingRect().width()/2,30);
    scene->addItem(displayGameOver);

    // Boutton de retour au menu
    Button* returnToMenu = new Button(":/Resources/Menu/Menu.png");
    int bxMenu = fenetre->width()/2 - returnToMenu->boundingRect().width()/2;
    int byMenu = 3*fenetre->height()/4;// returnToMenu->boundingRect().height();
    returnToMenu->setPos(bxMenu,byMenu);
    connect(returnToMenu,SIGNAL(clicked()),this,SLOT(selectionMenu()));
    scene->addItem(returnToMenu);

}*/

