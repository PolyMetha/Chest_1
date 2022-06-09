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


void printEchiquier(int size, char echiquier[size][size]){
    int x, y, i,j=0, ascii_A=65;

    wprintf(L"\n\n");

    //print lettres echiquier
    wprintf(L"\n\n   ");
    for(i=0; i<size; i++){
        wprintf(L"   %c  ", ascii_A+i);
    }
    wprintf(L"\n    ");
    for(i=0; i<size; i++){
        wprintf(L"-----+", ascii_A+i);
    }
    wprintf(L"\n");

    //contenu
    for(x=0; x<size; x++){
        wprintf(L"%d ", size-x);
        if(x>1){
            wprintf(L" ");
        }

        for(y=0; y<size; y++){
            wprintf(L"|");
            if(echiquier[x][y] != ' '){
                //findSprite(echiquier[x][y]);
                wprintf(L"  %c  ", echiquier[x][y]);
            }
            else{
                if(x%2==0){
                    if(y%2==0){
                        wprintf(L"  _  ");
                    }
                    else{
                        wprintf(L"     ");
                    }
                }
                else{
                    if(y%2==0){
                        wprintf(L"     ");
                    }
                    else{
                        wprintf(L"  _  ");
                    }
                }

            }
        }
        wprintf(L"|\n   ");
        for(y=0; y<size; y++){
            wprintf(L""
                    "+-----");
        }
        wprintf(L"\n");
    }
    wprintf(L"\n");
}

void searchID(char name, int * pieceID , piece pieces[]){ //Recherche un ID de piece Pour un nom donné
    int i;
    for(i=0; i<=11; i++){
        if(name==pieces[i].name){
            *pieceID = pieces[i].id;
        }
    }
}

void searchName(int ID, char* name, piece pieces[]){  //Recherche un nom pour un ID donné
    int i;
    for(i=0; i<=11; i++){
        if(ID==pieces[i].id){
            *name = pieces[i].name;
        }
    }
}

char searchColor(int ID){
    if(ID>5){
        return 'b';
    }
    else{
        return 'n';
    }
}

void searchRoi(int size, char echiquier[size][size], int PosRoiN[], int PosRoiB[]){
    int x, y;
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            if(echiquier[x][y]=='r'){
                PosRoiN[0]=x;
                PosRoiN[1]=y;
            }
            if(echiquier[x][y]=='R'){
                PosRoiB[0]=x;
                PosRoiB[1]=y;
            }
        }
    }
}

void generation(piece pieces[], int size, char echiquier[size][size]){

    //remplissage de l'echiquier
    int x, y, i , idPiece, compteurRoi=0;
    srand(time(0));
    for(x=0; x < 2; x++){       //2 premières lignes
        for(y=0; y < size; y++){
            idPiece = rand()%6;
            for(i=0;i<=5;i++){
                if(idPiece == pieces[i].id){
                    echiquier[x][y]=pieces[i].name;
                }
            }
        }
    }
    for(x=2; x<size-2; x++){            //lignes intermédiaires
        for(y=0; y<size; y++){
            echiquier[x][y] = ' ';
        }
    }
    for(x=size-2; x<size; x++){         //2 dernières lignes
        for(y=0; y<size; y++){
            idPiece = 6 + rand()%6;
            for(i=6;i<=11;i++){
                if(idPiece == pieces[i].id){
                    echiquier[x][y]=pieces[i].name;
                }
            }
        }
    }

    //verifications roi
    for(x=0; x<2; x++){
        if(x==0){
            for(y=0; y<size; y++){
                if(echiquier[x][y] == 'r'){
                    compteurRoi = compteurRoi+1;
                }
                if(compteurRoi>1){
                    idPiece = rand()%5;
                    for(i=0;i<5;i++){
                        if(idPiece == pieces[i].id){
                            echiquier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
            if(compteurRoi==0){
                echiquier[x][rand() %size]='r';
            }
        }
        if(x==1){
            for(y=0; y<size; y++){
                if(echiquier[x][y] == 'r'){
                    idPiece = rand()%5;
                    for(i=0;i<5;i++){
                        if(idPiece == pieces[i].id){
                            echiquier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
        }
    }
    compteurRoi = 0;
    for(x=size-2; x<size; x++){
        if(x==size-2){
            for(y=0; y<size; y++){
                if(echiquier[x][y] == 'R'){
                    idPiece = 6 + rand()%5;
                    for(i=6;i<11;i++){
                        if(idPiece == pieces[i].id){
                            echiquier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
        }
        if(x==size-1){
            for(y=0; y<size; y++){
                if(echiquier[x][y] == 'R'){
                    compteurRoi = compteurRoi+1;
                }
                if(compteurRoi>1){
                    idPiece = 6 + rand()%5;
                    for(i=6;i<11;i++){
                        if(idPiece == pieces[i].id){
                            echiquier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
            if(compteurRoi==0){
                echiquier[x][rand() %size]='R';
            }
        }
    }
}

int IsEchecB(int size, char Copie[size][size], piece pieces[]){
    int x, y, a, b, start[2], end[2], ID, BlockID, echecB=0;

    for(x=0; x<size; x++){
        start[0]=x;
        for(y=0; y<size; y++){
            start[1]=y;
            
            if(Copie[x][y]!=' '){
                //id Piece
                searchID(Copie[x][y], &ID, pieces);
                for(a=0; a<size;a++){
                    end[0]=a;
                    for(b=0; b<size; b++){
                        end[1]=b;

                        //id piece bloquante
                        if(Copie[a][b]!=0){
                            searchID(Copie[a][b], &BlockID, pieces);
                        }

                        if(fonctionCoup(size, Copie, start, end, ID, BlockID)==1){
                            if(Copie[a][b]=='R' && ID<6){
                                echecB = echecB + 1;
                            }
                        }
                    }
                }
            }

        }
    }
    if(echecB>0){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEchecN(int size, char Copie[size][size], piece pieces[]){
    int x, y, a, b, start[2], end[2], ID, BlockID, echecN=0;

    for(x=0; x<size; x++){
        start[0]=x;
        for(y=0; y<size; y++){
            start[1]=y;

            if(Copie[x][y]!=' '){
                //id Piece
                searchID(Copie[x][y], &ID, pieces);
                for(a=0; a<size;a++){
                    end[0]=a;
                    for(b=0; b<size; b++){
                        end[1]=b;

                        //id piece bloquante
                        if(Copie[a][b]!=0){
                            searchID(Copie[a][b], &BlockID, pieces);
                        }

                        if(fonctionCoup(size, Copie, start, end, ID, BlockID)==1){
                            if(Copie[a][b]=='r' && ID>5){
                                echecN = echecN + 1;
                            }
                        }
                    }
                }
            }

        }
    }
    if(echecN > 0){
        return 1;
    }
    else{
        return 0;
    }
}

void jeu(int size, char echiquier[size][size], piece pieces[]) {
    int Start[2] = {-1, -1}, End[2] = {-1, -1}, n = 0, m = 0, i, coupFait = 0, SaveCoup[4],
            PieceSelectID = -1, PieceBlockID = -1, PiecePriseID = -1, nextCoup = 0, PosRoiN[2], PosRoiB[2];

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

        if (IsEchecB(size, Copie, pieces) == 1) {

            printEchiquier(size, echiquier);
            wprintf(L"\nEchec pour les blancs !\n");
            while (IsEchecB(size, echiquier, pieces) == 1) {
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

                    printEchiquier(size, echiquier);
                }
                //reset ce qui doit l'etre
            }
        }
        else{
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

                    printEchiquier(size, echiquier);
                }

                if(IsEchecB(size, Copie, pieces) == 1){
                    wprintf(L"Le coup vous mettrais en echec");
                }
        }
            while (IsEchecB(size, Copie, pieces) == 1);
        //reset ce qui doit l'etre
    }

        if (IsEchecN(size, echiquier, pieces) == 1) {

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
                }
                //reset ce qui doit l'etre
                printEchiquier(size, echiquier);
            }
        }

        else {

            printEchiquier(size, echiquier);


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
                }
                //reset ce qui doit l'etre
                if(IsEchecN(size, Copie, pieces) == 1){
                    wprintf(L"Le coup vous mettrais en echec");
                }
            }
            while (IsEchecN(size, Copie, pieces) == 1);

            printEchiquier(size, echiquier);

        }
        wprintf(L"\nPour aller au prochain coup, entrez 0, pour quitter, entrez 2");

        scanf("%d", &nextCoup);
    }
}

void fonctEchiquier(piece pieces[]){

    int size=0, x, y;
    //input de la taille de l'échequier
    wprintf(L"Entrez la taille de l'echiquier\n");
    scanf("%d", &size);
    while(size<6 || size>12){
        wprintf(L"La valeur doit etre comprise entre 6 et 12");
        scanf("%d", &size);
    }
    char echiquier[size][size];
    generation(pieces, size, echiquier);

    jeu(size, echiquier, pieces);
    /*
     * Cette partie de ce programme sert a enregistrer l'échiquier dans un fichier, puis la taille de celui-ci dans un
     * autre fichier. L'enregistrement de l'échiquier se fait caractère par caractère et le fichier "size" ne contiens
     * que la taille. Les fichiers sont fermés après utilisation.
     */

  FILE* f = fopen("Save.txt","w+"); //Ouvre le fichier de sauvegarde (ecriture/lecture + suppression de ce qui a été écrit au paravant)
    if(f!= NULL){ //vérification de l'ouverture
        for(x=0; x<size;x++) {
            for (y = 0; y < size; y++) {
                fprintf(f, "%c", echiquier[x][y]); //Ecriture de l'echiquier dans le ficher
            }
        }
    }
    fclose(f);

    FILE* d = fopen("Size.txt","w");

    if(d != NULL){
        fprintf(d,"%d",size);
    }
    fclose(d);
    menu();
}