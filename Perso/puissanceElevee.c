#include <stdio.h>

// Valeur maximum de long long avec X%10==0 -> 1000000000000000000

int main(int argc, char const *argv[])
{
	unsigned long long x=1LL;
	while(1) {
		x*=10LL;
		printf("%lld\n", x);
	}
	return 0;
}