/**************************************************************************/
/* NOM  : TP3.C                 */
/* DESCRIPTION : Test d'un carre magique          */
/* AUTEUR :  MONGA LANDRY                 */
/* DATE DE LA DERNIERE MODIFICATION :                       */
/* VERSION :                                          */
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXELT 20
typedef int TABLE[MAXELT];
 

//Prototypes
void saisircarre(TABLE *, int);
void affichercarre(TABLE *, int*);
int suml (TABLE *, int*);
int sumc (TABLE *, int*);
int sumdiagleft(TABLE *, int* );
int sumdiagright(TABLE *, int *);
int dimensioncarre(TABLE[], int *);

int main(int argc, char *argv[])
{

TABLE Tableau[MAXELT];
int pasmagique;
int *dimension = NULL;
int a;
dimension = &a;

dimensioncarre(Tableau, dimension);
affichercarre(Tableau,dimension);


//Calcul de la somme des lignes
  int sum1 = suml(Tableau, dimension);  //L'aglite sert a avoir la valeur retournée par la fonction dans une variable

//Calcul de la somme des diagonales 
  int sum2 = sumc(Tableau, dimension); 
  
// Calcul de la somme des diagonales
  int sum3 = sumdiagleft(Tableau, dimension);
  printf("La somme de la diagonales gauche vaut %d \n", sum3);
  int sum4 = sumdiagright(Tableau, dimension);
  printf("La somme de la diagonales droite vaut %d \n", sum4);

// On verifie si le carre est magique
pasmagique =0 ;

// On teste que toutes les lignes, colonnes et diagonales sont egales

  if ( sum1 != sum2 || sum3 != sum4 || sum1 != sum3) //Conditions pour lesquels le carre n'est pas magique
  {
     pasmagique= 1;
  }

affichercarre(Tableau,dimension);

if (pasmagique == 0) //Si le le test precedent est faux
    printf(" \nLe carre est magique !!!");
else 
      printf(" \nLe carre n'est pas magique !!!");

}


/*************************************************************************/
/* NOM FONCTION : saisircarre              */
/* DESCRIPTION : permet la saisie du carre          */
/* Retourne : void                             */
/* Effets de bords :                                       */
/* Paramètres en entree :n (taille effective du carre)                   */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
void saisircarre(TABLE T[], int n)
{
  int i,j;

  for(i=0;i <= n;i++) //On ecrit lignes par lignes
  {
    for(j=0;j <= n;j++) 
    {
      scanf("%d",&T[i][j]);
    }
  }   
}

/*************************************************************************/
/* NOM FONCTION : affichercarre              */
/* DESCRIPTION : permet l'affichage d'un carre magique           */
/* Retourne : void                            */
/* Effets de bords :                                       */
/* Paramètres en entree :*n (taille effective du carre)                   */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
void affichercarre(TABLE T[], int *n)
{
  int i,j;

  for(i=0;i< *n;i++) 
  {
    for(j=0;j< *n; j++)
    {
      printf("%d ",T[i][j]);
    } 
    printf("\n");
  }
}


/*************************************************************************/
/* NOM FONCTION : suml                     */
/* DESCRIPTION : calcul la somme d'une ligne   */
/* Retourne :  void                          */
/* Effets de bords : la somme de la derniere ligne           */
/* Paramètres en entree :*n (taille effective/dimension du carre)        */
/*       l (ligne ou colonne a prendre en compte)        */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
int suml (TABLE T[], int *n)
{
  int s=0,i=0,j,d=0;

    while (i < (*n)) //Tant que on est pas a la derniere ligne
    {
      for (j=0; j < (*n) ; j++) {
        s = s+T[i][j]; //On fait la somme de chaques lignes
        d = s;
      }
      printf("La somme de la ligne %d vaut %d\n", i+1, s);
      i++;
      s=0;
    }

  return d;
}
/*************************************************************************/
/* NOM FONCTION : sumc                      */
/* DESCRIPTION : calcul la somme d'une colonne    */
/* Retourne :  void                          */
/* Effets de bords : la somme de la derniere colonne         */
/* Paramètres en entree :*n (taille effective/dimension du carre)        */
/*       l (ligne ou colonne a prendre en compte)        */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
int sumc (TABLE T[], int *n)
{
  int s=0,i,j=0, d=0;

    while (j < (*n)) //Tant qu'on est pas a la derniere colonne 
    {
      for (i=0; i < (*n); i++)
      {
        s = s+ T[i][j]; //On fait la somme de chaque valeur de la colonne
        d = s;
      }
       printf("La somme de la colonne %d vaut %d\n", j+1, s);
       d = d+s;
      j++;
      s =0;
    }
    
  return d;
}

/*************************************************************************/
/* NOM FONCTION : sumdiagleft              */
/* DESCRIPTION : calcul de la diagonale venant de gauche          */
/* Retourne :  la somme des valeurs de la diagonale                          */
/* Effets de bords :                                       */
/* Paramètres en entree :n (taille effective du carre)                   */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
int sumdiagleft(TABLE T[], int *n)
{
  int s=0; // somme
  int i;

  for (i=0; i< *n ; i++)
   s=s+T[i][i];

  return s;
}

/*************************************************************************/
/* NOM FONCTION : sumdiagright              */
/* DESCRIPTION : calcul de la diagonale venant de droite          */
/* Retourne :  la somme des valeurs de la diagonale           */
/* Effets de bords :                                       */
/* Paramètres en entree :n (taille effective du carre)                   */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
int sumdiagright(TABLE T[], int *n)
{
  int s=0; // somme
  int i;

  for (i=0; i< *n ; i++)
    s=s+T[(*n)-1-i][i];

  return s;
}

/*************************************************************************/
/* NOM FONCTION : dimensioncarre              */
/* DESCRIPTION : Saisie de la dimension du tableau et saisie du tableau */
/* Retourne :                              */
/* Effets de bords :                                       */
/* Paramètres en entree :*dimension (taille effective du carre)                   */
/* Paramètres en sortie : T (carre magique)            */
/*************************************************************************/
int dimensioncarre(TABLE T[], int *dimension)
{
  int n;
  int dim = 1, i, j;

  printf("Veuillez saisir la dimension de votre carre magique : ");
  scanf("%d", dimension);
  while (*dimension % 2 == 0) {
    dim = 0;
    printf ("Valeurs paires non valables veuillez saisir une autre valeur :  ");
    scanf("%d", dimension); }
  
  if (dim = 1)
  {
    printf("Saisie du tableau : \n");
    for(i=0;i < *dimension ;i++) {              //On ecrit lignes par lignes
      for(j=0;j < *dimension ;j++) {
        scanf("%d", &T[i][j]);
      } 
      printf("\n");
    }
  }

 return *dimension;   
}
