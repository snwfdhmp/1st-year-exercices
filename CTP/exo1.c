#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int saisir_entier(const int max) {
	int n;
	do {
		printf("Saisissez un nombre positif inférieur ou égal à %d : ", max);
		scanf("%d", &n);
	} while(n > max || n <= 0);
	return n;
}

void saisir_texte(char *chaine_a_saisir, int longueur) {
	chaine_a_saisir = (char*) malloc(sizeof(char) * (longueur+1));
	char str[100];
	unsigned short int i, boolInvalide = 0;
	do {
		printf("Saisissez une chaine de %d caractères (seulement minuscule) : ", longueur);
		scanf("%s", str);
		for(i=0;i<strlen(str);i++)
			boolInvalide += (str[i] < 97 || str[i] >= 122);

	} while(strlen(str) != longueur || boolInvalide);



	strcpy(chaine_a_saisir, str);
}

char* encode_texte(char* chaine_a_encoder, int longueur){
	unsigned int i, j, k = 0;
	char output[41];

	for (i = 0; i < longueur; i+=j)
	{
		for(j = 0; chaine_a_encoder[i+j] == chaine_a_encoder[i]; ++j);
		output[2*k] = j + '0';
		output[2*k+1] = chaine_a_encoder[i];
		k++;
	}
	output[2*k] = '\0';

	return output;
}

int main(int argc, char const *argv[])
{
	int n;
	char *ch, output[41];
	unsigned int i,j,k = 0;

	n = saisir_entier(20); // 20 -> MAX

	saisir_texte(ch, n);

	printf("%s\n", encode_texte(ch, n));

	return 0;
}