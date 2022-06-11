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
#include <string.h>

void clear() {
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void LetterToInt(char lettre, int *select) {
    switch (lettre) {
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

int pieceBlanche(int pieceID) {
    if (pieceID >= 6) {
        return 1;
    } else {
        return 0;
    }
}

int input(int Case[2], int size, piece pieces[], char echiquier[size][size]) {
    char lettre = '0';

    char reponse[3] = "oui";
    int reponseboolean = 0;
    int stock = 0;
    wprintf(L"Lettre de la colonne : ");
    while (lettre < 'A' || lettre >= 'A' + size && lettre == 'X' && lettre == 'S') {
        scanf("%c", &lettre);
    }
    if (lettre == 'X') {
        wprintf(L"vous êtes sur oui ou non?\n");
        scanf("%s", &reponse);
        strlwr(reponse);
        reponseboolean = strcmp(reponse, "oui");
        if (reponseboolean == 0) {
            wprintf(L"A bientot\n");
            return 2;
        }

    } else if (lettre == 'S') {
        stock = savefile(pieces, size, echiquier, 1);
        if (stock == 2) {
            return 2;
        }else{return 0;}

    } else {
        LetterToInt(lettre, &Case[1]);
        lettre = ' ';
        wprintf(L"Numero de la ligne : ");
        while (Case[0] < 0 || Case[0] >= size) {
            scanf(" %d", &Case[0]);
            //le 1 affiché correspond au 0 echiquier
            Case[0] = size - Case[0];
        }

    }
}

int fonctionCoup(int size, char echiquier[size][size], int CaseDepart[], int CaseArrivee[], int PieceID, int PieceBlockID) {
    //lance la bonne fonction pour la piece selectionnée
    switch (PieceID) {
        case 0: //pion Noir
            return dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 1: //Cavalier Noir
            return dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);

            break;
        case 2:
            return dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 3:
            return dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);

            break;
        case 4:
            return dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 5:
            return dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 6:
            return dPion(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 7:
            return dCavalier(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 8:
            return dFou(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 9:
            return dTour(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 10:
            return dReine(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        case 11:
            return dRoi(size, echiquier, CaseDepart, CaseArrivee, PieceID, PieceBlockID);
            break;
        default:
            return 0;
            break;
    }
}

int JeuBlanc(int size, char echiquier[size][size], piece pieces[], int SaveCoup[4]) {
    int Start[2], End[2], PieceSelectID, PieceBlockID, i, coupFait, stock = 0;

    wprintf(L"Tour des blancs\n");

    do {
        Start[0] = -1;
        Start[1] = -1;
        End[0] = -1;
        End[1] = -1;
        PieceSelectID = -1, PieceBlockID = -1;

        input(Start, size, pieces, echiquier);

        wprintf(L"\n");

        //verif si c'est une piece blanche, si case vide ou piece noire, choisir autre piece
        if (echiquier[Start[0]][Start[1]] != ' ') {
            searchID(echiquier[Start[0]][Start[1]], &PieceSelectID, pieces);
            if (PieceSelectID > 5) {
                wprintf(L"Piece selectionee : ");
                for (i = 0; i < strlen(pieces[PieceSelectID].namePiece); i++) {
                    wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
                }
                wprintf(L"\n");

                //Entrée de la case d'arrivée de la piece
                wprintf(L"Ou voulez vous vous déplacer ?\n");
                input(End, size, pieces, echiquier);

                //Si l'arrivée n'est pas vide, on prend l'ID de la piece bloquante
                if (echiquier[End[0]][End[1]] != ' ') {
                    searchID(echiquier[End[0]][End[1]], &PieceBlockID, pieces);
                }


                /* FonctionCoup redirige vers une fonction propre a chaque piece qui verifie si le deplacement est possible
                elle prend en parametre la lettre de la piece, la taille de l'echiquier, la case de départ, d'arrivée
                l'id de la piece de départ, l'id de la potentille piece prise */
                if(fonctionCoup(size, echiquier, Start, End, PieceSelectID, PieceBlockID) == 1){
                    echiquier[End[0]][End[1]] = echiquier[Start[0]][Start[1]];
                    echiquier[Start[0]][Start[1]] = ' ';

                    SaveCoup[0]=Start[0];
                    SaveCoup[1]=Start[1];
                    SaveCoup[2]=End[0];
                    SaveCoup[3]=End[1];

                    coupFait=0;
                }
                else{
                    //si la fonction retourne 0, cela veut dire que le coup n'a pas pu etre fait, on recommence la boucle
                    wprintf(L"Coup impossible");

        stock = input(Start, size, pieces, echiquier);

        if (stock == 2) {
            return 2;
        }else{
            wprintf(L"\n");

            //verif si c'est une piece blanche, si case vide ou piece noire, choisir autre piece
            if (echiquier[Start[0]][Start[1]] != ' ') {
                searchID(echiquier[Start[0]][Start[1]], &PieceSelectID, pieces);
                if (PieceSelectID > 5) {
                    wprintf(L"Piece selectionee : ");
                    for (i = 0; i < strlen(pieces[PieceSelectID].namePiece); i++) {
                        wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
                    }
                    wprintf(L"\n");

                    //Entrée de la case d'arrivée de la piece
                    wprintf(L"Ou voulez vous vous déplacer ?\n");
                    stock = input(End, size, pieces, echiquier);
                    if (stock == 2) {
                        return 2;
                    }

                    //Si l'arrivée n'est pas vide, on prend l'ID de la piece bloquante
                    if (echiquier[End[0]][End[1]] != ' ') {
                        searchID(echiquier[End[0]][End[1]], &PieceBlockID, pieces);
                    }


                    /* FonctionCoup redirige vers une fonction propre a chaque piece qui verifie si le deplacement est possible
                    elle prend en parametre la lettre de la piece, la taille de l'echiquier, la case de départ, d'arrivée
                    l'id de la piece de départ, l'id de la potentille piece prise */
                    if (fonctionCoup(size, echiquier, Start, End, PieceSelectID, PieceBlockID) == 1) {
                        echiquier[End[0]][End[1]] = echiquier[Start[0]][Start[1]];
                        echiquier[Start[0]][Start[1]] = ' ';

                        SaveCoup[0] = Start[0];
                        SaveCoup[1] = Start[1];
                        SaveCoup[2] = End[0];
                        SaveCoup[3] = End[1];

                        coupFait = 0;
                    } else {
                        //si la fonction retourne 0, cela veut dire que le coup n'a pas pu etre fait, on recommence la boucle
                        wprintf(L"Coup impossible");
                        coupFait = 1;
                    }

                    //On cherche la nom de la piece éventuellement prise lors du déplacement
                    /*
                    if (PiecePriseID >= 0 && PiecePriseID <= 5) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesN[n] = PiecePriseName;
                        n = n + 1;
                    }
                    if (PiecePriseID >= 6 && PiecePriseID <= 11) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesB[m] = PiecePriseName;
                        m = n + 1;
                    }
                    */
                    //reset des variables
                } else {
                    wprintf(L"\nPiece invalide, choisir une autre piece");
                    coupFait = 1;
                }

        }
    }while (coupFait == 1);
    return 0;
}

int JeuNoir(int size, char echiquier[size][size], piece pieces[], int SaveCoup[4]) {
    int Start[2], End[2], PieceSelectID, PieceBlockID, i, stock = 0,coupFait;
    wprintf(L"Tour des Noirs\n");

    do {

        PieceSelectID = -1, PieceBlockID = -1;

        Start[0]=-1;
        Start[1]=-1;
        End[0]=-1;
        End[1]=-1;

        stock = input(Start, size, pieces, echiquier);

        if(stock == 2){
            return 2;
        }

        wprintf(L"\n");


        //verif si c'est une piece noire, si case vide ou piece blanche, choisir autre piece
        if (echiquier[Start[0]][Start[1]] != ' ') {
            searchID(echiquier[Start[0]][Start[1]], &PieceSelectID, pieces);
            if (PieceSelectID < 6) {
                wprintf(L"Piece selectionee : ");
                for (i = 0; i < strlen(pieces[PieceSelectID].namePiece); i++) {
                    wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
                }
                wprintf(L"\n");

                //Entrée de la case d'arrivée de la piece
                wprintf(L"Ou voulez vous vous déplacer ?\n");
                input(End, size, pieces, echiquier);

                //Si l'arrivée n'est pas vide, on prend l'ID de la piece bloquante
                if (echiquier[End[0]][End[1]] != ' ') {
                    searchID(echiquier[End[0]][End[1]], &PieceBlockID, pieces);
                }


                    /* FonctionCoup redirige vers une fonction propre a chaque piece qui verifie si le deplacement est possible
                    elle prend en parametre la lettre de la piece, la taille de l'echiquier, la case de départ, d'arrivée
                    l'id de la piece de départ, l'id de la potentille piece prise */
                    if (fonctionCoup(size, echiquier, Start, End, PieceSelectID, PieceBlockID) == 1) {
                        echiquier[End[0]][End[1]] = echiquier[Start[0]][Start[1]];
                        echiquier[Start[0]][Start[1]] = ' ';
                        coupFait = 0;

                        SaveCoup[0] = Start[0];
                        SaveCoup[1] = Start[1];
                        SaveCoup[2] = End[0];
                        SaveCoup[3] = End[1];

                    } else {
                        //si la fonction retourne 0, cela veut dire que le coup n'a pas pu etre fait, on recommence la boucle
                        wprintf(L"Coup impossible");
                        coupFait = 1;
                    }

                    //On cherche la nom de la piece éventuellement prise lors du déplacement
                    /*
                    if (PiecePriseID >= 0 && PiecePriseID <= 5) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesN[n] = PiecePriseName;
                        n = n + 1;
                    }
                    if (PiecePriseID >= 6 && PiecePriseID <= 11) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesB[m] = PiecePriseName;
                        m = n + 1;
                    }
                    */
                    //reset des variables
                } else {
                    wprintf(L"\nPiece invalide, choisir une autre piece");
                    coupFait = 1;
                    return 0;
                }
            }
        


    } while (coupFait == 1);


                //On cherche la nom de la piece éventuellement prise lors du déplacement
                /*
                if (PiecePriseID >= 0 && PiecePriseID <= 5) {
                    searchName(PiecePriseID, &PiecePriseName, pieces);
                    findSprite(PiecePriseName);
                    PiecesPrisesN[n] = PiecePriseName;
                    n = n + 1;
                }
                if (PiecePriseID >= 6 && PiecePriseID <= 11) {
                    searchName(PiecePriseID, &PiecePriseName, pieces);
                    findSprite(PiecePriseName);
                    PiecesPrisesB[m] = PiecePriseName;
                    m = n + 1;
                }
                */
                //reset des variables
            }
        }
        else{
            wprintf(L"\nPiece invalide, choisir une autre piece");
            coupFait=1;
        }
    }
    while(coupFait==1);
}