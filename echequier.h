//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H

void fonctEchiquier();

struct piece{
    int id;
    char name;
    int dx[100];
    int dy[100];
    char namePiece[20];
};
typedef struct piece piece;


#endif //CHEST_1_ECHEQUIER_H
