//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_PIECES_H
#define CHEST_1_PIECES_H

void findSprite(char);

int dPion(int size, char echiquier[size][size], int[], int[], int,int, int*);
int dCavalier(int size, char echiquier[size][size], int[], int[], int,int, int*);
int dFou(int size, char echiquier[size][size], int[], int[], int,int, int*);
int dTour(int size, char echiquier[size][size], int[], int[], int,int, int*);
int dReine(int size, char echiquier[size][size], int[], int[], int,int, int*);
int dRoi(int size, char echiquier[size][size], int[], int[], int,int, int*);

#endif //CHEST_1_PIECES_H
