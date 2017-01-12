#include <stdio.h>
#include "menu.h"


int menu(int choix_max, char choix[choix_max][STR_MAX_LEN])
{
	unsigned int i; //Variable de parcours (de tableau, de boucle, ...)
	int c; //Choix de l'utilisateur (signé pour pouvoir handle les entrées incorrectes)

	//Affichage du menu
	for (i = 0; i < choix_max; ++i) //On va afficher toutes les options avec leur numéro correspondant
		AFFICHER_OPT(i+1, choix[i]);

	//Puis on va demander le choix de l'utilisateur, tout en vérifiant qu'il est correct
	do { //On utilise un do{}while pour gérer l'interception des erreurs
		printf("Choix (< %d) : ", choix_max); 
		scanf("%d", &c);
	} while(c > choix_max || choix <= 0); // = tant que le choix est incorrect

	return c;
}