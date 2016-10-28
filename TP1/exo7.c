/* Ecrit le 03/10/2016 pour TP1 SDA
	CONTACT : snwfdhmp@protonmail.com
*/
#include <stdio.h> //Bibliothèque standard input-output

#define C_TO_F 1
#define F_TO_C 2

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	int choix = 0;
	int temp = 0;
	int convertedTemp = 0;

	//ENTREE
	printf("Choisissez un mode :\nCelsius vers Farhenheit -> 1\nFarhenheit vers Celsius -> 2\nChoix : ");
	while(choix<=0) {
		printf("(Rentrez un nombre n > 0) : ");
		scanf("%d", &choix); //Entrée : choix
		while(getchar()!='\n'); //On vide le buffer
	}
	printf("Entrez la température : ");
	while(temp<=0) {
		printf("(Rentrez un nombre n > 0) : ");
		scanf("%d", &temp); //Entrée : choix
		while(getchar()!='\n'); //On vide le buffer
	}
	//TRAITEMENT

	switch(choix) {
		case C_TO_F :
			convertedTemp = (9*temp)/5+32;
			printf("%d degrés Celsius font %d Farhenheit.\n", temp, convertedTemp);
			break;
		case F_TO_C :
			convertedTemp = (temp-32)*5/9;
			printf("%d degrés Farhenheit font %d Celsius.\n", temp, convertedTemp);
			break;
		default :
			printf("Ce choix n'est pas correct.\n");
			return 1;
		break;
	}
	//SORTIE




	return 0;
}