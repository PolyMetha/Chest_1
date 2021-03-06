//
// Created by reini on 06/05/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io.h>             //requis pour imprimer les caractères en unicodes
#include <windows.h>        //requis pour clear la console sur windows
#include "echequier.h"
#include "menu.h"
#include "Savefile.h"
#include "fonctions.h"

void menu (){
    _setmode(_fileno(stdout), 0x00020000);
    int reponse;
    char quitter[3] = "oui";
    int quitterboolean = 1;
    struct piece pieces[12] = {
            0,'p',"Pion noir",
            1,'c',"Cavalier Noir",
            2,'f',"Fou Noir",
            3,'t',"Tour Noire",
            4,'q',"Reine Noire",
            5,'r',"Roi Noir",

            6,'P',"Pion Blanc",
            7,'C', "Cavalier Blanc",
            8,'F',"Fou Blanc",
            9,'T',"Tour Blanche",
            10,'Q',"Reine Blanche",
            11,'R',"Roi Blanc"
    };
    while(quitterboolean != 0){
        clear();
        wprintf(L"Jeu proposé par Andréa REINICHE et Quentin BALEZEAU\n");
        wprintf(L"  ┌──────────────────────────────┐\n");
        wprintf(L"  │   1 - Demarrer une partie    │\n");
        wprintf(L"  │   2 - Reprendre une partie   │\n");
        wprintf(L"  │   3 - Quitter                │\n");
        wprintf(L"  └──────────────────────────────┘\n");
        wprintf(L"En pleine partie, 'S' permet de sauvegarder, 'X' permet d'abandonner\n");

        do {//Vérification de l'accisition de l'utilisateur.
            fflush(stdin);
            scanf("%d",&reponse);
            if((reponse < 1 || reponse > 3)) { //N'affichera pas le message d'erreur si l'accisition de l'utilisateur est comprise entre 1 et 3.
                wprintf(L"Vous devez entrez votre réponse entre 1 et 3");
            }
        }while(reponse < 1 || reponse > 3);
        switch (reponse) {
            case 1 :
                fonctEchiquier(pieces);
                quitterboolean = 0;
                break;
            case 2 :
                readfile(pieces);
                quitterboolean = 0;
                break;
            case 3 :
                wprintf(L"vous êtes sur oui ou non?\n");
                scanf("%s",&quitter);
                strlwr(quitter);
                quitterboolean = strcmp(quitter, "oui");
                if(quitterboolean == 0){
                    wprintf(L"A bientot\n");
                }
                break;
        }
    }
}