//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <io.h>
#include "Savefile.h"
#include "menu.h"

void savefile(){
    _setmode(_fileno(stdout), 0x00020000);
    char save_echiquier[1000] = " ";
    FILE* f = fopen("Save.txt","r"); // ouverture du fichier en mode lecture
    if (f!=NULL){ //vérification de l'ouverture
        fgets(save_echiquier,1000,f); //lecture du fichier
        wprintf(L"%s",save_echiquier);

    }if (save_echiquier[0] == ' '){                                         //vérification d'enregistrement de la partie
        wprintf(L"Il n'y a aucune partie enregistré\n");             //(la partie n'est pas enregistré si le joueur gagne ou perd)
        menu();                                                            //(on affiche le caractère ' ' dans le fichier, on vérifie donc cette information)
    }
    fclose(f);
}