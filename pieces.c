//
// Created by reini on 06/05/2022.
//

#include "pieces.h"
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include "echequier.h"
#include <math.h>

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

void dPion(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int * PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1];

    if(pieceID > 5){
        //si avant derniere ligne, coup  et rien ne bloque
        if ((echiquier[Depart[0]][Depart[1]] == echiquier[size - 2][Depart[1]] && (dx == -2) &&
             Arrivee[1] == Depart[1]) && pieceBlockID == -1) {
            echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]] = ' ';
        } else if ((dx == -1 && Arrivee[1] == Depart[1]) && pieceBlockID == -1) {
            echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]] = ' ';
        }
            //Condition de prise d'une piece, verification si piece noir et si la placement est bon
        else if (pieceBlockID < 6 && ((dx == -1 && dy == 1) || (dx == -1 && dy == -1))) {
            echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]] = ' ';
            *PiecePriseNID = pieceBlockID;
        } else {
            wprintf(L"Le coup n'est pas autorisé");
            *coupFait = 1;
        }
    }
    else{
        //si avant derniere ligne, coup  et rien ne bloque
        if((echiquier[Depart[0]][Depart[1]] == echiquier[1][Depart[1]] && (dx == 2) && Arrivee[1] == Depart[1]) && pieceBlockID==-1){
            echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]]=' ';
        }
        else if((dx == 1 && Arrivee[1] == Depart[1]) && pieceBlockID==-1){
            echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]]=' ';
        }
            //Condition de prise d'une piece, verification si piece noir et si la placement est bon
        else if(pieceBlockID >= 6 && ((dx == 1 && dy == 1) || (dx == 1 && dy == -1))){
            echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
            echiquier[Depart[0]][Depart[1]]=' ';
            *PiecePriseNID=pieceBlockID;
        }
        else{
            wprintf(L"Le coup n'est pas autorisé");
            *coupFait = 1;
        }
    }

}

void dCavalier(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int * PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1];

    if(pieceID>5) {

        //Si l'un des deplacements est egal a 1 ou -1 et que l'autre est egal a 2*deplacement ou -2*deplacement
        if ((dx == 1 || dx == -1 || dy == 1 || dy == -1)
            && (dx == -2 * dy || dx == 2 * dy || dy == -2 * dx || dy == 2 * dx)) {
            if (pieceBlockID == -1) {
                echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                echiquier[Depart[0]][Depart[1]] = ' ';
            } else if (pieceBlockID < 6) {
                echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                echiquier[Depart[0]][Depart[1]] = ' ';
                *PiecePriseNID = pieceBlockID;
            } else {
                wprintf(L"Piece blanche bloquante");
                *coupFait = 1;
            }
        } else {
            wprintf(L"Le coup n'est pas autorisé\n");
            *coupFait = 1;
        }
    }
    else{
        if ((dx == 1 || dx == -1 || dy == 1 || dy == -1)
            && (dx == -2 * dy || dx == 2 * dy || dy == -2 * dx || dy == 2 * dx)) {
            if (pieceBlockID == -1) {
                echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                echiquier[Depart[0]][Depart[1]] = ' ';
            } else if (pieceBlockID > 5) {
                echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                echiquier[Depart[0]][Depart[1]] = ' ';
                *PiecePriseNID = pieceBlockID;
            } else {
                wprintf(L"Piece noire bloquante");
                *coupFait = 1;
            }
        } else {
            wprintf(L"Le coup n'est pas autorisé\n");
            *coupFait = 1;
        }
    }
};

void dFou(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int *PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], trajet=0, i;
    if(pieceID>5){
        if(dx==dy || dx == -dy){
            if(dx>0 && dy > 0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx>0 && dy <0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx<0 && dy>0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else{
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }

            if(trajet==0){
                if(pieceBlockID==-1){

                    echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                }
                else if(pieceBlockID<6){
                    echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else{
                    wprintf(L"Piece blanche bloquante");
                    *coupFait = 1;
                }
            }
            else{
                wprintf(L"Une piece bloque le trajet");
                *coupFait = 1;
            }
        }
    }
    else{
        if(dx==dy || dx == -dy){
            if(dx>0 && dy > 0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx>0 && dy <0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx<0 && dy>0){
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else{
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }

            if(trajet==0){
                if(pieceBlockID==-1){
                    echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                }
                else if(pieceBlockID>5){
                    echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else{
                    wprintf(L"Piece noire bloquante");
                    *coupFait = 1;
                }
            }
            else{
                wprintf(L"Une piece bloque le trajet");
                *coupFait = 1;
            }
        }
    }
}

void dTour(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int *PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i, trajet;
    if(pieceID>5){
        if(dx==0 || dy ==0){    //si le mouvement est rectiligne
            if(dx<0){           //si deplacement vers le haut
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx>0){      //si deplacement vers le bas
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dy<0){      //deplacement vers la gauche
                for(i=1; i<abs(dy); i++){
                    if(echiquier[Depart[0]][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else{               //deplacement vers la droite
                for(i=1; i<abs(dy); i++){
                    if(echiquier[Depart[0]][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }

            if(trajet==0){
                if(pieceBlockID==-1){
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]] = ' ';
                }
                else if(pieceBlockID<6){
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else{
                    wprintf(L"Piece blanche bloquante");
                    *coupFait = 1;
                }
            }
            else{
                wprintf(L"Une piece bloque le trajet");
                *coupFait = 1;
            }
        }
        else{
            wprintf(L"Coup non valide");
            *coupFait = 1;
        }
    }
    else{
        if(dx==0 || dy ==0){    //si le mouvement est rectiligne
            if(dx<0){           //si deplacement vers le haut
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]-i][Depart[1]] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dx>0){      //si deplacement vers le bas
                for(i=1; i<abs(dx); i++){
                    if(echiquier[Depart[0]+i][Depart[1]] != ' '){
                        trajet = 1;
                    }
                }
            }
            else if(dy<0){      //deplacement vers la gauche
                for(i=1; i<abs(dy); i++){
                    if(echiquier[Depart[0]][Depart[1]-i] != ' '){
                        trajet = 1;
                    }
                }
            }
            else{               //deplacement vers la droite
                for(i=1; i<abs(dy); i++){
                    if(echiquier[Depart[0]][Depart[1]+i] != ' '){
                        trajet = 1;
                    }
                }
            }

            if(trajet==0){
                if(pieceBlockID==-1){
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]] = ' ';
                }
                else if(pieceBlockID>5){
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]]=' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else{
                    wprintf(L"Piece blanche bloquante");
                    *coupFait = 1;
                }
            }
            else{
                wprintf(L"Une piece bloque le trajet");
                *coupFait = 1;
            }
        }
        else{
            wprintf(L"Coup non valide");
            *coupFait = 1;
        }
    }
}

void dReine(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int *PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i, trajet;
    if(dx == 0 || dy ==0 || dx == dy || dx == -dy) {
        if (dx < 0) {           //si deplacement vers le haut
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] - i][Depart[1]] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dx > 0) {      //si deplacement vers le bas
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] + i][Depart[1]] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dy < 0) {      //deplacement vers la gauche
            for (i = 1; i < abs(dy); i++) {
                if (echiquier[Depart[0]][Depart[1] - i] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dy > 0) {               //deplacement vers la droite
            for (i = 1; i < abs(dy); i++) {
                if (echiquier[Depart[0]][Depart[1] + i] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dx > 0 && dy > 0) {
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] + i][Depart[1] + i] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dx > 0 && dy < 0) {
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] + i][Depart[1] - i] != ' ') {
                    trajet = 1;
                }
            }
        } else if (dx < 0 && dy > 0) {
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] - i][Depart[1] + i] != ' ') {
                    trajet = 1;
                }
            }
        } else {
            for (i = 1; i < abs(dx); i++) {
                if (echiquier[Depart[0] - i][Depart[1] - i] != ' ') {
                    trajet = 1;
                }
            }
        }
            if (trajet == 0) {
                if (pieceBlockID == -1) {
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]] = ' ';
                } else if (pieceID >5 && pieceBlockID < 6) {
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]] = ' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else if (pieceID < 6 && pieceBlockID > 5 ) {
                    echiquier[Arrivee[0]][Arrivee[1]] = echiquier[Depart[0]][Depart[1]];
                    echiquier[Depart[0]][Depart[1]] = ' ';
                    *PiecePriseNID = pieceBlockID;
                }
                else {
                    wprintf(L"Piece bloquante");
                    *coupFait = 1;
                }
            }
            else {
                wprintf(L"Une piece bloque le trajet");
                *coupFait = 1;
            }
        }
    else{
        wprintf(L"Coup non valide");
        *coupFait = 1;
    }
}

void dRoi(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID, int *PiecePriseNID, int * coupFait){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i, trajet;
    if( ((abs(dx)==1 && abs(dy)==1) || (dx==0 && abs(dy == 1)) || (abs(dx)==1 && dy ==0)) && pieceID>5 && pieceBlockID<6){
        echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
        echiquier[Depart[0]][Depart[1]]=' ';
        *PiecePriseNID = pieceBlockID;
    }
    else if(((abs(dx)==1 && abs(dy)==1) || (dx==0 && abs(dy == 1)) || (abs(dx)==1 && dy ==0)) && pieceID<6 && pieceBlockID>5){
        echiquier[Arrivee[0]][Arrivee[1]]=echiquier[Depart[0]][Depart[1]];
        echiquier[Depart[0]][Depart[1]]=' ';
        *PiecePriseNID = pieceBlockID;
}
    else{
        wprintf(L"Coup non autorisé");
        *coupFait = 1;
    }
}