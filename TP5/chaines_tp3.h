#ifndef chaines_tp3_def
#define chaines_tp3_def

char* StringCopy(char* dest, const char* src);
int StringLength(const char *ch);
char* StringNCopy(char *dest, const char* src, int n);
char* StringConcat(char* dest, const char * src);
char* StringNConcat(char* dest, const char * src, int n);
int StringCompare(const char* ch1, const char * ch2);

#endif