//
// Created by reini on 06/05/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pieces.h"

void LetterToInt(char lettre, int * select){
    switch(lettre){
        case 'A':
            *select = 0;
            break;
        case 'B':
            *select = 1;
            break;
        case 'C':
            *select = 2;
            break;
        case 'D':
            *select = 3;
            break;
        case 'E':
            *select = 4;
            break;
        case 'F':
            *select = 5;
            break;
        case 'G':
            *select = 6;
            break;
        case 'H':
            *select = 7;
            break;
        case 'I':
            *select = 8;
            break;
        case 'J':
            *select = 9;
            break;
        case 'K':
            *select = 10;
            break;
        case 'L':
            *select = 11;
            break;
        default:
            break;
    }
}