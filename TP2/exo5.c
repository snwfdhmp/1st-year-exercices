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
	int jusquou = tailleTableau-1;
	int biggestIndex = 0;
	float tmp;
	while(jusquou > 0) {
		while(i <= jusquou) {
			if(tableau[i] > tableau[biggestIndex]) {
				printf("%f est plus grand que %f\n", tableau[i], tableau[biggestIndex]);
				biggestIndex = i;
			}
			i++;
		}
		i--;
		printf("Sortie de boucle i : i = %d, jusquou = %d, biggest = %f\n", i, jusquou, tableau[biggestIndex]);
		printf("Permutation : stockage tmp <- %f\n", tableau[biggestIndex]);
		tmp = tableau[biggestIndex];
		printf("Permutation : stockage tab[bigg] <- %f\n", tableau[i]);
		tableau[biggestIndex] = tableau[i];
		printf("Permutation : stockage tab[i] <- %f\n", tmp);
		tableau[i] = tmp;
		afficherTableau(tableau, tailleTableau);
		jusquou--;
		i=0;
		printf("Recommence boucle while avec jusqou = %d\n", jusquou);
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
	return 0;
}