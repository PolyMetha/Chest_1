//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "Savefile.h"
#include "menu.h"
#include "echequier.h"
#include "echequier.c"

void savefile(piece pieces[]) {
    _setmode(_fileno(stdout), 0x00020000);
    int taille;

    FILE *d = fopen("Size.txt", "r");
    if (d != NULL) {
        fscanf(d, "%d", &taille);
        wprintf(L"%d\n", taille);
    }
    char save_echiquier[taille][taille];
    FILE *f = fopen("Save.txt", "r"); // ouverture du fichier en mode lecture
    if (f != NULL) { //vérification de l'ouverture
        for (int i = 0; i < taille; i++) {
            for (int j = 0; j < taille; j++) {
                fscanf(save_echiquier[i][j], "%c", f);
                wprintf(L"%c",save_echiquier);
            }
        }//lecture du fichier
        jeu(taille, save_echiquier, pieces);
    }
}