#include <chaines.h>
#include <TP4-MONGA.c>



char *lire (char * ch){
	int i;
	fflush(stdin);
	gets(ch);
	unsigned int taille = StringLenght(ch);
	for (i = 0; i < taille; ++i)
	{
		if(ch[i] == ' ') {
			switch(i) {
				case 0:
					for (i = 0; i < taille-1; ++i)
					{
						ch[i] = ch[i+1];
					}
					ch[taille-1] = '';
				break;
				case taille-1 :
					ch[taille-1] = '';
				break;
				default :
					while(ch[i+1] == ' ') {
						for (i = 0; i < taille-1; ++i)
						{
							ch[i] = ch[i+1];
						}
						ch[taille-1] = '';
					}
				break;
			}
		}
	}
}


int strpos(char * m, char *ch){

}


char * strmin(char * ch){

}

