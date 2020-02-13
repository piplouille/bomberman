//export LDFLAGS="-L/usr/local/opt/qt/lib";
//export CPPFLAGS="-I/usr/local/opt/qt/include";

#include <QWidget>
#include <QApplication>
#include "Headers/Game.hpp"

Game* game;

int main( int argc, char * argv[]) {
    QApplication app(argc, argv);

    game = new Game();

    game->show();
    game->displayStartMenu();

    return app.exec();
}

//cd affichage.app/Contents/MacOS/ && ./affichage
//cd ../../.. && make
//qmake -project --> fait le .pro (il faut ajout QT += widgets gui core multimedia)
//qmake --> crée le make du projet, on peut remplacer le chemin du compilateur par /usr/local/Cellar/gcc/9.2.0_1/bin/g++-9 à la fin

/*
Utiliser des auto p = make_unique<classe>(attribut1, attribut2,...) -> unic pointer pour créer objets
Utiliser des shared pointer pour créer des objets
Dans les deux cas, l'objet est détruit automatiquement à la disparission des pointers
*/
