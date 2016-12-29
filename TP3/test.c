#include <stdio.h>
#define MAXELT_CARRE 10


void initCarre(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille){
	int i=0, j=0;
	for (j = 0; j < taille; ++j)
	{
		for (i = 0; i < taille; ++i)
		{
			tab[i][j] = 0;
			defined[i][j] = 0;
		}
	}
}
void clearConsole() {
	int i = 0;
	int tailleConsole = 100;
	for (i = 0; i < tailleConsole; ++i)
	{
		printf("\n");
	}
}


void afficherCarre(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille) {
	int i=0, j=0;
	for (j = 0; j < taille; ++j)
	{
		for (i = 0; i < taille; ++i)
		{
			if(defined[i][j]) {
				printf("%d\t", tab[i][j]);
			}
			else {
				return;
			}
		}
		printf("\n");
	}
}

void saisircarre(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille) {
	printf("Saisie du carre : [ligne;colonne]\n");
	int i = 0;
	int j = 0;
	for (j = 0; j < taille; ++j)
	{
		for (i = 0; i < taille; ++i)
		{
			if(!defined[i][j]) {
				clearConsole();
				printf("Saisissez les valeurs :\n");
				afficherCarre(tab, defined, taille);
				scanf("%d", &tab[i][j]);
				defined[i][j] = 1;
			}
		}
	}
}

int sumligne(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille, int ligne) {
	int i = 0;
	int somme = 0;
	for (i = 0; i < taille; ++i)
	{
		if(defined[i][ligne]) {
			somme+=tab[i][ligne];
		}
	}
	return somme;
}

int sumcolonne(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille, int colonne) {
	int j = 0;
	int somme = 0;
	for (j = 0; j < taille; ++j)
	{
		if(defined[colonne][j]) {
			somme+=tab[colonne][j];
		}
	}
	return somme;
}
int sumdiag1(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille) {
	int i = 0, j = 0;
	int somme = 0;
	for (i = 0; i < taille; ++i)
	{
		if(defined[i][j]) {
			somme+=tab[i][j];
		}
		++j;
	}
	return somme;
}
int sumdiag2(int tab[MAXELT_CARRE+1][MAXELT_CARRE+1], int defined[MAXELT_CARRE+1][MAXELT_CARRE+1], int taille) {
	//printf("Diag2\n
	int i = 0, j = 0;
	int somme = 0;
	for (i = taille-1; i >= 0; --i)
	{
		if(defined[i][j]) {
			somme+=tab[i][j];
		}
		++j;
	}
	return somme;
}

int main(int argc, char const *argv[])
{
	//Definition des constantes
	const int MAXELT = MAXELT_CARRE;
	int taille = 2;

	//Declaration des tableaux
	int Tableau[MAXELT+1][MAXELT+1];
	int Defined[MAXELT+1][MAXELT+1];//Tableau qui sert à savoir si la case actuelle a été déjà entrée par l'utilisateur
	//saisircarre(Tableau, 2);
	int ligne, colonne, pasmagique;

	do {
		printf("Saisir la taille : ");
		scanf("%d", &taille);
	} while((taille<0) || (taille>MAXELT-1));

	initCarre(Tableau, Defined, taille);
	saisircarre(Tableau, Defined, taille);


	for(ligne = 0; ligne < taille; ligne++) {
		Tableau[ligne][taille+1]=sumligne(Tableau, Defined, taille, ligne);
		printf("Somme ligne %d : %d\n", ligne+1, Tableau[ligne][taille+1]);
	}

	for(colonne = 0; colonne < taille; colonne++) {
		Tableau[taille+1][colonne] = sumcolonne(Tableau, Defined, taille, colonne);
		printf("Somme colonne %d : %d\n", colonne+1, Tableau[taille+1][colonne]);
	}
	Tableau[taille+1][taille+1] = sumdiag1(Tableau, Defined, taille);
	printf("Somme diag 1 : %d\n", Tableau[taille+1][taille+1]);

	Tableau[0][taille+1] = sumdiag2(Tableau, Defined, taille);
	printf("Somme diag 2 : %d\n", Tableau[0][taille+1]);

	colonne = 0;
	pasmagique = 0;

	while(pasmagique==0 && (colonne<taille)) {
		pasmagique = (Tableau[taille+1][colonne]!=Tableau[taille+1][colonne+1]);
		colonne++;
	}
	ligne = 0;
	while(pasmagique==0 && (ligne<taille)) {
		pasmagique=(Tableau[ligne][taille+1]!=Tableau[ligne+1][taille+1]);
		ligne++;
	}

	if(pasmagique==0 /*&& Tableau[taille+1][taille+1] == taille*(((taille^2)+1)/2)*/) {
		printf("Le carre est magique !\n");
	}
	else {
		printf("Le carre n'est pas magique !\n");
	}

	return 0;
}