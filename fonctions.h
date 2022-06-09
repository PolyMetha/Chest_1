//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_FONCTIONS_H
#define CHEST_1_FONCTIONS_H
#include "menu.h"

void LetterToInt(char, int*);

int pieceBlanche(int);

int input(int[2], int size, piece[], char echiquier[size][size], char PiecesPrisesB[2 * size], char PiecesPriseN[2 * size]);

int fonctionCoup(int size, char[size][size], int[], int[], int, int);

void JeuBlanc(int size, char[size][size], piece[], int[4]);
void JeuNoir(int size, char[size][size], piece[], int[4]);

void verifEchec(int size, char[size][size],char[size][size], piece[]);

#endif //CHEST_1_FONCTIONS_H