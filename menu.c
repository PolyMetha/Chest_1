//
// Created by reini on 06/05/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io.h>             //requis pour imprimer les caractères en unicodes
#include <conio.h>
#include <time.h>
#include <windows.h>
=======
#include "echequier.h"
#include "menu.h"
#include "Savefile.h"

void menu (){
    _setmode(_fileno(stdout), 0x00020000);
    int reponse;
    char quitter[3] = "oui";
    int quitterboolean = 1;
    while(quitterboolean != 0){
        wprintf(L"\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\n");
        wprintf(L"1 - Demarrer une partie\n");
        wprintf(L"2 - Reprendre une partie\n");
        wprintf(L"3 - Quitter\n");
        wprintf(L"\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\x2500\n");

        do {                                 //Vérification de l'accisition de l'utilisateur.
            scanf("%d",&reponse);
            if((reponse < 1 || reponse > 3)) { //N'affichera pas le message d'erreur si l'accisition de l'utilisateur est comprise entre 1 et 3.

=======
                wprintf(L"Vous devez entrez votre réponse entre 1 et 3");
            }
        }

        while(reponse < 1 || reponse > 3);
        system("cls");
        switch (reponse) {
            case 1 :
                //fonction d'andréa
                fonctEchiquier();
                quitterboolean = 1;
                break;
            case 2 :
                // le fameux ficher sauvegarde que inchallah je sais pas comment codé ca.
                savefile();
                quitterboolean = 1;
                break;
            case 3 :
                wprintf(L"vous êtes sur oui ou non?\n");
                scanf("%s",&quitter);
                strlwr(quitter);
                quitterboolean = strcmp(quitter, "oui");
                if(quitterboolean == 0){
                    wprintf(L"A bientot\n");
                    Sleep(1000);
                }
                break;
        }
    }
}
