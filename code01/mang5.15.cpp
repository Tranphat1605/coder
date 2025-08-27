#include <stdio.h> 
#include <math.h> 

int main () {
	int n, k;
	scanf ("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	scanf ("%d", &k);
	for (int i = 0; i < n; i++){
		if (A[i] == k) {
			printf ("%d", i+1);
		}
	}
	return 0;
}
