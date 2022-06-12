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
            wprintf(L"PB");
            break;
        case 'T':
            wprintf(L"TB");
            break;
        case 'C':
            wprintf(L"CB");
            break;
        case 'F':
            wprintf(L"FB");
            break;
        case 'Q':
            wprintf(L"QB");
            break;
        case 'R':
            wprintf(L"RB");
            break;

            //pieces noires
        case 'p':
            wprintf(L"pn");
            break;
        case 't':
            wprintf(L"tn");
            break;
        case 'c':
            wprintf(L"cn");
            break;
        case 'f':
            wprintf(L"fn");
            break;
        case 'q':
            wprintf(L"qn");
            break;
        case 'r':
            wprintf(L"rn");
            break;
        default:
            wprintf(L" ");
            break;
    }
}

int dPion(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1];

    if(pieceID > 5){
        //si avant derniere ligne, coup  et rien ne bloque
        if ((echiquier[Depart[0]][Depart[1]] == echiquier[size - 2][Depart[1]] && (dx == -2) &&
             Arrivee[1] == Depart[1]) && pieceBlockID == -1) {
            return 1;
        } else if ((dx == -1 && Arrivee[1] == Depart[1]) && pieceBlockID == -1) {
            return 1;
        }
            //Condition de prise d'une piece, verification si piece noir et si la placement est bon
        else if (pieceBlockID < 6 && ((dx == -1 && dy == 1) || (dx == -1 && dy == -1))) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        //si avant derniere ligne, coup  et rien ne bloque
        if((echiquier[Depart[0]][Depart[1]] == echiquier[1][Depart[1]] && (dx == 2) && Arrivee[1] == Depart[1]) && pieceBlockID==-1){
            return 1;
        }
        else if((dx == 1 && Arrivee[1] == Depart[1]) && pieceBlockID==-1){
            return 1;
        }
            //Condition de prise d'une piece, verification si piece noir et si la placement est bon
        else if(pieceBlockID >= 6 && ((dx == 1 && dy == 1) || (dx == 1 && dy == -1))){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int dCavalier(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1];

    if(pieceID>5) {

        //Si l'un des deplacements est egal a 1 ou -1 et que l'autre est egal a 2*deplacement ou -2*deplacement
        if ((dx == 1 || dx == -1 || dy == 1 || dy == -1)
            && (dx == -2 * dy || dx == 2 * dy || dy == -2 * dx || dy == 2 * dx)) {
            if (pieceBlockID == -1) {
                return 1;
            } else if (pieceBlockID < 6) {
                return 1;
            } else {
                //piece blanche bloquante
                return 0;
            }
        }
        else {
            //coup impossible
            return 0;
        }
    }
    else{
        if ((dx == 1 || dx == -1 || dy == 1 || dy == -1)
            && (dx == -2 * dy || dx == 2 * dy || dy == -2 * dx || dy == 2 * dx)) {
            if (pieceBlockID == -1) {
                return 1;
            } else if (pieceBlockID > 5) {
                return 1;
            } else {
                //piece noire bloquante
                return 0;
            }
        } else {
            return 0;
        }
    }
}

int dFou(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], trajet=0, i;

    if(pieceID>5){
        if(abs(dx)==abs(dy)){
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
                    return 1;
                }
                else if(pieceBlockID<6){
                    return 1;
                }
                else{
                    //wprintf(L"Piece blanche bloquante");
                    return 0;
                }
            }
            else{
                //wprintf(L"Une piece bloque le trajet");
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        if(abs(dx)==abs(dy)){
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
                    return 1;
                }
                else if(pieceBlockID>5){
                    return 1;
                }
                else{
                    //wprintf(L"Piece noire bloquante");
                    return 0;
                }
            }
            else{
                //wprintf(L"Une piece bloque le trajet");
                return 0;
            }
        }
        else{
            return 0;
        }
    }
}

int dTour(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i, trajet=0;
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
                    return 1;
                }
                else if(pieceBlockID<6){
                    return 1;
                }
                else{
                    //wprintf(L"Piece blanche bloquante");
                    return 0;
                }
            }
            else{
                //wprintf(L"Une piece bloque le trajet");
                return 0;
            }
        }
        else{
            //wprintf(L"Coup impossible pour la tour");
            return 0;
        }
    }
    else{
        if(dx==0 || dy == 0){    //si le mouvement est rectiligne
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
                    return 1;
                }
                else if(pieceBlockID>5){
                    return 1;
                }
                else{
                    //wprintf(L"Piece blanche bloquante");
                    return 0;
                }
            }
            else{
                //wprintf(L"Une piece bloque le trajet");
                return 0;
            }
        }
        else{
            //wprintf(L"Coup impossible pour la tour");
            return 0;
        }
    }
}

int dReine(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i, trajet;

    if(dTour(size, echiquier, Depart, Arrivee, pieceID, pieceBlockID)==1 || dFou(size, echiquier, Depart, Arrivee, pieceID, pieceBlockID)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int dRoi(int size, char echiquier[size][size], int Depart[], int Arrivee[], int pieceID, int pieceBlockID){
    int dx = Arrivee[0]-Depart[0], dy = Arrivee[1]-Depart[1], i;
    if( ((abs(dx)==1 && abs(dy)==1) || (dx==0 && abs(dy)== 1) || (abs(dx)==1 && dy ==0)) && pieceID>5 && pieceBlockID<6){
        return 1;
    }
    else if(((abs(dx)==1 && abs(dy)==1) || (dx==0 && abs(dy) == 1) || (abs(dx)==1 && dy ==0)) && pieceID<6 && pieceBlockID>5){
        return 1;
    }
    else if(((abs(dx)==1 && abs(dy)==1) || (dx==0 && abs(dy)== 1) || (abs(dx)==1 && dy ==0)) && pieceBlockID==-1){
        //si rien ne bloque
        return 1;
    }
    else{
        return 0;
    }
}