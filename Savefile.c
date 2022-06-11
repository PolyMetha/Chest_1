//
// Created by Quentin BALEZEAU on 07/05/2022.
//

#include <stdio.h>
#include <io.h>
#include "Savefile.h"
#include "echequier.h"
#include "menu.h"

void savefile(piece pieces[],int size, char echiquier[size][size]) {
    /*
     *
     */

    int compteur = 0;
    FILE* f = fopen("Save.txt","w+"); //Ouvre le fichier de sauvegarde (ecriture/lecture + suppression de ce qui a été écrit au paravant)
    if(f!= NULL){ //vérification de l'ouverture
        for(int x=0; x<size;x++) {
            for (int y = 0; y < size; y++) {
                fprintf(f, "%c", echiquier[x][y]); //Ecriture de l'echiquier dans le ficher
            }
        }
    }else {
        wprintf(L"Le fichier 'Save.txt' est introuvable");
        compteur++;
    }
    fclose(f);

    FILE* d = fopen("Size.txt","w");
    if(d != NULL){
        fprintf(d,"%d",size);
    } else {
        wprintf(L"le fichier 'Size.txt est introuvable");
        compteur++;
    }

    fclose(d);
    menu();
    if(compteur != 0){
        wprintf(L"échec de la sauvegarde");
    } else {
        wprintf(L"Votre partie à été enregistré !");
        wprintf(L"voulez-vous continué votre partie?");

    }
}




void readfile(piece pieces[]) {
    int taille = 0;
    FILE *d = fopen("Size.txt", "r"); // ouverture du fichier en mode lecture
    if (d != NULL) {  //vérification de l'ouverture
        fscanf(d, "%d", &taille); //Enregistre la taille de l'ancien échiquier
    }
    fclose(d);

    char Bprises[2 * taille], Nprises[2 * taille];


    FILE *b = fopen("Blancheprises.txt", "w");
    if (b != NULL) {
        fgets(Bprises, 2 * taille, b);
    }
    fclose(b);

    FILE *n = fopen("Noireprises.txt", "w");
    if (n != NULL) {
        fgets(Nprises, 2 * taille, n);
    }
    fclose(n);

    char save_echiquier[taille][taille];
    char c[10];

    FILE *f = fopen("Save.txt", "r");
    if (f != NULL) {
        rewind(f);
        for (int x = 0; x < taille; x++) {
            for (int y = 0; y < taille; y++) {
                if (fgets(c, 2, f) != NULL) {
                    save_echiquier[x][y] = c[0];
                    wprintf(L"%c", save_echiquier[x][y]);
                }
            }
        }
        jeu(taille,save_echiquier,pieces, 0);
    }
    fclose(f);
}