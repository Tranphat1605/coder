#include <stdio.h>
#include <math.h> 

int cmp (const void *a, const void*b) {
	return *(int*)a - *(int*)b;
}

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main () { 
	int n, i, j, a, b;
	scanf ("%d", &n);
	int A[n], B[n];
	for (i = 0; i < n; i++){
		scanf ("%d", &A[i]);
	}
	for (i = 0; i < n; i++) {
		B[i] = A[i];
	}
	qsort (A, n, sizeof(int), cmp);
	a = A[0];
	b = B[n-1];
	for (i = 0; i < n; i++) {
		if (B[i]==a) {
			for (j = 0; j < n; j++) {
				if (B[j]==b) {
					swap(&B[i], &B[j]);
				}
			}
		}
	}
	for (i = 0; i < n;  i++) {
		printf ("%d", B[i]);
	}
	return 0;
}
