/* Ecrit le 03/10/2016 pour TP1 SDA
	CONTACT : snwfdhmp@protonmail.com
*/
#include <stdio.h> //Bibliothèque standard input-output

#define NBR_PIECES 8

void emptyBuffer() { //Fonction pour vider le buffer
	while(getchar()!='\n');
}

int main(int argc, char const *argv[]) //Fonction principale
{
	//VARIABLES
	double somme = 0; //Somme d'argent
	double reste = somme; //Somme d'argent qui n'a pas encore été rendue
	double pieces[NBR_PIECES] = {2,1,0.5,0.2,0.1,0.05,0.02,0.01}; //Liste des pieces disponibles
	int nombrePieces[NBR_PIECES]; //Nombre de pieces de chaque type de piece
	int i = 0; //variable de parcours, pour le for

	//ENTREE
	printf("Entrez une somme d'argent >0 : ");
	scanf("%lf", &somme); //Entrée d'un réel somme

	//TRAITEMENT & sortie
	reste = somme; //Reste à donner
	for (i = 0; i < NBR_PIECES; ++i)
	{
		nombrePieces[i] = reste/pieces[i];
		reste = reste - nombrePieces[i] * pieces[i];
	}

	//SORTIE
	printf("Il vous sera rendu:\n");
	for (i = 0; i < NBR_PIECES; ++i)
	{
		if(nombrePieces[i] != 0) {
				printf("%d pieces de %.2f€\n", nombrePieces[i], pieces[i]);
		}
	}
	return 0;
}