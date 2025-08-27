#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main () {
	int n, i;
	int s = 0;
	scanf ("%d", &n);
	int A[n];
	for (i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	qsort (A, n, sizeof(int), cmp);
	for (i = 0; i < n-1; i++){
		s+=A[i];
	}
	int t = s + 2*A[n-1];
	printf ("%d", t);
	return 0;
}
