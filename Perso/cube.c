#include <stdio.h>

//Definition de la taille du cube (3x3x3 ou 4x4x4 ou ...)
#define TAILLE_CUBE 3

//Definition des valeurs correspondant aux couleurs
// Ordre : avec rouge de face : rouge -> bleu -> orange -> vert (haut) blanc (bas) jaune
#define ROUGE 1
#define BLEU 2
#define ORANGE 3
#define VERT 4
#define BLANC 5
#define JAUNE 6

char lettreCorrespondantCouleur(int couleur);
void construireCube(int**** cube);
void afficherCube(int*** cube);


void construireCube(int**** cube) {
	int i = 0, j = 0, k = 0;
	int couleurActuelle = ROUGE;
	printf("Indice de la couleur actuelle : %d\nCouleur associée : %c\n", couleurActuelle, lettreCorrespondantCouleur(couleurActuelle));
	for (i = 0; i < TAILLE_CUBE; ++i)
	{
		printf("Passage dans la boucle for de i\n");
		for (j = 0; j < TAILLE_CUBE; ++j)
		{
			printf("Passage dans la boucle for de j\n");
			for (k = 0; k < TAILLE_CUBE; ++k)
			{
				printf("Passage dans la boucle for de k\n");
				printf("Changement de valeur pour cube[%d][%d][%d].", i, j, k);
				*cube[i][j][k] = couleurActuelle;
				printf("cube[%d][%d][%d] = %d\n", i, j, k, couleurActuelle);
			}
		}
		printf("Changement de couleur\n");
		couleurActuelle++;
		printf("La couleur actuelle est maintenant %d\n", couleurActuelle);
	}
}

void afficherCube(int*** cube) {
	int i = 0, j = 0, k = 0;
	for (i = 0; i < TAILLE_CUBE; ++i)
	{
		for (j = 0; j < TAILLE_CUBE; ++j)
		{
			for (k = 0; k < TAILLE_CUBE; ++k)
			{
				printf("%c",lettreCorrespondantCouleur(cube[i][j][k]));
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
}

char lettreCorrespondantCouleur(int couleur) {
	switch(couleur) {
		case 1:
			return 'R';
		break;
		case 2:
			return 'B';
		break;
		case 3:
			return 'O';
		break;
		case 4:
			return 'G';
		break;
		case 5:
			return 'W';
		break;
		case 6:
			return 'Y';
		break;
		default:
			return '?';
		break;
	}
}


int main(int argc, char const *argv[])
{
	int cube[6][3][3];
	construireCube(&cube);
	afficherCube(cube);
	return 0;
}