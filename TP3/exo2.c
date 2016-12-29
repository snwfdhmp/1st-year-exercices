// NOTE : dans ce programme on utilisera les LONG DOUBLE pour
// pouvoir stocker des nombres plus grands

#include <stdio.h>
/* Fonction puissance
	Objet : donne la puissance b de a
	Paramètre : a, b
	Retourne : a^b */

long double puissance1(int a, int b) {
	int i = 0;
	long double result = 1;
	while(i < b) {
		result*=a;
		i++;
	}
	return result;
}
/* Fonction puissance
	Objet : donne la puissance b de a
	Paramètre : a, b, c
	Retourne : rien, assigne a^b dans c */

void puissance2(int a, int b, long double *c) {
	int i = 0;
	*c = 1;
	while(i < b) {
		*c *= a;
		i++;
	}
}

// Programme principal
int main(int argc, char const *argv[])
{

	int menu = 1;
	printf("Choisir une fonction :\n1:int puissance();\n2:void puissance();\nChoix : ");
	scanf("%d", &menu);
	int a = 0, b = 0;
	long double c;
	printf("Entrez une nombre : ");
	scanf("%d", &a);
	printf("Entrez une puissance : ");
	scanf("%d", &b);
	switch(menu) {
		case 1:
			printf("Le resultat est : %.0Lf\n", puissance1(a,b));
		break;
		case 2:
			puissance2(a,b,&c);
			printf("Le resultat est : %.0Lf\n", c);
		break;
		default:
		break;
	}
	return 0;
}