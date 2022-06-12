//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

#include "fonctions.h"
#include "Savefile.h"
#include "echequier.h"
#include "menu.h"

int savefile(piece pieces[], int size, char echiquier[size][size], int tourdujoueur) {
    /*
     *
     */

    int compteur = 0;
    int reponseboolean = 0;
    char reponse[3] = "oui";

    FILE *f = fopen("Save.txt",
                    "w"); //Ouvre le fichier de sauvegarde (ecriture/lecture + suppression de ce qui a été écrit au paravant)
    if (f != NULL) { //vérification de l'ouverture
        fprintf(f, "%d\n", size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fprintf(f, "%c", echiquier[i][j]);
            }
        }
        fprintf(f, "\n%d", tourdujoueur);
    } else {
        wprintf(L"Le fichier 'Save.txt' est introuvable\n");
        compteur++;
    }
    fclose(f);

    if (compteur != 0) {
        wprintf(L"échec de la sauvegarde\n");
    } else {
        wprintf(L"Votre partie à été enregistré !\n");
        wprintf(L"voullez-vous reprendre votre partie ? (oui ou non?)\n");
        scanf("%s", &reponse);
        strlwr(reponse);
        reponseboolean = strcmp(reponse, "oui");
        if (reponseboolean == 0) {
            jeu(size, echiquier, pieces, tourdujoueur);
        } else {
            wprintf(L"retour au menu...\n");
            return 2;

        }
    }
}


void readfile(piece pieces[]) {

    int tourdujoueur = 0;
    int size = 0;
    char stock[10];
    int test = 0;
    FILE *f = fopen("Save.txt", "r"); // ouverture du fichier en mode lecture

    if (f != NULL && fgets(stock,2,f) != NULL){  //vérification de l'ouverture
        rewind(f);
        fscanf(f, "%d\n", &size); //Enregistre la taille de l'ancien échiquier
        char save_echiquier[size][size];
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                if (fgets(stock, 2, f) != NULL) {
                    save_echiquier[x][y] = stock[0];
                } else { wprintf(L"il n'y a pas de partie enregistré");
                }
            }
        }
        fscanf(f, "%d\n", &tourdujoueur);
        fclose(f);
        jeu(size, save_echiquier, pieces, tourdujoueur);
        menu();
    }else{wprintf(L"Pas de partie enregristé");
        menu();}




}