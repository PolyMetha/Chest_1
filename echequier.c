//
// Created by reini on 06/05/2022.
//

#include "echequier.h"
#include <stdio.h>
#include "pieces.h"
#include "fonctions.h"
#include "menu.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printEchiquier(int size, char echiquier[size][size]) {
    int x, y, i, j = 0, ascii_A = 65;
    // clear();

    //print lettres echiquier
    wprintf(L"\n\n   ");

    for (i = 0; i < size; i++) {
        wprintf(L"   %c  ", ascii_A + i);
    }
    wprintf(L"\n    ");
    for (i = 0; i < size; i++) {
        wprintf(L"-----+");
    }
    wprintf(L"\n");

    //contenu
    for (x = 0; x < size; x++) {
        wprintf(L"%d ", size - x);
        if (x > 1) {
            wprintf(L" ");
        }

        for (y = 0; y < size; y++) {
            wprintf(L"|");
            if (echiquier[x][y] != ' ') {
                //findSprite(echiquier[x][y]);
                wprintf(L"  %c  ", echiquier[x][y]);
            } else {
                if (x % 2 == 0) {
                    if (y % 2 == 0) {
                        wprintf(L"  _  ");
                    } else {
                        wprintf(L"     ");
                    }
                } else {
                    if (y % 2 == 0) {
                        wprintf(L"     ");
                    } else {
                        wprintf(L"  _  ");
                    }
                }

            }
        }
        wprintf(L"|\n   ");
        for (y = 0; y < size; y++) {
            wprintf(L""
                    "+-----");
        }
        wprintf(L"\n");
    }
    wprintf(L"\n");

}

void searchID(char name, int *pieceID, piece pieces[]) { //Recherche un ID de piece Pour un nom donné
    int i;
    for (i = 0; i <= 11; i++) {
        if (name == pieces[i].name) {
            *pieceID = pieces[i].id;
        }
    }
}

void searchName(int ID, char *name, piece pieces[]) {  //Recherche un nom pour un ID donné
    int i;
    for (i = 0; i <= 11; i++) {
        if (ID == pieces[i].id) {
            *name = pieces[i].name;
        }
    }
}

char searchColor(int ID) {
    if (ID > 5) {
        return 'b';
    } else {
        return 'n';
    }
}

void searchRoi(int size, char echiquier[size][size], int PosRoiN[], int PosRoiB[]) {
    int x, y;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (echiquier[x][y] == 'r') {
                PosRoiN[0] = x;
                PosRoiN[1] = y;
            }
            if (echiquier[x][y] == 'R') {
                PosRoiB[0] = x;
                PosRoiB[1] = y;
            }
        }
    }
}

void generation(piece pieces[], int size, char echiquier[size][size]) {

    //remplissage de l'echiquier
    int x, y, i, idPiece, compteurRoi = 0;
    srand(time(0));
    for (x = 0; x < 2; x++) {       //2 premières lignes
        for (y = 0; y < size; y++) {
            idPiece = rand() % 6;
            for (i = 0; i <= 5; i++) {
                if (idPiece == pieces[i].id) {
                    echiquier[x][y] = pieces[i].name;
                }
            }
        }
    }
    for (x = 2; x < size - 2; x++) {            //lignes intermédiaires
        for (y = 0; y < size; y++) {
            echiquier[x][y] = ' ';
        }
    }
    for (x = size - 2; x < size; x++) {         //2 dernières lignes
        for (y = 0; y < size; y++) {
            idPiece = 6 + rand() % 6;
            for (i = 6; i <= 11; i++) {
                if (idPiece == pieces[i].id) {
                    echiquier[x][y] = pieces[i].name;
                }
            }
        }
    }

    //verifications roi
    for (x = 0; x < 2; x++) {
        if (x == 0) {
            for (y = 0; y < size; y++) {
                if (echiquier[x][y] == 'r') {
                    compteurRoi = compteurRoi + 1;
                }
                if (compteurRoi > 1) {
                    idPiece = rand() % 5;
                    for (i = 0; i < 5; i++) {
                        if (idPiece == pieces[i].id) {
                            echiquier[x][y] = pieces[i].name;
                        }
                    }
                }
            }
            if (compteurRoi == 0) {
                echiquier[x][rand() % size] = 'r';
            }
        }
        if (x == 1) {
            for (y = 0; y < size; y++) {
                if (echiquier[x][y] == 'r') {
                    idPiece = rand() % 5;
                    for (i = 0; i < 5; i++) {
                        if (idPiece == pieces[i].id) {
                            echiquier[x][y] = pieces[i].name;
                        }
                    }
                }
            }
        }
    }
    compteurRoi = 0;
    for (x = size - 2; x < size; x++) {
        if (x == size - 2) {
            for (y = 0; y < size; y++) {
                if (echiquier[x][y] == 'R') {
                    idPiece = 6 + rand() % 5;
                    for (i = 6; i < 11; i++) {
                        if (idPiece == pieces[i].id) {
                            echiquier[x][y] = pieces[i].name;
                        }
                    }
                }
            }
        }
        if (x == size - 1) {
            for (y = 0; y < size; y++) {
                if (echiquier[x][y] == 'R') {
                    compteurRoi = compteurRoi + 1;
                }
                if (compteurRoi > 1) {
                    idPiece = 6 + rand() % 5;
                    for (i = 6; i < 11; i++) {
                        if (idPiece == pieces[i].id) {
                            echiquier[x][y] = pieces[i].name;
                        }
                    }
                }
            }
            if (compteurRoi == 0) {
                echiquier[x][rand() % size] = 'R';
            }
        }
    }
}

int IsEchecB(int size, char Copie[size][size], piece pieces[]) {
    int x, y, a, b, start[2], end[2], ID, BlockID, echecB = 0;

    for (x = 0; x < size; x++) {
        start[0] = x;
        for (y = 0; y < size; y++) {
            start[1] = y;

            if (Copie[x][y] != ' ') {
                //id Piece
                searchID(Copie[x][y], &ID, pieces);
                for (a = 0; a < size; a++) {
                    end[0] = a;
                    for (b = 0; b < size; b++) {
                        end[1] = b;

                        //id piece bloquante
                        if (Copie[a][b] != 0) {
                            searchID(Copie[a][b], &BlockID, pieces);
                        }

                        if (fonctionCoup(size, Copie, start, end, ID, BlockID) == 1) {
                            if (Copie[a][b] == 'R' && ID < 6) {
                                echecB = echecB + 1;
                            }
                        }
                    }
                }
            }

        }
    }
    if (echecB > 0) {
        return 1;
    } else {
        return 0;
    }
}

int IsEchecN(int size, char Copie[size][size], piece pieces[]) {
    int x, y, a, b, start[2], end[2], ID, BlockID, echecN = 0;

    for (x = 0; x < size; x++) {
        start[0] = x;
        for (y = 0; y < size; y++) {
            start[1] = y;

            if (Copie[x][y] != ' ') {
                //id Piece
                searchID(Copie[x][y], &ID, pieces);
                for (a = 0; a < size; a++) {
                    end[0] = a;
                    for (b = 0; b < size; b++) {
                        end[1] = b;

                        //id piece bloquante
                        if (Copie[a][b] != 0) {
                            searchID(Copie[a][b], &BlockID, pieces);
                        }

                        if (fonctionCoup(size, Copie, start, end, ID, BlockID) == 1) {
                            if (Copie[a][b] == 'r' && ID > 5) {
                                echecN = echecN + 1;
                            }
                        }
                    }
                }
            }

        }
    }
    if (echecN > 0) {
        return 1;
    } else {
        return 0;
    }
}


int EchecEtMatN(int size, char echiquier[size][size], piece pieces[], int posRoi[2]) {
    int x, y, a, b, End[2], ID = 5, BlockID, escape = 0, IDpiece, PieceStart[2], PieceEnd[2];
    char temp;

    for (x = 0; x < size; x++) {
        End[0] = x;
        for (y = 0; y < size; y++) {
            End[1] = y;

            if (echiquier[End[0]][End[1]] != ' ') {
                searchID(echiquier[x][y], &BlockID, pieces);
            } else {
                BlockID = -1;
            }


            if (fonctionCoup(size, echiquier, posRoi, End, ID, BlockID) == 1) {
                //sauvegarde la piece dans la position d'arrivée pour reset le coup plus tard
                temp = echiquier[End[0]][End[1]];
                echiquier[End[0]][End[1]] = echiquier[posRoi[0]][posRoi[1]];
                echiquier[posRoi[0]][posRoi[1]] = ' ';
                if (IsEchecN(size, echiquier, pieces) == 0) {
                    escape = escape + 1;
                }
                echiquier[posRoi[0]][posRoi[1]] = 'r';
                echiquier[End[0]][End[1]] = temp;
                temp = ' ';
            }
            //reset variables
            BlockID = -1;
        }
    }

    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (echiquier[x][y] != ' ') {
                searchID(echiquier[x][y], &IDpiece, pieces);
                PieceStart[0] = x;
                PieceStart[1] = y;

                if (IDpiece < 6) {
                    for (a = 0; a < size; a++) {
                        PieceEnd[0] = a;

                        if (echiquier[a][b] != ' ') {
                            searchID(echiquier[a][b], &BlockID, pieces);
                        }

                        for (b = 0; b < size; b++) {
                            PieceEnd[1] = b;
                            if (fonctionCoup(size, echiquier, PieceStart, PieceEnd, IDpiece, BlockID) == 1) {
                                temp = echiquier[PieceEnd[0]][PieceEnd[1]];
                                echiquier[PieceEnd[0]][PieceEnd[1]] = echiquier[PieceStart[0]][PieceStart[1]];
                                echiquier[PieceStart[0]][PieceStart[1]] = ' ';

                                if (IsEchecN(size, echiquier, pieces) == 0) {
                                    escape = escape + 1;
                                    wprintf(L"Une piece peut defendre");
                                }
                                echiquier[PieceStart[0]][PieceStart[1]] = echiquier[PieceEnd[0]][PieceEnd[1]];
                                echiquier[PieceEnd[0]][PieceEnd[1]];
                                temp = ' ';
                            }
                        }
                    }
                }
            }
            BlockID = -1;
        }
    }

    if (escape != 0) {
        return 0;
    } else {
        return 1;
    }
}

int EchecEtMatB(int size, char echiquier[size][size], piece pieces[], int posRoi[2]) {
    int x, y, a, b, End[2], ID = 11, BlockID, escape = 0, IDpiece, PieceStart[2], PieceEnd[2];
    char temp;

    for (x = 0; x < size; x++) {
        End[0] = x;
        for (y = 0; y < size; y++) {
            End[1] = y;

            if (echiquier[End[0]][End[1]] != ' ') {
                searchID(echiquier[x][y], &BlockID, pieces);
            } else {
                BlockID = -1;
            }


            if (fonctionCoup(size, echiquier, posRoi, End, ID, BlockID) == 1) {
                //sauvegarde la piece dans la position d'arrivée pour reset le coup plus tard
                temp = echiquier[End[0]][End[1]];
                echiquier[End[0]][End[1]] = echiquier[posRoi[0]][posRoi[1]];
                echiquier[posRoi[0]][posRoi[1]] = ' ';
                if (IsEchecB(size, echiquier, pieces) == 0) {
                    escape = escape + 1;
                }
                echiquier[posRoi[0]][posRoi[1]] = 'R';
                echiquier[End[0]][End[1]] = temp;
                temp = ' ';
            }
            //reset variables
            BlockID = -1;
        }
    }

    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (echiquier[x][y] != ' ') {
                searchID(echiquier[x][y], &IDpiece, pieces);
                PieceStart[0] = x;
                PieceStart[1] = y;

                if (IDpiece > 5) {
                    for (a = 0; a < size; a++) {
                        PieceEnd[0] = a;

                        if (echiquier[a][b] != ' ') {
                            searchID(echiquier[a][b], &BlockID, pieces);
                        }

                        for (b = 0; b < size; b++) {
                            PieceEnd[1] = b;
                            if (fonctionCoup(size, echiquier, PieceStart, PieceEnd, IDpiece, BlockID) == 1) {
                                temp = echiquier[PieceEnd[0]][PieceEnd[1]];
                                echiquier[PieceEnd[0]][PieceEnd[1]] = echiquier[PieceStart[0]][PieceStart[1]];
                                echiquier[PieceStart[0]][PieceStart[1]] = ' ';

                                if (IsEchecB(size, echiquier, pieces) == 0) {
                                    escape = escape + 1;
                                    wprintf(L"Une piece peut defendre\n");
                                }
                                echiquier[PieceStart[0]][PieceStart[1]] = echiquier[PieceEnd[0]][PieceEnd[1]];
                                echiquier[PieceEnd[0]][PieceEnd[1]];
                                temp = ' ';
                            }
                        }
                    }
                }
            }
            BlockID = -1;
        }
    }


    if (escape != 0) {
        return 0;
    } else {
        return 1;
    }
}

void jeu(int size, char echiquier[size][size], piece pieces[], int QuelTour) {

    int Start[2] = {-1, -1}, End[2] = {-1, -1}, n = 0, m = 0, i, coupFait = 0, SaveCoup[4],
            PieceSelectID = -1, PieceBlockID = -1, PiecePriseID = -1, nextCoup = 0, PosRoiN[2], PosRoiB[2], stock = 0;

    char lettre, PiecePriseName, color,
            Copie[size][size];

    //Selection de la piece a deplacer
    while (nextCoup == 0) {

        searchRoi(size, echiquier, PosRoiN, PosRoiB);

        //copie l'échiquier
        for (n = 0; n < size; n++) {
            for (m = 0; m < size; m++) {
                Copie[n][m] = echiquier[n][m];
            }
        }


        if (QuelTour == 0) {
            if (IsEchecB(size, Copie, pieces) == 1) {

                if (EchecEtMatB(size, Copie, pieces, PosRoiB) == 0) {
                    printEchiquier(size, echiquier);
                    wprintf(L"\nEchec pour les blancs !\n");
                    while (IsEchecB(size, echiquier, pieces) == 1) {

                        for (n = 0; n < size; n++) {
                            for (m = 0; m < size; m++) {
                                Copie[n][m] = echiquier[n][m];
                            }
                        }
                        stock = JeuBlanc(size, Copie, pieces, SaveCoup);
                        if (stock == 2) {
                            menu();
                        }
                        //jouer les blancs dans la copie
                        JeuBlanc(size, Copie, pieces, SaveCoup);
                        if (IsEchecB(size, Copie, pieces) != 1) {
                            echiquier[SaveCoup[2]][SaveCoup[3]] = echiquier[SaveCoup[0]][SaveCoup[1]];
                            echiquier[SaveCoup[0]][SaveCoup[1]] = ' ';
                            //recopie le changement dans la copie
                            Copie[SaveCoup[2]][SaveCoup[3]] = Copie[SaveCoup[0]][SaveCoup[1]];
                            Copie[SaveCoup[0]][SaveCoup[1]] = ' ';
                            QuelTour = 1;

                            printEchiquier(size, echiquier);
                        }
                        //reset ce qui doit l'etre
                    }
                } else {
                    //partie finie, vainqueur Noir
                    wprintf(L"Les noirs gagnent");
                    menu();
                }
            } else {
                //si on est pas en echec, on verifie que notre coup ne nous met pas nous meme en echec

                printEchiquier(size, echiquier);

                do {
                    //jouer les blancs dans la copie
                    for (n = 0; n < size; n++) {
                        for (m = 0; m < size; m++) {
                            Copie[n][m] = echiquier[n][m];
                        }
                    }
                    JeuBlanc(size, Copie, pieces, SaveCoup);
                    if (IsEchecB(size, Copie, pieces) != 1) {
                        echiquier[SaveCoup[2]][SaveCoup[3]] = echiquier[SaveCoup[0]][SaveCoup[1]];
                        echiquier[SaveCoup[0]][SaveCoup[1]] = ' ';
                        //recopie le changement dans la copie
                        Copie[SaveCoup[2]][SaveCoup[3]] = Copie[SaveCoup[0]][SaveCoup[1]];
                        Copie[SaveCoup[0]][SaveCoup[1]] = ' ';


                        QuelTour = 1;
                        coupFait = 1;


                        printEchiquier(size, echiquier);
                    } else {
                        wprintf(L"Ce coup vous mettrait en echec");
                        coupFait == 0;
                    }
                } while (IsEchecB(size, echiquier, pieces) == 1 || coupFait == 0);
                //reset ce qui doit l'etre
            }
        }

        coupFait = 0;

        if (QuelTour != 0) {
            if (IsEchecN(size, echiquier, pieces) == 1) {

                if (EchecEtMatN(size, Copie, pieces, PosRoiN) == 0) {
                    for (n = 0; n < size; n++) {
                        for (m = 0; m < size; m++) {
                            Copie[n][m] = echiquier[n][m];
                        }

                    }
                    printEchiquier(size, echiquier);
                    wprintf(L"\nEchec pour les noirs !\n");
                    while (IsEchecN(size, Copie, pieces) == 1) {
                        //jouer les noirs dans la copie
                        JeuNoir(size, Copie, pieces, SaveCoup);
                        if (IsEchecN(size, Copie, pieces) != 1) {
                            echiquier[SaveCoup[2]][SaveCoup[3]] = echiquier[SaveCoup[0]][SaveCoup[1]];
                            echiquier[SaveCoup[0]][SaveCoup[1]] = ' ';
                            //recopie le changement dans la copie
                            Copie[SaveCoup[2]][SaveCoup[3]] = Copie[SaveCoup[0]][SaveCoup[1]];
                            Copie[SaveCoup[0]][SaveCoup[1]] = ' ';
                            QuelTour = 0;
                        }
                        //reset ce qui doit l'etre
                        printEchiquier(size, echiquier);
                    }
                } else {
                    wprintf(L"Les Blancs Gagnent");
                    menu();
                }
            } else {

                wprintf(L"Pas echec noir");

                printEchiquier(size, echiquier);
                do {
                    for (n = 0; n < size; n++) {
                        for (m = 0; m < size; m++) {
                            Copie[n][m] = echiquier[n][m];
                        }
                    }
                    //jouer les noirs dans la copie
                    JeuNoir(size, Copie, pieces, SaveCoup);
                    if (IsEchecN(size, Copie, pieces) != 1) {
                        echiquier[SaveCoup[2]][SaveCoup[3]] = echiquier[SaveCoup[0]][SaveCoup[1]];
                        echiquier[SaveCoup[0]][SaveCoup[1]] = ' ';
                        //recopie le changement dans la copie
                        Copie[SaveCoup[2]][SaveCoup[3]] = Copie[SaveCoup[0]][SaveCoup[1]];
                        Copie[SaveCoup[0]][SaveCoup[1]] = ' ';

                        QuelTour = 0;
                        coupFait = 1;

                    }
                        //reset ce qui doit l'etre
                    else {
                        wprintf(L"Ce coup vous mettrait en echec");
                        coupFait = 0;
                    }
                } while (IsEchecN(size, echiquier, pieces) == 1 || coupFait == 0);

                printEchiquier(size, echiquier);
            }
        }


        wprintf(L"\nPour aller au prochain coup, entrez 0, pour quitter, entrez 2");
        fflush(stdin);
        scanf("%d", &nextCoup);
    }
}


void fonctEchiquier(piece pieces[]) {

    int size = 0, x, y;
    //input de la taille de l'échequier
    wprintf(L"Entrez la taille de l'echiquier de 6x6 à 12x12\n");
    scanf("%d", &size);
    while (size < 6 || size > 12) {
        wprintf(L"La valeur doit etre comprise entre 6 et 12");
        fflush(stdin);
        scanf("%d", &size);
    }
    char echiquier[size][size];
    generation(pieces, size, echiquier);

    jeu(size, echiquier, pieces, 0);
    /*
     * Cette partie de ce programme sert a enregistrer l'échiquier dans un fichier, puis la taille de celui-ci dans un
     * autre fichier. L'enregistrement de l'échiquier se fait caractère par caractère et le fichier "size" ne contiens
     * que la taille. Les fichiers sont fermés après utilisation.
     */
    FILE *f = fopen("Save.txt",
                    "w"); //Ouvre le fichier de sauvegarde (ecriture/lecture + suppression de ce qui a été écrit au paravant)
    if (f != NULL) { //vérification de l'ouverture
        fprintf(f, "%d\n", size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fprintf(f, "%c", echiquier[i][j]);
            }
        }
        fprintf(f, "\n0");
        fclose(f);
        menu();
    }
}