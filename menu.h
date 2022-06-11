//
// Created by reini on 06/05/2022.
//

#ifndef CHEST_1_MENU_H
#define CHEST_1_MENU_H

struct piece{
    int id;
    char name;
    char namePiece[20];
};
typedef struct piece piece;
/*
 *  Cette fonction sert de menu, elle n'a pas de paramètre et ne renvoie rien, elle affiche juste le menu et appelle la fonction 'readfile' pour relancer la partie
 *  ou alors fonctEchiquier pour lancer une nouvelle partie.
 */
void menu();

#endif //CHEST_1_MENU_H
