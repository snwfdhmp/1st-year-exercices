#include <stdio.h>
#include <stdlib.h>


#define  MAX	80

typedef char TCHAINE[MAX];


//Prototypes des fonctions



int StringLenght(const char *);
char *StringCopy(char*, const char*);
char *StringNCopy(char*, const char*, int);
char* StringConcat(char*, const char*);
char* StringNConcat(char*, const char*, int);
int StringCompare(const char*, const char*);

int menu();

main()
{
 TCHAINE chaine1,chaine2;
 int choix;
 int n;

do
{
choix=menu();
switch (choix) {
case 1 : printf("\n\t\t\tEntrer une chaine de caracteres : ");
	   fflush(stdin);
 	   gets(chaine1);
	   printf("\n\t\t\t La longueur de  '%s' est : %d \n\n", chaine1,StringLenght(chaine1));
	   break;

case 2 : printf("\n\t\t\tEntrer une chaine de caracteres : ");
 	   gets(chaine1);
	   StringCopy(chaine2,chaine1);
	   printf("\n\t\t\t La chaine2 est  '%s' \n\n", chaine2);
	   break;
case 3 : 

	 printf("Entrez la chaine de caracteres : ");
	 gets(chaine1);
	 printf("Conbien de lettres voulez vous copier dans le mot\n");
	 scanf("%d", &n);
	 //StringNCopy(chaine2, chaine1,n);
	 printf(" Le nouveau mot est %s\n", StringNCopy(chaine2, chaine1,n));
	 break;
	 
case 4 : /* StringConcat */
	 	printf("Ecrivez la chaine 1 : ");
	 	fflush(stdin);
		gets(chaine1);
		printf("Ecrivez la chaine 2 : ");
		fflush(stdin);
		gets(chaine2);
  	 	//StringConcat(chaine2, chaine1);
  	 	printf("%s\n", StringConcat(chaine2, chaine1));
	 break;
case 5 : /* StringNConcat */

  	 	printf("Ecrivez la chaine 1 : ");
	 	fflush(stdin);
		gets(chaine1);
		printf("Ecrivez la chaine 2 : ");
		fflush(stdin);
		gets(chaine2);
		printf("Conbien de lettres voulez vous concatener : ");
	 	scanf("%d", &n);
	 	printf("La concatenation de chaine 1 et 2 donne : %s",StringNConcat(chaine2,chaine1,n));
	 break;
case 6 : /* StringCompare */
  	 	printf("Ecrivez la chaine 1 : ");
	 	fflush(stdin);
		gets(chaine1);
		printf("Ecrivez la chaine 2 : ");
		fflush(stdin);
		gets(chaine2);
		StringCompare(chaine1,chaine2);
		if (StringCompare(chaine2,chaine1) == 0)
			printf("Les deux chaines sont differentes\n");
		else printf("Les deux chaines sont egales\n");
	 break;	
case 9 : // Option pour quitter
	 break;	
default : printf("\n\n Cas imprevu !!! \n\n");
	}
}
while (choix!=9);
	 

 return 1;
}



int menu()
{
  int choix;
  printf("\n\t\t\t\t 1 - Longueur d'une chaine ");  
  printf("\n\t\t\t\t 2 - Copie d'une chaine ");
  printf("\n\t\t\t\t 3 - Copie de N caracteres d'une chaine ");
  printf("\n\t\t\t\t 4 - Concatenation de deux chaines ");
  printf("\n\t\t\t\t 5 - Concatenation d'une chaine destination et des N caracteres de la chaine source ");
  printf("\n\t\t\t\t 6 - Comparaison de deux chaines");
  printf("\n\t\t\t\t 9 - Quitter");
 printf("\n\n\t\t\t\t Votre choix : "); 
 scanf("%d",&choix);
 getchar(); // vide le RC du buffer
 return choix;
}


/***************************************************************************/
/* NOM FONCTION : StringCopy						   */
/* DESCRIPTION :  Retourne une copie de la chaine s1		           */
/* Retourne :dest (chaine de caractères)			   	   */
/* Effets de bords : 			                                   */
/* Paramètres en entree : src (chaine  source)	                   	   */
/* Paramètres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringCopy(char* dest, const char* src)
{
int i=0;
while (dest[i]=src[i]) i++;
 
  return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringLenght					   */
/* DESCRIPTION : calcule la longueur de la chaine passee en parametres     */
/* Retourne : int (valeur de la longueur)				   */
/* Effets de bords : 			                                   */
/* Paramètres en entree :ch1 (const TCHAINE)                                 */
/* Paramètres en sortie :      			                           */
/***************************************************************************/

int StringLenght(const char *ch)
{
	int i=0;
	while (ch[i] != '\0')
		i++;
  
  return i;
}



/***************************************************************************/
/* NOM FONCTION : StringNCopy						   */
/* DESCRIPTION :  Retourne l'adresse de la chaine dest		           */
/* Retourne :dest (chaine de caractères)			   	   */
/* Effets de bords : 			                                   */
/* Paramètres en entree : src (chaine  source)				   */
/*			  n (nombre de caracteres a copier)		   */
/* Paramètres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringNCopy(char *dest, const char* src, int n)
{
 int i=0;

 for (i =0; i < n; i++)
 {
 	 (dest[i]=src[i]);
 }

return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringConcat						   */
/* DESCRIPTION :  Concatene dest+src				           */
/* Retourne :dest (chaine de caractères obtenue par contenation de deux src*/
/* Effets de bords : 			                                   */
/* Paramètres en entree : dest et src (chaines  sources)	           */
/* Paramètres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringConcat(char* dest, const char * src)
{
	char *concat;
	int i=0;
	int	j=0;

 		while (src[i])
 		{
 			concat[i] = src[i];
 			i++;
 		}
 		while (dest[j])
 		{
 			concat[i] = dest[j];
 			j++;
 			i++;
 		}

 		dest = concat;
return dest;

}

/***************************************************************************/
/* NOM FONCTION : StringNConcat						   */
/* DESCRIPTION :  Concatene dest+ N caracteres de src		 	   */
/* Retourne :dest (chaine de caractères obtenue par contenation de deux src*/
/* Effets de bords : 			                                   */
/* Paramètres en entree : dest et src (chaines  sources)	           */
/*			  n (nombre de caracteres a copier)		   */
/* Paramètres en sortie : dest (chaine destination)     		   */
/***************************************************************************/

char* StringNConcat(char* dest, const char * src, int n)
{
	int i =0;
	int j = 0;
	int l;
	char *concat;
	l = n-StringLenght(src);
	printf("%d\n",StringLenght(src));
	
	if (n > StringLenght(src))
	{
  		while (n > l)
 		{
 			concat[i] = src[i];
 			i++;
 			n--; 
    	}
    	//printf("%d\n",n );
 		if(n > 0)
 		{
 			while (n > 0)
 			{
 				concat[i] = dest[j];
 				n--;
 				i++;
 				j++;	
 			}
 	 	}
 	}

 	else 
 	{
 		for (i = 0; i < n; ++i)
 		{
 			concat[i] = src[i];
 		}
 	}

 	dest[i] = '\0';
 	dest = concat;
 
  return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringCompare					  	   */
/* DESCRIPTION :  Compare deux chaines de caracteres. Retoune 0 si elles   */
/* sont identiques, sinon la premire position de leur difference	   */
/* Retourne :0 si les chaines sont egales 				   */
/* Effets de bords : 			                                   */
/* Paramètres en entree : ch1 et ch2 (chaines  sources)	           	   */
/* Paramètres en sortie :    		   */
/***************************************************************************/

int StringCompare(const char* ch1, const char * ch2)
{
	int i;
	int comp = 1;
	while(ch1[i])
	{
		if (ch1[i] != ch2[i])
			comp ==0;
		else i++;
	}
  
  return comp;
}



