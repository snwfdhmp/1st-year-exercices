#include <stdio.h>
#include <string.h>

#define ALPHA 7
#define BETA  3

unsigned long int encodeString(char* ch) {
	unsigned int i, taille = strlen(ch);
	unsigned long int hash = 0;
	for (i = 0; i < taille; ++i)
		hash += ch[i];//*ALPHA + BETA; 
	return hash;
}

void saisir_7lettres(char* lettres) {
	do {
		printf("Entrez vos 7 lettres : ");
		scanf("%s", lettres);
	} while(strlen(lettres) > 7);
}

void afficherScore(char* mot) {
	unsigned int sum = 0, taille = strlen(mot), i;
	int points[26]={1,3,3,2,1,4,2,4,1,8,10,1,2,1,1,3,8,1,1,1,1,4,10,10,10,10};

	for (i = 0; i < taille; ++i)
	{
		sum += points[mot[i] - 'A'];
	}

	printf("Bravo, ce mot vaut %u points !\n", sum);
}

void saisir_mot(char *lettres,char *mot) {
	do {
		printf("Entrez votre mot (7 lettres) : ");
		scanf("%s", mot);
	} while(strlen(mot) > 7);
	if (encodeString(lettres)==encodeString(mot))
		afficherScore(mot);
	else
		printf("Erreur : mot incorrect.\n");

}

int main(int argc, char const *argv[])
{
	char input[8], mot[8];

	saisir_7lettres(input);
	saisir_mot(input, mot);

	return 0;
}