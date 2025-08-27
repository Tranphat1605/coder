#include <stdio.h>
int main () {
	int m,n;
	int s= 0;
	scanf ("%d %d", &m, &n);
	int A[m][n];
	for (int i = 0; i < m; i++) {
		for ( int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j] );
			if (A[i][j]%3==0) {
				s++;
			}
		}
	}
	printf ("%d", s);
	return 0;
}
