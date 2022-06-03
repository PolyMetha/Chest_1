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

void printEchiquier(int size, char echequier[size][size], char PiecesPrisesB[], char PiecesPrisesN[]){
    int x, y, i,j=0, ascii_A=65;

    //Pieces perdues par les noirs
    wprintf(L"\n\n ");
    while(PiecesPrisesN[j]!='\0'){
        findSprite(PiecesPrisesN[j]);
        j=j+1;
    }

    //print lettres echiquier
    wprintf(L"\n\n ");
    for(i=0; i<size; i++){
        wprintf(L" %c ", ascii_A+i);
        if(i%2==0){
            wprintf(L" ");
        }
    }
    wprintf(L"\n");

    //contenu
    for(x=0; x<size; x++){
        wprintf(L"%d ", x+1);
        for(y=0; y<size; y++){
            if(echequier[x][y]!=' '){
                wprintf(L" ");
                findSprite(echequier[x][y]);
                wprintf(L" ");
            }
            else{
                if(x%2==0){
                    if(y%2==0){
                        wprintf(L" \x2015 ");
                    }
                    else{
                        wprintf(L" \x2001 ");
                    }
                }
                else{
                    if(y%2==0){
                        wprintf(L" \x2001 ");
                    }
                    else{
                        wprintf(L" \x2015 ");
                    }
                }

            }
        }
        wprintf(L"\n");


    }

    //Pieces perdues par les blancs
    while(PiecesPrisesN[j]!='\0'){
        findSprite(PiecesPrisesN[j]);
        j=j+1;
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

void echec(int size, char echiquier[size][size], char copie[size][size], int * echecB, int * echecN){
    int x, y, CaseRoiB[2], CaseRoiN[2];
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){
            if(echiquier[x][y]=='R'){
                CaseRoiB[0]=x;
                CaseRoiB[1]=y;
            }
            if(echiquier[x][y]=='r'){
                CaseRoiN[0]=x;
                CaseRoiN[1]=y;
            }
        }
    }

    if(copie[CaseRoiB[0]][CaseRoiB[0]]=='1' || copie[CaseRoiB[0]][CaseRoiB[0]]=='2' || copie[CaseRoiB[0]][CaseRoiB[0]]=='4'){
        *echecB = 1;
    }
    if(copie[CaseRoiN[0]][CaseRoiN[0]]=='0' ||copie[CaseRoiN[0]][CaseRoiN[0]]=='2' || copie[CaseRoiN[0]][CaseRoiN[0]]=='3'){
        *echecN = 1;
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

void jeu(int size, char echiquier[size][size], piece pieces[]) {
    int Start[2] = {-1, -1}, End[2] = {-1, -1}, n = 0, m = 0, i, coupFait=0, echecB=0, echecN=0;     //Cases de départ et d'arrivée et compteurs
    int PieceSelectID = -1, PieceBlockID = -1, PiecePriseID = -1, nextCoup = 0; //ID de la piece selectionnée et la piece bloquante lors du coup
    char lettre, PiecePriseName, PiecesPrisesB[2 * size], PiecesPrisesN[2 * size];    //Lettre de la colonne
    char MatriceEchiquier[size][size], CopieEchiquier[size][size];

    //Affiche la situation de départ
    printEchiquier(size, echiquier, PiecesPrisesB, PiecesPrisesN);

    //initialise une copie de l'echiquier
    for(i=0; i<size; i++){
        for(n=0; n<size; n++){
            MatriceEchiquier[i][n] = ' ';
        }
    }

    //Selection de la piece a deplacer
    while (nextCoup == 0) {
        wprintf(L"Tour des blancs\n");
        do{
            echec(size, echiquier, MatriceEchiquier, &echecB, &echecN);

            /**
             * scan echec
             * si echec==1
             *  jouer avec copie echiquier
             *  scan echec
             *  si echec == 1
             *      relancer la boucle
             *  sinon
             *      appliquer les changements sur la vraie grille
             *      terminer la boucle
             *  sinon
             *      jouer normalement
             */

            wprintf(L"%d", echecB);
            if(echecB==1){
                wprintf(L"Les blancs sont en echec");
            }

            input(Start, size);

            wprintf(L"\n");


            //verif si c'est une piece blanche, si case vide ou piece noire, choisir autre piece
            if (echiquier[Start[0]][Start[1]] != ' ') {
                searchID(echiquier[Start[0]][Start[1]], &PieceSelectID, pieces);
                if (PieceSelectID >= 6) {
                    wprintf(L"Piece selectionee : ");
                    for (i = 0; i < strlen(pieces[PieceSelectID].namePiece); i++) {
                        wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
                    }
                    wprintf(L"\n");

                    //Entrée de la case d'arrivée de la piece
                    wprintf(L"Ou voulez vous vous déplacer ?\n Lettre de la colonne : ");
                    input(End, size);

                    //Si l'arrivée n'est pas vide, on prend l'ID de la piece bloquante
                    if (echiquier[End[0]][End[1]] != ' ') {
                        searchID(echiquier[End[0]][End[1]], &PieceBlockID, pieces);
                    }


                    /* FonctionCoup redirige vers une fonction propre a chaque piece qui verifie si le deplacement est possible
                    elle prend en parametre la lettre de la piece, la taille de l'echiquier, la case de départ, d'arrivée
                    l'id de la piece de départ, l'id de la potentille piece prise */
                    if(fonctionCoup(size, echiquier, MatriceEchiquier, Start, End, PieceSelectID, PieceBlockID, &PiecePriseID) == 1){
                        echiquier[End[0]][End[1]] = echiquier[Start[0]][Start[1]];
                        echiquier[Start[0]][Start[1]] = ' ';
                        verifEchec(size, echiquier, MatriceEchiquier, pieces);
                        coupFait=0;
                    }
                    else{
                        //si la fonction retourne 0, cela veut dire que le coup n'a pas pu etre fait, on recommence la boucle
                        wprintf(L"Coup impossible");
                        coupFait = 1;
                    }

                    //On cherche la nom de la piece éventuellement prise lors du déplacement
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

                    //reset des variables
                    PiecePriseID = -1;
                    PiecePriseName = ' ';
                }
                else{
                    wprintf(L"\nPiece invalide, choisir une autre piece");
                    coupFait=1;
                }
            }

            if(echecB==1 && coupFait == 0){
                wprintf(L"Les noirs sont toujours en echec");
                //on remet la piece a son emplacement de départ
                echiquier[Start[0]][Start[1]] = echiquier[End[0]][End[1]];
                echiquier[End[0]][End[1]] = ' ';
                coupFait = 1;
            }
            //reset des variables de coup de départ, d'arrivée et des variables utilisées
            Start[0] = -1;
            Start[1] = -1;
            End[0] = -1;
            End[1] = -1;
            PieceSelectID = -1, PieceBlockID = -1, PiecePriseID = -1;

            //cherche si les blancs ou les noirs sont en echec
            echec(size, echiquier, MatriceEchiquier, &echecB, &echecN);

            //affichage de la situation finale
            printEchiquier(size, echiquier, PiecesPrisesB, PiecesPrisesN);
        }
        while(coupFait==1);


        coupFait = 0;


        wprintf(L"Tour des noirs\n");
        do {
            echec(size, echiquier, MatriceEchiquier, &echecB, &echecN);

            if(echecN==1){
                wprintf(L"LEs blancs sont en echec");
            }

            input(Start, size);

            wprintf(L"\n");

            //verif si c'est une piece noire, si case vide ou piece noire, choisir autre piece

            if (echiquier[Start[0]][Start[1]] != ' ') {
                searchID(echiquier[Start[0]][Start[1]], &PieceSelectID, pieces);
                if (PieceSelectID < 6) {
                    wprintf(L"Piece selectionee : ");
                    for (i = 0; i < strlen(pieces[PieceSelectID].namePiece); i++) {
                        wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
                    }
                    wprintf(L"\n");

                    //Entrée de la case d'arrivée de la piece
                    wprintf(L"Ou voulez vous aller ?\n");
                    input(End, size);

                    //Si l'arrivée n'est pas vide, on prend l'ID de la piece bloquante
                    if (echiquier[End[0]][End[1]] != ' ') {
                        searchID(echiquier[End[0]][End[1]], &PieceBlockID, pieces);
                    }

                    /* FonctionCoup redirige vers une fonction propre a chaque piece qui verifie si le deplacement est possible
                    elle prend en parametre la lettre de la piece, la taille de l'echiquier, la case de départ, d'arrivée
                    l'id de la piece de départ, l'id de la potentille piece prise */
                    if(fonctionCoup(size, echiquier, MatriceEchiquier, Start, End, PieceSelectID, PieceBlockID, &PiecePriseID) == 1){
                        echiquier[End[0]][End[1]] = echiquier[Start[0]][Start[1]];
                        echiquier[Start[0]][Start[1]] = ' ';
                        verifEchec(size, echiquier, MatriceEchiquier, pieces);
                        coupFait=0;
                    }
                    else{
                        coupFait=1;
                        wprintf(L"Coup impossible");
                    }

                    //On cherche la nom de la piece éventuellement prise lors du déplacement
                    if (PiecePriseID >= 6 && PiecePriseID <= 11) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesN[n] = PiecePriseName;
                        n = n + 1;
                    }
                    if (PiecePriseID >= 0 && PiecePriseID <= 5) {
                        searchName(PiecePriseID, &PiecePriseName, pieces);
                        findSprite(PiecePriseName);
                        PiecesPrisesB[m] = PiecePriseName;
                        m = n + 1;
                    }

                    //reset des variables
                    PiecePriseID = -1;
                    PiecePriseName = ' ';
                }
                else {
                    wprintf(L"\nPiece invalide, choisir une autre piece");
                    coupFait=1;
                }
            }

            if(echecN==1 && coupFait == 0){
                wprintf(L"Les noirs sont toujours en echec");
                //on remet la piece a son emplacement de départ
                echiquier[Start[0]][Start[1]] = echiquier[End[0]][End[1]];
                echiquier[End[0]][End[1]] = ' ';
                coupFait = 1;
            }

            Start[0] = -1;
            Start[1] = -1;
            End[0] = -1;
            End[1] = -1;
            PieceSelectID = -1, PieceBlockID = -1, PiecePriseID = -1;

            echec(size, echiquier, MatriceEchiquier, &echecB, &echecN);

            //affichage de la situation finale
            printEchiquier(size, echiquier, PiecesPrisesB, PiecesPrisesN);

        }
        while(coupFait==1);

        //reset des coups
        coupFait=0;

        printEchiquier(size, MatriceEchiquier, PiecesPrisesB, PiecesPrisesN);

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