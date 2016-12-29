#include <stdio.h>

void saisircarre(int* tab[], int taille) {
	printf("Saisie du carre : [ligne;colonne]\n");
	int i = 0;
	int j = 0;
	for (j = 0; j <= taille; ++j)
	{
		for (i = 0; i <= taille; ++i)
		{
			printf("Rentrer la valeur [%d, %d]", i, j);
			scanf("%d", tab[i, j]);
		}
	}
}

void affichercarre();
int sumligne();
int sumcolonne();
int sumdiag1();
int sumdiag2();




int main(int argc, char const *argv[])
{
	const int MAXELT = 10;
	int Tableau[MAXELT+1][MAXELT+1];
	int taille, ligne, colonne, pasmagique;
	int n;
	do {
		printf("Saisir la taille : ");
		scanf("%d", &taille);
	} while((taille<0) || (taille>MAXELT-1));

	saisircarre(Tableau, taille);
	affichercarre(Tableau, taille);

	//Calcul de la somme des lignes
	for(ligne = 1; ligne <= taille; ligne++) {
		Tableau[ligne][taille+1]=sumligne(Tableau, taille, ligne);
	}

	//Calcul de la somme des colonnes
	for(colonne = 1; colonne <= taille; colonne++) {
		Tableau[taille+1][colonne] = sumcolonne(Tableau, taille, colonne);
	}

	//Calcul de la somme des diagonales
	Tableau[taille+1][taille+1] = sumdiag1(Tableau, taille);
	Tableau[0][taille+1] = sumdiag2(Tableau, taille);

	//On verifie si le carre est magique
	colonne = 1;
	pasmagique = 0;

	while(pasmagique==0 && (colonne<=taille)) {
		pasmagique = (Tableau[taille+1][colonne]!=Tableau[taille+1, colonne+1]);
		colonne++;
	}
	ligne = 0;
	while(pasmagique==0 && (ligne<=taille)) {
		pasmagique=(/*ligne*/Tableau[ligne][taille+1]!=Tableau[ligne+1, taille+1]);
		ligne++;
	}

	if(pasmagique==0 && Tableau[taille+1][taille+1] == n*(((n^2)+1)/2)) {
		printf("Le carre est magique !\n");
	}
	else {
		printf("Le carre n'est pas magique !\n");
	}

	return 0;
}