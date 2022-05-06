//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H

void echequier();

struct piece{
    int id;
    char name;
    int dx[100];
    int dy[100];
    char spriteB[4];
    char spriteN[4];
};
typedef struct piece piece;

#endif //CHEST_1_ECHEQUIER_H
