#include <stdio.h>

#define MAX_COMPOSANTES 20
#define NBR_ETAPES 6

int getNbrComposantes(){
	int nbrComposantes = 0;
	do {
		printf("Combien de composantes ? ");
		scanf("%d", &nbrComposantes);

		if(nbrComposantes>MAX_COMPOSANTES) {
			printf("Moins de 20 composantes !!!\n");
		}
		else if(nbrComposantes<=0) {
			printf("Minimum 1 composante !");
		}
	}while(nbrComposantes > MAX_COMPOSANTES || nbrComposantes <= 0);
	return nbrComposantes;
}

void initTableau(float* tableau, int tailleTableau) {
	unsigned short int i = 0;
	for(i=0; i<tailleTableau; i++) {
		tableau[i] = 0;
	}
	tableau[tailleTableau] = -1;
}

void setTableau (float* tableau, int tailleTableau) {
	unsigned short int i = 0;
	for(i=0;i < tailleTableau;i++) {
		printf("Composante n°%d : ", i+1);
		scanf("%f", &tableau[i]);
	}
}

void afficherTableau(float* tableau, int tailleTableau) {
	unsigned short int i = 0;
	printf("Le vecteur est le suivant : u(");
	for(i=0;i<tailleTableau;i++) {
		printf("%.2f", tableau[i]);
		if(i<tailleTableau-1) {
			printf(";");
		}
	}
	printf(")\n");
}
void lookForNull(float* tableau, int tailleTableau) {
	unsigned short found = 0;
	int i = 0;
	for(i=0; found==0 && i<tailleTableau; i++) {
		if(tableau[i] == 0) {
			float newValue=1;
			printf("Une composante nulle a été trouvée en position %d, quelle valeur lui assigner ? ", i+1);
			scanf("%f", &newValue);
			tableau[i] = newValue;
			found = 1;
			afficherTableau(tableau, tailleTableau);
		}
	}
}

int searchForElement(float* tableau, int tailleTableau) {
	float el = 0;
	unsigned short int i = 0;
	printf("Entrez l'élément à rechercher : ");
	scanf("%f", &el);
	tableau[tailleTableau] = el;
	while(tableau[i]!=el) i++;
	if(i<tailleTableau) {
		printf("Element trouvé ! Sa première occurence dans le tableau est la %de composante\n", i+1);
		return 1;
	}
	printf("Element non trouvé (valeur de retour : 0)\n");
	return 0;
}

/*void triSelect(float* tableau, int tailleTableau) {
	unsigned short int i = tailleTableau;
	short int reste = tailleTableau;
	float biggest = tableau[tailleTableau];
	int biggestIndex = tailleTableau;
	while(tailleTableau-reste < tailleTableau) {
		for (i = tailleTableau; i >= tailleTableau-reste+1; --i)
		{
			if(tableau[i] > biggest) {
				biggest = tableau[i];
				biggestIndex = i;
			}
		}
			tableau[biggestIndex] = tableau[tailleTableau-reste];
			tableau[tailleTableau-reste] = biggest;
			biggest = tableau[tailleTableau];
			biggestIndex = tailleTableau;
		reste--;
	}
	afficherTableau(tableau, tailleTableau);
}*/
void triSelect(float* tableau, int tailleTableau) { //Ne marche pas encore
	int i = 0;
	int reste = tailleTableau;
	int biggestIndex = 0;
	float nouveauTableau[tailleTableau];
	initTableau(nouveauTableau, tailleTableau);
	while (reste > 0) {
		for (i = 0; i < reste; ++i)
		{
			if(tableau[biggestIndex] < tableau[i]) {
				biggestIndex = i;
			}
		}
		float tmp = tableau[reste-1];
		tableau[reste-1] = tableau[biggestIndex];
		tableau[biggestIndex] = tmp;
		biggestIndex = 0;
		reste--;
	}

	afficherTableau(tableau, tailleTableau);
}


int main(int argc, char const *argv[])
{
	//VARIABLES
	unsigned short int nbrComposantes;
	unsigned short int etape = 1;

	//TRAITEMENT
	nbrComposantes = getNbrComposantes();
	float composantes[MAX_COMPOSANTES+1]; //possible de mettre composantes[nbrComposantes]

	/* Pour cet exercice, nous avons utilisé une autre façon de procéder que celle des menus.
		Cette approche de l'éxécution par étape est intéressante car elle permet de comprendre exactement
		ce que fait le programme et dans quel ordre.
		Pour voir comment j'ai effectué le menu de navigation, se référer aux autres exercices.
	*/

	for(etape = 1; etape <= NBR_ETAPES; etape++) {
		switch(etape) {
			case 1:
			initTableau(composantes, nbrComposantes);
			break;
			case 2:
			setTableau(composantes, nbrComposantes);
			break;
			case 3:
			afficherTableau(composantes, nbrComposantes);
			break;
			case 4:
			lookForNull(composantes, nbrComposantes);
			break;
			case 5:
			searchForElement(composantes, nbrComposantes);
			break;
			case 6:
			triSelect(composantes, nbrComposantes);
			break;
		}
	}

	/* Voici tout de même le menu, au cas où vous auriez besoin de vérifier le bon fonctionnement du programme avec
	 le menu.
	 Il est nécéssaire de commenter la boucle for située au dessus */
	/* for(etape = 1; etape <= NBR_ETAPES; etape++) {
		printf("Que faire :\n1:Initialiser à 0\n2:Changer valeurs\n3:Afficher Tableau\n4:Chercher une valeur nulle\n5:Rechercher un élément\n6:Tri sélection\n%d:Quitter\nChoix : ", NBR_ETAPES+1);
		scanf("%d", &etape);
		switch(etape) {
			case 1:
				initTableau(composantes, nbrComposantes);
			break;
			case 2:
				setTableau(composantes, nbrComposantes);
			break;
			case 3:
				afficherTableau(composantes, nbrComposantes);
			break;
			case 4:
				lookForNull(composantes, nbrComposantes);
			break;
			case 5:
				searchForElement(composantes, nbrComposantes);
			break;
			case 6:
				triBulle(composantes, nbrComposantes);
			break;
			case NBR_ETAPES+1:
			break;
			default:
				printf("Entrez un choix valide.\n");
			break;
		}
	} */

	return 0;
}