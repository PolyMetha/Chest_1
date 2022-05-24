//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H
#include "menu.h"

void fonctEchiquier(piece pieces[]);

void searchID(char name, int *pieceID, piece pieces[]);
void searchName(int, char*, piece[]);
void generation(piece[], int size, char echiquier[size][size]);
void jeu(int size, char echiquier[size][size], piece[]);

#endif //CHEST_1_ECHEQUIER_H
