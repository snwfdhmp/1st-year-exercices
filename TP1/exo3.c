/* Ecrit le 03/10/2016 pour TP1 SDA
	CONTACT : snwfdhmp@protonmail.com
*/
#include <stdio.h> //Bibliothèque standard input-output
#include <math.h> //Bibliothèque mathématiques (pour le sqrt)

void emptyBuffer() { //Fonction pour vider le buffer
	while(getchar()!='\n');
}

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	long double a = 0, b = 0, c = 0; //composantes a,b,c de l'equation
	long double delta = 0; //variable qui contiendra le determinant

	//ENTREE
	printf("f(x) = ax^2+bx+c\nResolution de l'equation f(x) = 0\nEntrez a : ");
	scanf("%Lf", &a); //Entrée : n
	emptyBuffer();
	printf("Entrez b : ");
	scanf("%Lf", &b);
	emptyBuffer();
	printf("Entrez c : ");
	scanf("%Lf", &c);
	emptyBuffer();

	//TRAITEMENT & SORTIE
	delta = b*b - 4*a*c;
	printf("Delta = %.2Lf\n", delta);
	if(a==0) {
		printf("Il n'y a qu'une solution :\nSolution : %.2Lf\n", -c/b);
	}
	else if(delta > 0) {
		long double solutions[2] = {(-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)}; //tableau contenant les solutions
		printf("Il y a deux solutions à cette équation :\nSolution 1 : %.2Lf\nSolution 2 : %.2Lf\n", solutions[0], solutions[1]);
	}
	else if(delta == 0) {
		long double solution = -b/(2*a); //Variable contenant la solution unique
		printf("Il n'y a qu'une seule solution unique à cette équation :\nSolution : %.2Lf\n", solution);
	}
	else {
		printf("Il y a deux solutions complexes\nSolution 1 : %.2Lf+i*%.2Lf\nSolution 2 : %.2Lf-i*%.2Lf\n", -b/(2*a), sqrt(-delta)/2*a, -b/(2*a), sqrt(-delta)/2*a);
	}

	return 0;
}