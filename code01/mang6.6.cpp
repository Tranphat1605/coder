#include <stdio.h> 
int main () {
	long long n, m;
	scanf ("%lld %lld", &n, &m);
	long long A[n][m];
	long long s[m];
	for (int i = 0; i < m; i++ ){
		s[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf ("%lld", &A[i][j]);
			s[j] += A[i][j];
		}	
	}
	for (int i = 0; i < m; i++) {
		printf ("%lld\n", s[i]);
	}
	return 0;
}
