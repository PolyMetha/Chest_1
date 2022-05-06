//
// Created by reini on 06/05/2022.
//

#include "echequier.h"
#include <stdio.h>
#include "pieces.h"
#include "fonctions.c"

void echequier(){
    int size=0;

    struct piece pieces[6] = {
            0,'p', {0,0}, {1,2},"2659","265F",
            1,'c', {-1,-1,-2,-2,1,1,2,2},{-2,2,-1,1,-2,2,-1,1},"2658","265C",
            2,'f',{},{},"2657","265D",
            3,'t',{},{},"2656","265C",
            4,'r',{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1},"2654","265B",
            5,'q',{},{},"2655","265A"
    };

    wprintf(L"Entrez la taille de l'echequier");
    scanf("%d", &size);
    while(size<6 || size>12){
        wprintf(L"La valeur doit etre comprise entre 6 et 12");
        scanf("%d", &size);
    }

    char echequier[size][size];

    //remplissage
    int x, y, i , idPiece;
    srand(time(0));
    for(x=0; x < size; x++){
        for(y=0; y < size; y++){
            idPiece = rand()%7;
            for(i=0;i<=6;i++){
               if(idPiece == pieces[i].id){
                  wprintf(L"%c", pieces[i].name);
                 }
               }
            }
        }
    wprintf(L"\n");
}
