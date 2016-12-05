#ifndef chaines_def
#define chaines_def

/*La fonction lire réalise la saisie d'une chaine et 
la formate de maniè̀re à ce qu'elle respecte les spécifications 
imposées au début de cet énoncé.*/
char *lire (char * ch);

/*La fonction strpos retourne la position du mot pointé par m 
dans la chaine pointée par ch sinon -1. */
int strpos(char * m, char *ch);

/*Elle convertit en minuscule les caractères de la chaine pointée 
par ch. Retourne un pointeur sur le début de cette chaine.*/
char * strmin(char * ch);

/*Elle retourne un pointeur sur une chaine contenant le 
premier mot de la chaine pointée par ch.*/
char* premier(char* ch);

/*Elle retourne un pointeur sur une chaine contenant tout sauf
le premier mot de la chaine pointée par ch.*/
char *saufpremier(char * ch);

/*Elle retourne un pointeur sur une nouvelle chaine construite en prenant 
tous les mots de la chaine pointée par ch1, suivis d'un espace et de tous
les mots de la chaine pointée par ch2 dans la limite des 80 caractères.*/
char *phrase (char * ch1, char * ch2) ;

#endif