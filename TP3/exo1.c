

#include <stdio.h>
/* Fonction saisir une valeur
	Objet : capture la saisie de l'utilisateur
	Paramètre : rien
	Retourne : valeur rentrée */

int saisirUneValeur1() {
	int entree;
	scanf("%d", &entree);
	return entree;
}

/* Fonction saisir une valeur
	Objet : capture la saisie de l'utilisateur
	Paramètre : rien
	Retourne : rien */

void saisirUneValeur2(int *nbr) {
	scanf("%d", nbr);
}

/* Fonction affiche une valeur
	Objet : affiche la valeur d'une variable
	Paramètre : la variable
	Affiche : la variable */
void afficherUneValeur1(int V) {
	printf("%d", V);
}


// Programme principal
int main(int argc, char const *argv[])
{
	int menu = 1;
	printf("Choisir une fonction :\n1:int saisir();\n2:void saisir();\nChoix : ");
	scanf("%d", &menu);
	int nombre;
	switch(menu) {
		case 1:
			printf("Saisissez une valeur : ");
			nombre = saisirUneValeur1();
		break;
		case 2:
			printf("Saisissez une valeur : ");
			saisirUneValeur2(&nombre);
		break;
		default:
		break;
	}
	printf("La valeur est : ");
	afficherUneValeur1(nombre);
	printf("\n");
	return 0;
}