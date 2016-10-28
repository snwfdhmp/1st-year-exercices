#include <stdio.h> //Bibliothèque standard input-output

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	int n = 0; //Nombre de nombres impairs à additionner
	unsigned int i; //Variable de parcours, utile pour le for
	unsigned int nombreImpairActuel = 1; //Contient le i-ème nombre impair
	unsigned int somme = 0; //Contiendra la somme des n premiers nombres impairs

	//ENTREE
	while(n<=0) {
		printf("Rentrez un nombre n > 0 : ");
		scanf("%d", &n); //Entrée : n
		while(getchar()!='\n'); //On vide le buffer
	}

	//TRAITEMENT
	for (i = 0; i < n; ++i)
	{
		somme+=nombreImpairActuel; //A la somme est ajoutée le i-ème nombre impair
		nombreImpairActuel+=2; //Calcul du i+1-ème nombre impair
	}

	//SORTIE
	printf("La somme des %d premiers nombres impairs est %d\n", n, somme); //Affichage du résultat
	return 0;
}