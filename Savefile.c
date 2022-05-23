//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "Savefile.h"
#include "menu.h"

int savefile() {
    _setmode(_fileno(stdout), 0x00020000);
    int taille;

    FILE *d = fopen("Size.txt", "r");
    if (d != NULL) {
        fscanf(d, "%d", &taille);
        wprintf(L"%d\n", taille);
    }
    char save_echiquier[taille+1];
    FILE *f = fopen("Save.txt", "r"); // ouverture du fichier en mode lecture
    if (f != NULL) { //vérification de l'ouverture
        for (int i = 0; i < taille + 5; i++) {
            fgets(save_echiquier, taille+1, f);
            wprintf(L"%s", save_echiquier);
        } //lecture du fichier


    }
}