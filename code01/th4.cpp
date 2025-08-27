#include <stdio.h> 
int main () {
	int n ,m;
	scanf ("%d %d", &m, &n); 
	int A[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j]==25) {
				printf ("%d %d\n", i, j);
			}
		}
	}
	return 0;
}
