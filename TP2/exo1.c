#include <stdio.h>

#define MAX_COMPOSANTES 20

int main(int argc, char const *argv[])
{
	int nbrComposantes = 1;
	int i = 0;
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
	int composantes[nbrComposantes]; 
	for(i=0;i < nbrComposantes;i++) {
		printf("Composante n°%d : ", i+1);
		scanf("%d", &composantes[i]);
	}
	printf("Liste des composantes :\n");
	for(i=0;i<nbrComposantes;i++) {
		printf("Composante n°%d : %d\n", i+1, composantes[i]);
	}
	return 0;
}