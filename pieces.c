//
// Created by reini on 06/05/2022.
//

#include "pieces.h"
#include <io.h>
#include <stdio.h>
#include "echequier.h"

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

void dPionB(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceBlockID, int * PiecePriseNID){
    char temp;
    if((echiquier[Depart[0]][Depart[1]] == echiquier[size - 2][Depart[1]] && Arrivee[0] == Depart[0] - 2 && Arrivee[1] == Depart[1]) && echiquier[Arrivee[0]][Arrivee[1]]==' '){
        echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
        echiquier[Depart[0]][Depart[1]]=' ';
    }
    else if((Arrivee[0] == Depart[0] - 1 && Arrivee[1] == Depart[1])&& echiquier[Arrivee[0]][Arrivee[1]]==' '){
        echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
        echiquier[Depart[0]][Depart[1]]=' ';
    }
    //Condition de prise d'une piece, verification si piece noir et si la placement est bon
    else if(pieceBlockID >= 0 && pieceBlockID < 6 && ((Arrivee[0] == Depart[0] - 1 && Arrivee[1] == Depart[1] - 1) || (Arrivee[0] == Depart[0] - 1 && Arrivee[1] == Depart[1] + 1))){
        echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
        echiquier[Depart[0]][Depart[1]]=' ';
        *PiecePriseNID=pieceBlockID;
    }
    else{
        wprintf(L"La coup n'est pas autorisé");
    }
}