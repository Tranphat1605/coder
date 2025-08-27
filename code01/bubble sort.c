#include <stdio.h>
int main () {
	int n;
	scanf("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++){
			if (A[i] > A[j]) {
			tam = A[i];
			A[i] = A[j];
			A[j] = tam;
			}
		}
	}
	for (int i = 0; i < n; i++){
		printf ("%d", A[i]);
	}
	return 0;
	
}
