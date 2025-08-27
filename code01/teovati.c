#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main () {
	int n, i;
	scanf ("%d", &n);
	int A[n];
	for (i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	qsort (A, n, sizeof(int), cmp);
	if (n%2==0) {
		printf ("%d", A[n/2-1]);
	} else {
		printf ("%d", A[n/2]);
	}
	return 0;
}
