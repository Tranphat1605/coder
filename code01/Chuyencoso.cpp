#include <stdio.h>

int main () {
	unsigned int A[1000], c, n;
	int z = 0;
	scanf("%d", &n);
	if (n == 0) {
		printf ("0");
	}
	else {
		while (n>0) {
			c = n % 2;
			A[z] = c;  
			z++;
			n = n/2;
		}
		for (int i = z - 1; i >= 0; i--){
			printf ("%d", A[i]); 
		}
	}
	return 0;
} 
