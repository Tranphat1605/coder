#include <stdio.h> 
int main () {
	int n ,m;
	scanf ("%d %d", &m, &n); 
	int A[m][n];
	int s[m];
	for (int i = 0; i < m; i++) {
		s[i] =0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j]);
			s[i]+=A[i][j];
		}
	}
	int max = s[0];
	for (int i = 0; i < m; i++){
		if (s[i] > max) {
			max = s[i];
		}
	}
	printf ("%d", max);
	return 0;
}
