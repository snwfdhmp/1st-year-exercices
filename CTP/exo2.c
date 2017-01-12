#include <stdio.h>
#include <math.h>

// vous devez ecrire les sous programmes
//perimetre (case 1)
//valeurMini (case 2)
//NiemevaleurMini (case 3)
//transforme (case 4)

#define TAILLE 10
typedef int T_Carre[TAILLE][TAILLE];

/************************     PERIMETRE     **************************/
/************************ entree 1 : Carre ***************************/
/************************ entree 2 : taille carré  *******************/
/******************* renvoie le perimetre du carre  ******************/
int perimetre(T_Carre monCarre, int taille)
{
	unsigned int i, j;
	int sum = 0;
	for (i = 0; i < taille; ++i)
		if (i==0 || i==taille-1)
			for(j = 0; j < taille; ++j)
				sum += monCarre[i][j];
		else
			sum += (monCarre[i][0]+monCarre[i][taille-1]);
	return sum;
}

/************************   valeurMini   *****************************/
/************************ entree 1 : Carre ***************************/
/************************ entree 2 : taille carré  *******************/
/******************* renvoie la valeur Mini du carre  ****************/


int valeurMini(T_Carre monCarre, int taille) {
	unsigned int i, j;
	int x;

	for (i = 0; i < taille; ++i)
		for (j = 0; j < taille; ++j)
			if(x>monCarre[i][j]) x=monCarre[i][j];

	return x;
}

int NiemevaleurMini(T_Carre monCarre, int taille, int N, int* x, int* y) {
	unsigned int previous = 0, min, i, j, k;
 
    for(k=0; k<N; k++)
    {
        min = monCarre[0][0];
        for(i=0; i<taille; i++)
            for(j=0; j<taille; j++)
                if(min > monCarre[i][j] && monCarre[i][j] > previous)
                {
                    min = monCarre[i][j];
                    *x = i+1;
                    *y = j+1;
                }
        previous = min;
    }
 
    return min;
}

/************************     MENU     *******************************/
/************************ aucune entree  *****************************/
/******************* renvoie le choix de l'utilisateur  **************/
int menu()
{
	int chx;
	printf("\n1 - calculer le perimetre du Carre");
	printf("\n2 - trouver la plus petite valeur du Carre");
	printf("\n3 - trouver la Nieme plus petite valeur du Carre");
	printf("\n4 - calculer le plus GRAND perimetre du Carre ");
	printf("\n0 - QUITTER \n\n");
	scanf("%d",&chx);
	return chx;
}


/************************     AFFICHERCARRE     *******************************/
/************************ entree 1 : le tableau T  (son adresse)  *************/
/************************ entree 2 : la taille reelle du tableau T  ***********/
/*********************** ne renvoie rien , ne modifie rien    *****************/

void afficherCarre(T_Carre T,int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		printf("\n");
		for(j=0;j<t;j++)
			printf("%6d ",T[i][j]);
	}
	printf("\n\n\n");

}

void transforme(T_Carre monCarre, int taille)
{
    unsigned int i, j, x, y;
 
    for(i=1; i<taille-1; i++)
        for(j=1; j<taille-1; j++)
        {
            NiemevaleurMini(monCarre, taille, (i-1)*(taille-2)+j, &x, &y);
            swap(monCarre, i, j, x, y);
        }
}


void swap(T_Carre monCarre, int x1, int y1, int x2, int y2)
{
    int t;
 
    t = monCarre[x1][y1];
    monCarre[x1][y1] = monCarre[x2][y2];
    monCarre[x2][y2] = t;
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////  MAIN /////////////////
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	int choix,PERIMETRE=0,miniValue=0,NiemeMiniValue=0,x=-1,y=-1,N;

    //vous pourrez/devrez tester avec l'un ou l'autre de ces 2 carr�s

	int taille=4;
	T_Carre monCarre={{55,8,11,45}, {3,22,41,52}, {65,83,17,5}, {12,21,23,27}};

    //int taille=5;
    //T_Carre monCarre={{55,8,11,45,17}, {3,22,41,2,64}, {65,83,37,5,1}, {12,21,23,27,99}, {38,85,52,19,7}};

	printf("\n\nCTP 2017 \n\n\n");
	afficherCarre(monCarre,taille);
	do{
		choix= menu();
		switch(choix)
		{
			case 1 :
                PERIMETRE = perimetre(monCarre,taille);
			printf("\n\n ----> le perimetre vaut %d\n\n",PERIMETRE);
			break;
			case 2 :
                miniValue=valeurMini(monCarre,taille);
			printf("\n\n ----> la plus petite valeur vaut %d\n\n",miniValue);
			break;
			case 3 :
                N=2;//on peut changer N : N=3, N=4, etc ...
                NiemeMiniValue=NiemevaleurMini(monCarre,taille,N,&x,&y);
                printf("\n\n ----> la %dieme plus petite valeur vaut %d\n",N,NiemeMiniValue);
                printf("\n\n ----> Cette valeur est en position %d--%d\n\n",x,y);
                break;
                case 4 :
                transforme(monCarre,taille);

                /*
                la fonction transforme doit rechercher les (taille-2)^2 plus
                petites valeurs du Carre et les ranger � l'int�rieur du Carr�
                Ainsi, le p�rim�tre du Carr� sera le p�rim�tre MAXI !

                (taille-2)^2 =4 si taille=4
                (taille-2)^2 =9 si taille=5 , etc ...

                */
                //PERIMETRE= perimetre(monCarre,taille);
                printf("\n\n ----> le plus GRAND perimetre vaut %d\n\n",PERIMETRE);

                break;
                default : break;

            }
        } while(choix!=0);
        printf("\n\n\n");
        return 0;
    }
