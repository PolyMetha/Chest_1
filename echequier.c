//
// Created by reini on 06/05/2022.
//

#include "echequier.h"
#include <stdio.h>
#include "pieces.h"
#include "fonctions.h"
#include <time.h>
#include <stdlib.h>

void printEchequier(int size, char echequier[size][size]){
    int x=0, y=0, i=0, ascii_A=65;

    wprintf(L"\n  ");
    for(i=0; i<size; i++){
        wprintf(L" %d ", i);
        if(i%2==0){
            wprintf(L" ");
        }
    }
    wprintf(L"\n");
    //contenu
    for(x=0; x<size; x++){
        wprintf(L"%c ", ascii_A+x);
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

void fonctEchequier(){
    int size=0;

    struct piece pieces[12] = {
            0,'p', {0,0}, {1,2},
            1,'c', {-1,-1,-2,-2,1,1,2,2},{-2,2,-1,1,-2,2,-1,1},
            2,'f',{},{},
            3,'t',{},{},
            4,'q',{},{},
            5,'r',{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1},

            6,'P', {0,0}, {1,2},
            7,'C', {-1,-1,-2,-2,1,1,2,2},{-2,2,-1,1,-2,2,-1,1},
            8,'F',{},{},
            9,'T',{},{},
            10,'Q',{},{},
            11,'R',{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1},
    };

    //input de la taille de l'échequier
    wprintf(L"Entrez la taille de l'echequier\n");
    scanf("%d", &size);
    while(size<6 || size>12){
        wprintf(L"La valeur doit etre comprise entre 6 et 12");
        scanf("%d", &size);
    }

    char echequier[size][size];

    //remplissage
    int x, y, i , idPiece, compteurRoi=0;
    srand(time(0));
    for(x=0; x < 2; x++){
        for(y=0; y < size; y++){
            idPiece = rand()%6;
            for(i=0;i<=5;i++){
               if(idPiece == pieces[i].id){
                  echequier[x][y]=pieces[i].name;
                 }
               }
            }
        }
    for(x=2; x<size-2; x++){
        for(y=0; y<size; y++){
            echequier[x][y] = ' ';
        }
    }
    for(x=size-2; x<size; x++){
        for(y=0; y<size; y++){
            idPiece = 6 + rand()%6;
            for(i=6;i<=11;i++){
                if(idPiece == pieces[i].id){
                    echequier[x][y]=pieces[i].name;
                }
            }
        }
    }

    //verifRoi
    for(x=0; x<2; x++){
        if(x==0){
            for(y=0; y<size; y++){
                if(echequier[x][y]=='r'){
                    compteurRoi = compteurRoi+1;
                }
                if(compteurRoi>1){
                    idPiece = rand()%5;
                    for(i=0;i<5;i++){
                        if(idPiece == pieces[i].id){
                            echequier[x][y]=pieces[i].name;
                        }
                    }
                }
                }
            if(compteurRoi==0){
                echequier[x][rand()%size]='r';
            }
            }
        if(x==1){
            for(y=0; y<size; y++){
                if(echequier[x][y]=='r'){
                    idPiece = rand()%5;
                    for(i=0;i<5;i++){
                        if(idPiece == pieces[i].id){
                            echequier[x][y]=pieces[i].name;
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
                if(echequier[x][y]=='R'){
                    idPiece = 6 + rand()%5;
                    for(i=6;i<11;i++){
                        if(idPiece == pieces[i].id){
                            echequier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
        }
        if(x==size-1){
            for(y=0; y<size; y++){
                if(echequier[x][y]=='R'){
                    compteurRoi = compteurRoi+1;
                }
                if(compteurRoi>1){
                    idPiece = 6 + rand()%5;
                    for(i=6;i<11;i++){
                        if(idPiece == pieces[i].id){
                            echequier[x][y]=pieces[i].name;
                        }
                    }
                }
            }
            if(compteurRoi==0){
                echequier[x][rand()%size]='R';
            }
        }
    }

    int CaseStart[2]={-1, -1},CaseEnd[2]={-1, -1} ;
    char lettre;

    printEchequier(size, echequier);

    wprintf(L"Quelle piece voulez vous deplacer ?\n Lettre de la ligne : ");
    while (lettre < 'A' || lettre >= 'A' + size) {
         scanf("%c", &lettre);
         }
    LetterToInt(lettre, &CaseStart[0]);
    lettre = ' ';
    wprintf(L" Numero de colonne : ");
    while (CaseStart[1] < 0 || CaseStart[1] >= size) {
         scanf(" %d", &CaseStart[1]);
         }
    wprintf(L"\n");

    wprintf(L"Ou voulez vous vous déplacer ?\n Lettre de la ligne : ");
    while(lettre < 'A' || lettre >= 'A' + size){
        scanf("%c", &lettre);
    }
    LetterToInt(lettre, &CaseEnd[0]);
    lettre = ' ';
    wprintf(L" Numero de colonne : ");
    while(CaseEnd[1] < 0 || CaseEnd[1] >= size){
        scanf(" %d", &CaseEnd[1]);
    }
    wprintf(L"\n");


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
}