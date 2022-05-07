//
// Created by reini on 06/05/2022.
//

#include "echequier.h"
#include <stdio.h>
#include "pieces.h"
#include "fonctions.c"

void printEchequier(int size, char echequier[size][size]){
    int x=0, y=0, i=0;

    wprintf(L"\n");
    //contenu
    for(x=0; x<size; x++){
        for(y=0; y<size; y++){

            if(echequier[x][y]!=' '){
                wprintf(L"\x2001");
                findSprite(echequier[x][y]);
                wprintf(L"\x2001");
            }
            else{
                if(x%2==0){
                    if(y%2==0){
                        wprintf(L"\x2001\x2B1B\x2001");
                    }
                    else{
                        wprintf(L"\x2001\x2001\x2001");
                    }
                }
                else{
                    if(y%2==0){
                        wprintf(L"\x2001\x2001\x2001");
                    }
                    else{
                        wprintf(L"\x2001\x2B1B\x2001");
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

    wprintf(L"Entrez la taille de l'echequier");
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

    printEchequier(size, echequier);
}


