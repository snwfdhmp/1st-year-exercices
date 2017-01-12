#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char result[80000], input[8000];
	unsigned int i, j, k = 0;

	printf("Entrez une chaine : ");
	scanf("%s", input);

	for (i = 0; i < strlen(input); i+=j)
	{
		for(j = 0; input[i+j] == input[i]; ++j);
			result[2*k+1] = input[i];
			result[2*k] = j + '0';
			k++;
	}

	printf("%s", result);
	return 0;
}