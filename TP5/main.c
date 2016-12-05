#include <stdio.h>
#include <string.h>
#include "chaines.h"
#include "chaines_tp3.h"

#define VIDE(a) strlen(a)==0
#define EGAL(a, b) strcmp(a,b)==0

int main(int argc, char const *argv[])
{
	char bonjour[80];
	char hello[80];
	char mot[80];

	//BLOC TEST DES FONCTIONS PRINCIPALES
	
	printf("Entrez une premiere chaine : ");
	lire(bonjour);

	printf("La chaine entrée est : '%s'\n", bonjour);
	strmin(bonjour);
	printf("La chaine convertie en minuscule est : '%s'\n", bonjour);

	printf("Le premier mot de la chaine est : %s\n", premier(bonjour));
	printf("Tout sauf le premier mot est : %s\n", saufpremier(bonjour));
	printf("Le dernier mot est : %s\n", dernier(bonjour));
	printf("Tout sauf le dernier mot est : %s\n", saufdernier(bonjour));

	/*printf("Rentrez une seconde chaine : ");
	lire(hello);

	printf("La chaine entrée est : '%s'\n", hello);
	strmin(hello);
	printf("La chaine convertie en minuscule est : '%s'\n", hello);
	printf("La phrase formée par les deux chaines est :\n%s\n", phrase(bonjour, hello));*/

	//BLOC TEST PREPROCESSEUR FONCTION VIDE

	/*printf("Entrez une chaine : ");
	gets(bonjour);
	if(VIDE(bonjour))
		printf("La chaine est vide.\n");
	else
		printf("La chaine n'est pas vide.\n");*/

	//BLOC TEST FONCTION PREPROCESSEUR EGAL

	/*printf("Entrez une chaine : ");
	gets(bonjour);
	printf("Entrez une autre chaine : ");
	gets(hello);
	if(EGAL(bonjour, hello))
		printf("Les deux chaines sont identiques.\n");
	else
		printf("Les deux chaines sont différentes.\n");*/



	//BLOC RECHERCHE DE MOT

	/*printf("Quel mot voulez-vous rechercher ? ");
	scanf("%s", mot);
	int pos = strpos(mot, bonjour);
	if(pos == -1) {
		printf("Le mot recherché n'a pas été trouvé.\n");
	}
	else {
		printf("Le mot recherché est à la position %d\n", pos);
	}*/
	return 0;
}