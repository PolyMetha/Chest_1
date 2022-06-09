//
// Created by reini on 06/05/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "pieces.h"
#include "echequier.h"
#include "Savefile.h"

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

int input(int Case[2], int size,piece pieces[],char echiquier[size][size],char Blancheprise[2*size],char NoirePrise[2*size]){
    char lettre='0';
    char reponse[3] = "oui";
    int reponseboolean = 0;
    wprintf(L"Lettre de la colonne : ");
    while (lettre < 'A' || lettre >= 'A' + size && lettre == 'X' && lettre == 'S') {
        scanf("%c", &lettre);
    }
    if(lettre == 'X'){
        wprintf(L"vous êtes sur oui ou non?\n");
        scanf("%s",&reponse);
        strlwr(reponse);
        reponseboolean = strcmp(reponse, "oui");
        if(reponseboolean == 0){
            wprintf(L"A bientot\n");
            return 2;
        }
    }else if(lettre == 'S'){
        savefile(pieces,size,echiquier[size][size]);
    }
    else{
    LetterToInt(lettre, &Case[1]);
    lettre = ' ';
    wprintf(L"Numero de la ligne : ");
    while (Case[0] < 0 || Case[0] >= size) {
        scanf(" %d", &Case[0]);
        //le 1 affiché correspond au 0 echiquier
        Case[0] = Case[0] - 1;
        return 5;
    }
    }
}

int fonctionCoup(int size, char echiquier[size][size], char CopieEchiquier[size][size], int CaseDepart[], int CaseArrivee[], int PieceID, int PieceBlockID, int * PiecePriseID){
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
            return dRoi(size, echiquier, CopieEchiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
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
            return dRoi(size, echiquier, CopieEchiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID, &*PiecePriseID);
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
     * des 3 si il y a un danger pour les blancs si une autre piece blanche est prise
     * des 4 si il y a un danger pour les noirs si une autre piece noire est prise
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

                    if(fonctionCoup(size, echiquier, Copie, Depart, coup, pieceID, pieceBlockID, &piecePriseID)==1){
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
            //printEchiquier(size, Copie, piecesPrisesB, piecesPrisesN);
        }
    }
}