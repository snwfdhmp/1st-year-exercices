#ifndef MENU_H
#define MENU_H

#define AFFICHER_OPT(a,b) printf("%d : %s\n", a, b); //Fonction macro qui sert à afficher une option
#define STR_MAX_LEN 140

int menu(int choix_max, char choix[choix_max][STR_MAX_LEN]);

#endif