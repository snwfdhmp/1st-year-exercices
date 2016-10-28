/* Ecrit le 03/10/2016 pour TP1 SDA
	CONTACT : snwfdhmp@protonmail.com
*/
#include <stdio.h> //Bibliothèque standard input-output
#include <string.h>

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	int n = 0; //Nombre de nombres impairs à additionner
	int i = 0; //Variable de parcous, utile pour le for

	//ENTREE
	while(n<=0) {
		printf("Rentrez un nombre n > 0 : ");
		scanf("%d", &n); //Entrée : n
		while(getchar()!='\n'); //On vide le buffer
	}
	//TRAITEMENT
	printf("Les %d premiers termes de la constante de Champernowne sont 0.", n);
	for (i = 1; i <= n; ++i)
	{
		printf("%d",i);
	}
	printf("\n");
	//SORTIE
	return 0;
}