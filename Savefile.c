//
// Created by Quentin BALEZEAU on 07/05/2022.
//
#include <stdio.h>
#include <io.h>

#include "Savefile.h"
void savefile(){
    _setmode(_fileno(stdout), 0x00020000);
    char save_echiquier[256] = " ";
    FILE* f = fopen("Save.txt","r"); // ouverture du fichier en mode lecture
    if (f!=NULL){ //vérification de l'ouverture
        fgets(save_echiquier,256,f); //lecture du fichier
    }
    fclose(f);
}