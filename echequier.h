//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_ECHEQUIER_H
#define CHEST_1_ECHEQUIER_H
#include "menu.h"
/**
 * Lance la génération de l'échiquier et le jeu
 */
void fonctEchiquier();
void printEchiquier(int size, char echiquier[size][size]);
/**
 * cherche la position des deux rois et les renvoie dans deux tableaux a une dimension,
 * le deux veleurs de ces tableaux prennent donc
 * des int de 0 à size
 */
void searchRoi(int size, char[size][size], int[], int[]);
/**
 * génère l'échiquier, piece[] sert a trouver les identifians et les nms des pieces dans la structure, la taille
 * prend des valeurs de 6 a 12, même chose pour toutes les fonctions prenant size en paramètre
 * echiquier[size][size] est le tableau a 2 dimension représentant l'échiquier
 */
void generation(piece[], int size, char echiquier[size][size]);
/**
 * Detecte si il y'a echec pour le roi noir ou le roi blanc en parcourant l'échiquier et en trouvant les pièces
 * suceptibles de représenter un danger pour le roi, retourne 1 si echec, 0 si echec et mat
 */
int IsEchecB(int size, char[size][size], piece[]);
int IsEchecN(int size, char[size][size], piece[]);
/**
 * Détecte l'échec et mat pour le roi noir ou blanc en verifiant les éventuelles échapatoires du roi dans une copie
 * de l'échiquier, si le roi n'est pas en danger sur cette nouvelle positions, alors la fonction renvoie 0
 * Sinon, on vérifie en parcourant l'échiquier si une pièce alliée peut nous défendre, renvoie 0 si c'est la cas
 * 1 si les deux boucles précédentes n'ont pas trouvé de solution
 */
int EchecEtMatN(int size, char[size][size], piece[], int[2]);
int EchecEtMatB(int size, char[size][size], piece[], int[2]);
/**
 * Renvoie l'ID d'une pièce dans un pointeur en fonction de son nom 'name' dans la structure des pièces
 */
void searchID(char name, int *pieceID, piece[]);
/**
 * Effectue toutes les verifications nécéssaires pour que le jeu se déroule bien, notamment les permissions de jouer
 * lorsque l'on est en échec, si on selectionne une piece de notre couleur etc
 */
int jeu(int size, char echiquier[size][size], piece[], int);

#endif //CHEST_1_ECHEQUIER_H
