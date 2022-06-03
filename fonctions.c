//
// Created by reini on 06/05/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pieces.h"
#include "echequier.h"

void LetterToInt(char lettre, int * select){
    switch(lettre){
        case 'A':
            *select = 0;
            break;
        case 'B':
            *select = 1;
            break;
        case 'C':
            *select = 2;
            break;
        case 'D':
            *select = 3;
            break;
        case 'E':
            *select = 4;
            break;
        case 'F':
            *select = 5;
            break;
        case 'G':
            *select = 6;
            break;
        case 'H':
            *select = 7;
            break;
        case 'I':
            *select = 8;
            break;
        case 'J':
            *select = 9;
            break;
        case 'K':
            *select = 10;
            break;
        case 'L':
            *select = 11;
            break;
        default:
            break;
    }
}

int pieceBlanche(int pieceID){
    if(pieceID>=6){
        return 1;
    }
    else{
        return 0;
    }
}

void input(int Case[2], int size){
    char lettre='0';
    wprintf(L"Lettre de la colonne : ");
    while (lettre < 'A' || lettre >= 'A' + size) {
        scanf("%c", &lettre);
    }
    LetterToInt(lettre, &Case[1]);
    lettre = ' ';

    wprintf(L"Numero de la ligne : ");
    while (Case[0] < 0 || Case[0] >= size) {
        scanf(" %d", &Case[0]);
        //le 1 affiché correspond au 0 echiquier
        Case[0] = Case[0] - 1;
    }
}

int fonctionCoup(int size, char echiquier[size][size], int CaseDepart[], int CaseArrivee[], int PieceID, int PieceBlockID, int * PiecePriseID){
    //lance la bonne fonction pour la piece selectionnée
    switch(PieceID){
        case 0: //pion Noir
            return dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID , PieceBlockID, &*PiecePriseID);
            break;
        case 1: //Cavalier Noir
            return dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);

            break;
        case 2:
            return dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 3:
            return dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);

            break;
        case 4:
            return dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 5:
            return dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 6:
            return dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 7:
            return dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 8:
            return dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 9:
            return dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 10:
            return dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        case 11:
            return dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
            break;
        default:
            return 0;
            break;
    }
}