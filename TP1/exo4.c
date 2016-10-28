/* Ecrit le 03/10/2016 pour TP1 SDA
	contact : snwfdhmp@protonmail.com
*/


//  /!\ REMARQUE : l'énoncé est faux, il indique e^x = 1+x+x2/2!+x3/3! ....; or, c'est e^x = 1+x+(x^2)/(2!)+(x^3)/(3!) ....

#include <stdio.h> //Bibliothèque standard input-output
#include <math.h> //Bibliothèque maths pour fonction pow(a,b) (a puissance b)

double factoriel(int f) { //fonction renvoyant f!
	double resultat = 1;
	int i = 0;
	for (i = 2; i <= f; ++i)
	{
		resultat*=i;
	}
	return resultat;
}

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	long double resultat = 0; // resultat sera égal à e^x
	int x = -1; //entrée de l'utilisateur
	double p = 0; //précision
	int i = 0; //variable de parcours

	//ENTREE
	while(x<0) {
		printf("Calcul d'e^x -> Rentrez x (>=0) : ");
		scanf("%d", &x); //Entrée : n
		while(getchar()!='\n'); //On vide le buffer
	}
	while(p<=0) {
		printf("Précision p (>0) : ");
		scanf("%lf", &p); //Entrée : n
		while(getchar()!='\n'); //On vide le buffer
	}
	//TRAITEMENT
	for (i = 0; i <= p; ++i)
	{
		resultat+=pow(x,i)/(factoriel(i));
	}

	//SORTIE
	printf("e^x = %Lf\n", resultat);
	return 0;
}








