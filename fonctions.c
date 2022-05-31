//
// Created by reini on 06/05/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pieces.h"

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

void fonctionCoup(int size, char echiquier[size][size], int CaseDepart[], int CaseArrivee[], int PieceID, int PieceBlockID, int * PiecePriseID, int *coupFait){
    //lance la bonne fonction pour la piece selectionnée
    switch(PieceID){
        case 0: //pion Noir
            dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID , PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 1: //Cavalier Noir
            dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 2:
            dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 3:
            dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 4:
            dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 5:
            dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 6:
            dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 7:
            dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 8:
            dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 9:
            dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 10:
            dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        case 11:
            dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID, &*coupFait);
            break;
        default:
            break;
    }
}

void verifEchec(){

};