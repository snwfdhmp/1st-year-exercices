#include <stdio.h>

#define MAX_COMPOSANTES 20
#define NBR_ETAPES 5

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
			printf("Une composante nulle a été trouvée, quelle valeur lui assigner ? ");
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

int main(int argc, char const *argv[])
{
	//VARIABLES
	unsigned short int nbrComposantes;
	int etape = 1;

	//TRAITEMENT
	nbrComposantes = getNbrComposantes();
	float composantes[MAX_COMPOSANTES+1]; //possible de mettre composantes[nbrComposantes]

	for(etape = 1; etape != NBR_ETAPES+1; etape++) {
		printf("Que faire :\n1:Initialiser à 0\n2:Changer valeurs\n3:Afficher Tableau\n4:Chercher une valeur nulle\n5:Rechercher un élément\n%d:Quitter\nChoix : ", NBR_ETAPES+1);
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
			case NBR_ETAPES+1:
			break;
			default:
				printf("Entrez un choix valide.\n");
			break;
		}
	}
	return 0;
}