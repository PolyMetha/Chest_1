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

void verifEchec(int size, char echiquier[size][size] , char Copie[size][size], piece pieces[]){
    /**
     * La fonction met :
     * des 0 pour les cases dangeureuses pour les blancs
     * des 1 pour les cases dangeureuses pour les noirs
     * des 2 pour les cases dangeureuses pour les deux
     * rien si la case est safe
     */

    int x, y, i, j;
    int pieceID, pieceBlockID=-1, piecePriseID=-1;
    int Depart[2]={0, 0},coup[2]={0, 0};
    char piecesPrisesB[1], piecesPrisesN[1];

    for(x=0; x < size; x++){
        for(y=0; y < size; y++){
            //on parcoure l'echiquier et calcule tous les mouvements possibles pour cette piece
            Depart[0] = x;
            Depart[1] = y;

            if(echiquier[x][y]!=' '){
                searchID(echiquier[x][y], &pieceID, pieces);
            }

            for(i=0; i<size; i++){
                coup[0]=i;
                for(j=0; j<size; j++){
                    coup[1]=j;

                    if (echiquier[coup[0]][coup[1]] != ' ') {
                        searchID(echiquier[coup[0]][coup[1]], &pieceBlockID, pieces);
                    }

                    if(fonctionCoup(size, echiquier, Depart, coup, pieceID, pieceBlockID, &piecePriseID)){
                        //si piece blanche
                        if(pieceID > 5){
                            if(Copie[coup[0]][coup[1]]==' ' && pieceBlockID==-1){
                                Copie[coup[0]][coup[1]]='0';
                            }
                            else if(Copie[coup[0]][coup[1]]=='1' && pieceBlockID==-1){
                                Copie[coup[0]][coup[1]]='2';
                            }
                            else if(Copie[coup[0]][coup[1]]==' ' && pieceBlockID<6){
                                Copie[coup[0]][coup[1]]='3';
                            }
                        }

                        if(pieceID < 6){
                            if(Copie[coup[0]][coup[1]]==' ' && pieceBlockID==-1){
                                Copie[coup[0]][coup[1]]='1';
                            }
                            else if(Copie[coup[0]][coup[1]]=='0' && pieceBlockID==-1){
                                Copie[coup[0]][coup[1]]='2';
                            }
                            else if(Copie[coup[0]][coup[1]]==' ' && pieceBlockID>5){
                                Copie[coup[0]][coup[1]]='4';
                            }
                        }
                    }

                    pieceBlockID=-1;
                    piecePriseID=-1;
                }
            }
            printEchiquier(size, Copie, piecesPrisesB, piecesPrisesN);
        }
    }
}