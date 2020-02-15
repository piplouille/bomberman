# B O M B E R M A N
IN204 - Project c++

## Compilation

### Installation de Qt5

```
sudo apt install qt5-default
```

### Compiler

> La compilation sur Mac et Linux se fait de manière similaire.
> Les instructions précédées de "$" sont à faire dans le terminal.

Se rendre dans le dossier ```affichage```.

```
$ qmake -project
```

Ouvrir le fichier ```affichage.pro``` et y ajouter à la toute fin la ligne :
```
QT += gui core multimedia widgets
```

Puis

```
$ qmake
$ make
```

Attention : la compilation prend beaucoup de temps lors du traitement de res.qrc

## Manuel du jeu

### Fonctions principales

| Fonction               | Touche |
| --------               | ------ |
| Quitter                | Echap  |
| Revenir au jeu (focus) | Tab    |

### Joueur 1 (celui qui choisit son personnage)

| Fonction               | Touche          |
| --------               | ------          |
| Déplacement en haut    | Flèche du haut  |
| Déplacement à droite   | Flèche de droite|
| Déplacement en bas     | Flèche du bas   |
| Déplacement à gauche   | Flèche de gauche|
| Poser une bombe        | Shift           |

### Joueur 2

| Fonction               | Touche |
| --------               | ------ |
| Déplacement en haut    | Z      |
| Déplacement à droite   | D      |
| Déplacement en bas     | S      |
| Déplacement à gauche   | Q      |
| Poser une bombe        | E      |

## Documentation

### Déplacement d'un joueur

- Display (interface) [récupère touche clavier](https://developer.gnome.org/gtkmm-tutorial/stable/sec-keyboardevents-overview.html.en) qui demande déplacement
- (done) Map demande à Joueur de se déplacer
- (done) Joueur demande à Bloc s'il peut venir
- (done) Joueur s'en va de l'ancienne case et change ses coordonnées

Ca foire on fait plutot :
- interface
- Map regarde où est Joueur et demande à Bloc s'il peut venir
- Map déplace Joueur et change ses coords

## Déroulé du projet

[Sujet](https://perso.ensta-paris.fr/~bmonsuez/Cours/lib/exe/fetch.php?media=in204:projet_informatique_-_tetris.pdf)

[Des classes en attribut de classe](https://www.ensta-bretagne.fr/jaulin/polycottenceau.pdf)

1. Analyse du problème
    * Use case analysis
    * Analyse fonctionnelle du logiciel
    * Architecture gros grains du logiciel
2. Réaliser un démonstrateur
    * Description du modèle d'architecture
    * Bien documenter les choix des classes
    * Réaliser une implantation documentée du logiciel

## Objectifs :
* Implanter complètement les règles du Bomberman mode solo (avec et sans ia)
* Mode multijoueur local ou online

## Description du jeu

### Plateau de jeu

Par défaut : 8x8

4 types de sol :
1. Vide
2. Vide avec objet
3. Cloison indestructible
4. Cloison cassable

Chaque joueur commence à un coin du plateau : max 4 joueurs

### Déplacements du joueur

Déplacement discret, une case par une case

### Pose et explosion des bombes

Chronomètre avant explosion dépendant du joueur
Ne peut se poser que sur une case vide
Se pose sur la case actuelle du joueur
Explose dans 4 directions sur un nombre de cases dépendant des caractéristiques du joueur

### Cas d'explosion de bloc du plateau

Si au moment de l'explosion d'une bombe un bloc cassable est dans son périmètre, il se brise et devient une case vide

### But du jeu

#### Nombre de vies limité

But : faire exploser l'autre joueur jusqu'à ce que son nombre de vie tombe à zéro
