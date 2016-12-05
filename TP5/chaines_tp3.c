#include <stdio.h>
#include "chaines_tp3.h"

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
	for (i = 0; i<StringLength(src); ++i)
		dest[i]=src[i];
 
  	return dest;
}

/***************************************************************************/
/* NOM FONCTION : StringLength					   */
/* DESCRIPTION : calcule la longueur de la chaine passee en parametres     */
/* Retourne : int (valeur de la longueur)				   */
/* Effets de bords : 			                                   */
/* Paramètres en entree :ch1 (const TCHAINE)                                 */
/* Paramètres en sortie :      			                           */
/***************************************************************************/

int StringLength(const char *ch)
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
	l = n-StringLength(src);
	printf("%d\n",StringLength(src));
	
	if (n > StringLength(src))
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
			comp=0;
		else i++;
	}
  
  return comp;
}

