//
// Created by reini on 06/05/2022.
//

#include "echequier.h"
#include <stdio.h>
#include "pieces.h"
#include "fonctions.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printEchiquier(int size, char echequier[size][size]){
    int x=0, y=0, i=0, ascii_A=65;

    wprintf(L"\n  ");
    for(i=0; i<=size; i++){
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
    //bas tableau

}

void searchPiece(char name,int * pieceID ,piece pieces[]){
    int i;
    for(i=0; i<=11; i++){
        if(name==pieces[i].name){
            *pieceID = pieces[i].id;
        }
    }
}

void fonctEchiquier(){
    int size=0;

    struct piece pieces[12] = {
            0,'p', {0,0}, {1,2},"Pion noir",
            1,'c', {-1,-1,-2,-2,1,1,2,2},{-2,2,-1,1,-2,2,-1,1},"Cavalier Noir",
            2,'f',{},{},"Fou Noir",
            3,'t',{},{},"Tour Noire",
            4,'q',{},{},"Reine Noire",
            5,'r',{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1},"Roi Noir",

            6,'P', {0,0}, {1,2},"Pion Blanc",
            7,'C', {-1,-1,-2,-2,1,1,2,2},{-2,2,-1,1,-2,2,-1,1},"Cavalier Blanc",
            8,'F',{},{},"Fou Blanc",
            9,'T',{},{},"Tour Blache",
            10,'Q',{},{},"Reine Blanche",
            11,'R',{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1},"Roi Blanc"
    };

    //input de la taille de l'échequier
    wprintf(L"Entrez la taille de l'echiquier\n");
    scanf("%d", &size);
    while(size<6 || size>12){
        wprintf(L"La valeur doit etre comprise entre 6 et 12");
        scanf("%d", &size);
    }

    char echiquier[size][size];

    //remplissage
    int x, y, i , idPiece, compteurRoi=0;
    srand(time(0));
    for(x=0; x < 2; x++){
        for(y=0; y < size; y++){
            idPiece = rand()%6;
            for(i=0;i<=5;i++){
               if(idPiece == pieces[i].id){
                   echiquier[x][y]=pieces[i].name;
                 }
               }
            }
        }
    for(x=2; x<size-2; x++){
        for(y=0; y<size; y++){
            echiquier[x][y] = ' ';
        }
    }
    for(x=size-2; x<size; x++){
        for(y=0; y<size; y++){
            idPiece = 6 + rand()%6;
            for(i=6;i<=11;i++){
                if(idPiece == pieces[i].id){
                    echiquier[x][y]=pieces[i].name;
                }
            }
        }
    }

    //verifRoi
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
                echiquier[x][rand() % size]='r';
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
                echiquier[x][rand() % size]='R';
            }
        }
    }




    int CaseStart[2]={-1, -1},CaseEnd[2]={-1, -1};
    int PieceSelectID=0, nextCoup=0;
    char lettre;

    printEchiquier(size, echiquier);




    while(nextCoup == 0){
        wprintf(L"Quelle piece voulez vous deplacer ?\n Numero de la ligne : ");
        while (CaseStart[0] < 0 || CaseStart[0] >= size) {
            scanf(" %d", &CaseStart[0]);
            //le 1 affiché correspond au 0 echiquier
            CaseStart[0] = CaseStart[0]-1;
        }
        wprintf(L"\n");

        wprintf(L" Lettre de colonne : ");
        while (lettre < 'A' || lettre >= 'A' + size) {
            scanf("%c", &lettre);
        }
        LetterToInt(lettre, &CaseStart[1]);
        lettre = ' ';

        //verif si c'est une piece blanche, si case vide ou piece noire, choisir autre piece
        if(echiquier[CaseStart[0]][CaseStart[1]] != ' '){
            searchPiece(echiquier[CaseStart[0]][CaseStart[1]], &PieceSelectID, pieces);
        }

        wprintf(L"Piece selectionee : ");
        for(i=0; i<strlen(pieces[PieceSelectID].namePiece); i++){
            wprintf(L"%c", pieces[PieceSelectID].namePiece[i]);
        }
        wprintf(L"\n");

        wprintf(L"Ou voulez vous vous déplacer ?\n Numero de la Ligne : ");
        while(CaseEnd[0] < 0 || CaseEnd[0] >= size){
            scanf(" %d", &CaseEnd[0]);
            CaseEnd[0] = CaseEnd[0]-1;
        }
        wprintf(L"\n");

        wprintf(L" Lettre de colonne : ");
        while(lettre < 'A' || lettre >= 'A' + size){
            scanf("%c", &lettre);
        }
        LetterToInt(lettre, &CaseEnd[1]);
        lettre = ' ';


        wprintf(L"Case de départ : \n");
        for(i=0; i<2; i++){
            wprintf(L"%d", CaseStart[i]);
        }
        wprintf(L"\n");
        wprintf(L"Case d'arrivée : \n");
        for(i=0; i<2; i++){
            wprintf(L"%d", CaseEnd[i]);
        }
        wprintf(L"\n");

        fonctionCoup(echiquier[CaseStart[0]][CaseStart[1]], size, echiquier, CaseStart, CaseEnd);

        printEchiquier(size, echiquier);

        //reset des coups
        CaseStart[0]=-1; CaseStart[1]=-1; CaseEnd[0]=-1; CaseEnd[1]=-1;

        wprintf(L"Pour aller au prochain coup, entrez 0, sinon\nPour quitter, entrez 2");
        scanf("%d", &nextCoup);
    }
}