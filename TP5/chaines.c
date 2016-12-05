#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chaines.h"
#include "chaines_tp3.h"

#define VIDE(a) strlen(a)==0


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

char* saufpremier(char* ch) {
	int i,j;
	char saufpremier[80];
	for (i = 0; i < StringLength(ch) && ch[i] != ' '; ++i)
	{
	}
	for (j=0; i+j < StringLength(ch); j++) {
		saufpremier[j] = ch[i+j];
	}
	return saufpremier;
}

char *phrase (char * ch1, char * ch2) {
	char ch3[80];
	int taille1 = StringLength(ch1);
	int taille2 = StringLength(ch2);
	//printf("Les chaines a concatener sont '%s' et '%s'\n", ch1, ch2);
	int i,j;
	if(taille1+taille2 >= 80) {
		//printf("[ATTENTION] La taille de la jonction des deux chaines dépasse 80 caractères ...\nLa deuxième chaine sera coupée.\n");
	}
	for (i = 0; i < taille1; ++i)
	{
		//printf("ch3[%d] = %c\n",i, ch1[i]);
		ch3[i] = ch1[i];
	}
	//printf("FIN de la premiere chaine, i = %d\n", i);
	ch3[i] = ' ';
	i+=1;
	for (j=0; (j < taille2-0) && (i+j < 80); j++) {
		//printf("ch3[%d] = %c\n",i+j, ch2[j]);
		ch3[i+j] = ch2[j];
	}

	//printf("ch3 = %s\n", ch3);
	return ch3;
}

char * dernier(char * ch) {
	char dernier[80];
	int i,j,indexDernierEspace = 0;
	int taille = StringLength(ch);
	for (i = 0; i < taille; ++i)
	{
		if(ch[i] == ' ') {
			indexDernierEspace = i;
		}
	}
	indexDernierEspace++;
	for (i = 0; indexDernierEspace+i < taille; ++i)
	{
		printf("dernier[%d] = %c  (ch[%d])\n", i, ch[indexDernierEspace+i], indexDernierEspace+i);
		dernier[i] = ch[indexDernierEspace+i];
	}
	dernier[i] = '\0';
	return dernier;
}

char * saufdernier(char * ch) {
	char saufdernier[80];
	int i,j,indexDernierEspace = 0;
	int taille = StringLength(ch);
	for (i = 0; i < taille; ++i)
	{
		if(ch[i] == ' ') {
			indexDernierEspace = i;
		}
	}
	for(i=0; i < indexDernierEspace; i++) {
		saufdernier[i] = ch[i];
	}
	return saufdernier;
}
