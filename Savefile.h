//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#ifndef CHEST_1_SAVEFILE_H
#define CHEST_1_SAVEFILE_H
#include "menu.h"
/*
 * Savefile permet d'écrire toute les informations utiles au lancement d'une partie dans un fichier nommé 'Save.txt'. Elle prend pour paramètre la structure piece
 * la taille (pouvant aller de 6 à 12), l'echiquier (sa taille pouvant aller de 6 à 12 et ayant toutes pieces du jeu en cours)i et tourdujoueur(pouvant allez de 0 à 1)
 * ce paramètre renseigne là quel tour la partie se situe (tour noir ou blanc).
 */
int savefile(piece[],int taille, char echiquier[taille][taille],int tourdujoueur);
/*
 * Readfile permet de lire le fichier 'Save.txt', elle lit la taille de l'échequier de la partie précédente, puis créé un tableau nommé save_echiquier de la même taille que l'échiquier de la partie précédente et
 * lit le tour du joueur pour savoir si c'était au blanc ou au noir de jouer, ensuite elle appelle la fonction jeu pour lancer la partie. Elle prend en paramètre la strucure piece pour pouvoir faire fonctionner la fonction
 * jeu
 */
void readfile(piece[]);
#endif //CHEST_1_SAVEFILE_H
