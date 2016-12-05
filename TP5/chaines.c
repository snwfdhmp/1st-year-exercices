#include <stdio.h>
#include <stdlib.h>
#include "chaines.h"
#include "chaines_tp3.h"


char *decaler(char* ch, int indexDebut, int indexFin) {
	int j =0;
	for (j = indexDebut; j < indexFin ; ++j)
		ch[j] = ch[j+1];
	return ch;
}

char *lire (char * ch){
	int i,j,n = 1;
	fflush(stdin);
	gets(ch);
	unsigned int taille = StringLength(ch) - 1;
	while (n!=0) {
		n = 0;
		for (i = 0; i <= taille; ++i) {
			taille = StringLength(ch) - 1;
			//printf("FOR : i = %d; ch[i] = %c\n", i, ch[i]);
			if (ch[i] == ' ') {
				n = 1;
				if(i == 0 || ch[i+1] == ' ')
					ch = decaler(ch, i, taille);
				else if (i == taille)
					ch[i] = '\0';
				else
					n = 0;
			}
		}
	}
	return ch;
}


int strpos(char * m, char *ch){
	int i,j;
	for (i = 0; i < StringLength(ch); ++i)
	{
		for(j=0; ch[i+j] == m[j]; j++){
			if(j==StringLength(m)-1) {
				return i;
			}
		}
	}
	return -1;
}


char * strmin(char * ch){
	int i;
	unsigned int taille = StringLength(ch);

	for (i = 0; i < taille; ++i) {
		if(ch[i] >= 65 && ch[i] < 97)
			ch[i] += 32;
	}
	return ch;
}

char* premier(char* ch) {
	int i;
	char premier[80];
	for (i = 0; i < StringLength(ch) && ch[i] != ' '; ++i)
	{
		premier[i] = ch[i];
	}
	return premier;
}

