#include <stdio.h>
int main () {
	int n,tam;
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++){
			if (A[j] > A[j+1]) {
			tam = A[j];
			A[j] = A[j+1];
			A[j+1] = tam;
			}
		}
	}
	for (int i = 0; i < n; i++){
		printf ("%d", A[i]);
	}
	return 0;
	
}
