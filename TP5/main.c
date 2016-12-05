#include <stdio.h>
#include "chaines.h"
#include "chaines_tp3.h"

int main(int argc, char const *argv[])
{
	char bonjour[80];
	char mot[80];

	lire(bonjour);

	printf("La chaine entrée est : '%s'\n", bonjour);
	strmin(bonjour);
	printf("La chaine convertie en minuscule est : '%s'\n", bonjour);

	printf("Le premier mot de la chaine est : %s\n", premier(bonjour));

	printf("Quel mot voulez-vous rechercher ? ");
	scanf("%s", mot);
	int pos = strpos(mot, bonjour);
	if(pos == -1) {
		printf("Le mot recherché n'a pas été trouvé.\n");
	}
	else {
		printf("Le mot recherché est à la position %d\n", pos);
	}
	return 0;
}