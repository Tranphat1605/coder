#include <stdio.h>
int main () {
	int m,n;
	scanf ("%d %d", &m, &n);
	int A[m][n];
	for (int i = 0; i < m; i++) {
		for ( int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j] );
		}
	}
	for (int i = 0; i < m; i++) {
		int max = A[i][0]; 
		for ( int j = 0; j < n; j++) {
			if (A[i][j]>max){
				max = A[i][j];
			}
		}
		printf ("%d \n", max);
	}
	return 0;
}


