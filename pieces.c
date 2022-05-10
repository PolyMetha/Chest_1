//
// Created by reini on 06/05/2022.
//

#include "pieces.h"
#include <io.h>
#include <stdio.h>

void findSprite(char name){
    _setmode(_fileno(stdout), 0x00020000);
    switch(name){
        //pieces blanches
        case 'P':
            wprintf(L"\x2659");
            break;
        case 'T':
            wprintf(L"\x2656");
            break;
        case 'C':
            wprintf(L"\x2658");
            break;
        case 'F':
            wprintf(L"\x2657");
            break;
        case 'Q':
            wprintf(L"\x2655");
            break;
        case 'R':
            wprintf(L"\x2654");
            break;

            //pieces noires
        case 'p':
            wprintf(L"\x265F");
            break;
        case 't':
            wprintf(L"\x265C");
            break;
        case 'c':
            wprintf(L"\x265E");
            break;
        case 'f':
            wprintf(L"\x265D");
            break;
        case 'q':
            wprintf(L"\x265B");
            break;
        case 'r':
            wprintf(L"\x265A");
            break;
        default:
            wprintf(L"\x2001");
            break;
    }
}

void dPion(int size, char echiquier[size][size], int CaseDepart[], int CaseArrivee[]){
    char temp;
    if(CaseArrivee[0]==CaseDepart[0]-1 && CaseArrivee[1]==CaseDepart[1]){
        echiquier[CaseArrivee[0]][CaseArrivee[1]]=echiquier[CaseDepart[0]][CaseDepart[1]];
        echiquier[CaseDepart[0]][CaseDepart[1]]=' ';
        wprintf(L"%c   %c",echiquier[CaseArrivee[0]][CaseArrivee[1]],echiquier[CaseDepart[0]][CaseDepart[1]] );
    }
    else{
        wprintf(L"Ca marche pas");
    }
}