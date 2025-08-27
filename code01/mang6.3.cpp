#include <stdio.h> 

int main () {
	int n; 
	scanf ("%d", &n);
	int A[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			if (A[i][j]%2==0) {
				s+=A[i][j];
			}
		}
		printf ("%d\n", s);
	}
	return 0;
}
