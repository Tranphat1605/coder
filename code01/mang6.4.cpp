#include <stdio.h>
int main () {
	int n;
	scanf ("%d", &n);
	int A[n+2][n+2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = i + j + 2;
            printf("%d ", A[i][j]);
		} 
		printf ("\n");
	}
	return 0;
}
