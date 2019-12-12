# B O M B E R M A N
IN204 - Project c++

## Déroulé du projet

[Sujet](https://perso.ensta-paris.fr/~bmonsuez/Cours/lib/exe/fetch.php?media=in204:projet_informatique_-_tetris.pdf)

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

#### Nombre de vies illimité

Jeu en temps : faire le plus de points
Tuer une personne : +1 point