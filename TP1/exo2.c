/* Ecrit le 03/10/2016 pour TP1 SDA
	CONTACT : snwfdhmp@protonmail.com
*/
#include <stdio.h>


int main() 
{
	//VARIABLES
	unsigned long int n = 0; //maximum
	unsigned long int s = 0; //
	unsigned long int i = 0, j = 0; //variables de parcours

	//ENTREE
	while(n<=0) {
		printf("Rentrez un nombre n > 0 : ");
		scanf("%ld", &n); //Entrée : n
		while(getchar()!='\n'); //On vide le buffer
	}

	//TRAITEMENT & SORTIE
	printf("Les nombres parfait compris entre 1 et %ld sont :\n", n);
	for(i=1;i<=n;i++) { 
		//if(i == 33550337) {
			s=0; //somme
			for(j=1;j<=i-1;j++) {
				if(i%j==0) {
					s=s+j;
				}
			}
			if(s==i) //si le nombre est parfait
			{
				printf("%ld\n",i);//alors on l'affiche
			}
		//}
	}

	return 0;
}