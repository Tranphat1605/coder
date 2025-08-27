#include <stdio.h>
int main () {
	int n; 
	scanf ("%d", &n);
	int A[n][n] ;
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			scanf ("%d", &A[i][j]);
			if (i == j) {
				s+= A[i][j];
			}
		}
	}
	printf ("%d",s );
	return 0;   
}
