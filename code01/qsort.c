#include <Stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}
int main () {
	int n, i ;
	scanf ("%d", &n);
	int A[n];
	for ( i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	qsort (A, n, sizeof(int) , cmp);
	for (i = 0; i < n ; i++) {
		printf ("%d ", A[i]);
	}
	return 0;
}
