5
#include <stdio.h>

int main () {
	int n;
	int s = 0; 
	int smax = 0;
	scanf ("%d", &n);
	int A[2*n];
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &A[2*i], &A[2*i+1]);
	}
	for (int i = 0; i < n; i++) {
		s -= A[2*i];
		s += A[2*i+1];
		if (s>smax) {
			smax = s;
		}
	}
	printf ("%d", smax);
	return 0;
}
