#include <stdio.h>
#include "chaines.h"
#include "chaines_tp3.h"

int main(int argc, char const *argv[])
{
	char bonjour[80];
	lire(bonjour);
	printf("La chaine entrée est : '%s'\n", bonjour);
	printf("La chaine convertie en minuscule est : '%s'\n", strmin(bonjour));
	return 0;
}