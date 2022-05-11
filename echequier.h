//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H

void fonctEchiquier();

struct piece{
    int id;
    char name;
    char namePiece[20];
};
typedef struct piece piece;

void searchID(char name, int *pieceID, piece pieces[]);
void searchName(int, char*, piece[]);
#endif //CHEST_1_ECHEQUIER_H
