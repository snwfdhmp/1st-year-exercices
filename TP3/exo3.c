

#include <stdio.h>
/* Fonction factorielle
	Objet : donne la factorielle de a
	Paramètre : a
	Retourne : a! */

long double factoriel1(int a) {
	int i = 1;
	long double result = 1;
	while(i <= a) {
		result*=i;
		i++;
	}
	return result;
}
/* Fonction factorielle
	Objet : donne la factorielle de a
	Paramètre : a
	Retourne : rien, assigne a! dans c */

void factoriel2(int a, long double *c) {
	int i = 1;
	*c = 1;
	while(i <= a) {
		*c *= i;
		i++;
	}
}

// Programme principal
int main(int argc, char const *argv[])
{

	int menu = 1;
	printf("Choisir une fonction :\n1:int factorielle();\n2:void factorielle();\nChoix : ");
	scanf("%d", &menu);
	int a = 0, b = 0;
	long double c;
	printf("Entrez une nombre : ");
	scanf("%d", &a);
	switch(menu) {
		case 1:
			printf("Le resultat est : %.0Lf\n", factoriel1(a));
		break;
		case 2:
			factoriel2(a,&c);
			printf("Le resultat est : %.0Lf\n", c);
		break;
		default:
		break;
	}
	return 0;

}