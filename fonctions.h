//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_FONCTIONS_H
#define CHEST_1_FONCTIONS_H
#include "menu.h"

void LetterToInt(char, int*);

int pieceBlanche(int);

void input(int[2], int);

int fonctionCoup(int size, char[size][size], char[size][size], int[], int[], int, int, int*);

void verifEchec(int size, char[size][size],char[size][size], piece[]);

#endif //CHEST_1_FONCTIONS_H