//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H
#include "menu.h"

void fonctEchiquier();
void printEchiquier(int size, char echiquier[size][size]);
void searchRoi(int size, char[size][size], int[], int[]);
void generation(piece[], int size, char echiquier[size][size]);
int IsEchecB(int size, char[size][size], piece[]);
int IsEchecN(int size, char[size][size], piece[]);
int EchecEtMatN(int size, char[size][size], piece[], int[2]);
int EchecEtMatB(int size, char[size][size], piece[], int[2]);
void searchID(char name, int *pieceID, piece[]);
int jeu(int size, char echiquier[size][size], piece[], int);

#endif //CHEST_1_ECHEQUIER_H
