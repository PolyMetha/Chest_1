//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "Savefile.h"
#include "menu.h"

void savefile() {
    /*
     * Le but de la fonction save file est de pouvoir lire les fichiers sauvegardes, pour plus de simplicité il y a deux
     * fichiers sauvegardes, l'un sauvegarde la taille l'autre sauvegarde l'échiquier en entier.
     * La fonciton savefile ouvre le premier fichier contenant la taille de l'échiquier (cette valeur à été enregistré à la
     * fin de la précédente partie), ensuite créé un tableau à deux dimension pour le remplir caractère par caractère
     * via l'ouverture du second fichier contenant l'échiquier. Les fichiers sont fermé après utilisations.
     */

    int taille = 0;
    FILE* d = fopen("Size.txt", "r");
    if (d != NULL) {
        fscanf(d, "%d", &taille);
    }
    fclose(d);
    char save_echiquier[taille][taille];
    char c[10];

    FILE *f = fopen("Save.txt", "r"); // ouverture du fichier en mode lecture
    if (f != NULL) { //vérification de l'ouverture
        rewind(f);
        for (int x = 0; x < taille; x++){
            for (int y = 0; y < taille; y++) {
                if(fgets(c,2,f) != NULL){
                    save_echiquier[x][y] = c[0];
                    printf("%c",save_echiquier[x][y]);
                }
            }
            printf("\n");
        }
    }
}