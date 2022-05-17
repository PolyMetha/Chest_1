//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <io.h>
#include "Savefile.h"
#include "menu.h"

int savefile(){
    _setmode(_fileno(stdout), 0x00020000);
    char save_echiquier[1000];
    FILE* f = fopen("Save.txt","r"); // ouverture du fichier en mode lecture
    if (f!=NULL){ //vérification de l'ouverture
        while(fgets(save_echiquier,1000,f)!=NULL){
            puts(save_echiquier);
        } //lecture du fichier
    }else{
        wprintf(L"raté");
    }
    if (save_echiquier[0] == ' '){                                         //vérification d'enregistrement de la partie
        wprintf(L"Il n'y a aucune partie enregistré\n");//(la partie n'est pas enregistré si le joueur gagne ou perd)
        return 1;
        menu();                                                            //(on affiche le caractère ' ' dans le fichier, on vérifie donc cette information)
    }else{return 0;}
    fclose(f);
}