//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_FONCTIONS_H
#define CHEST_1_FONCTIONS_H
#include "menu.h"
/*
 * La fonction clear permet supprimer tout ce qui a été affiché a l'écran lors des manipulations précédentes. Elle ne prend pas de paramètres et ne renvoie aucune information.
 */
void clear();

void LetterToInt(char, int*);

int pieceBlanche(int);

int input(int[2], int size, piece[], char echiquier[size][size]);

int fonctionCoup(int size, char[size][size], int[], int[], int, int);

int JeuBlanc(int size, char[size][size], piece[], int[4]);
int JeuNoir(int size, char[size][size], piece[], int[4]);

void verifEchec(int size, char[size][size],char[size][size], piece[]);

#endif //CHEST_1_FONCTIONS_H