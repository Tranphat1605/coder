#include <stdio.h>

int main () {
	int n;
	scanf ("%d", &n);
	int A[n];
	int s = 0, max = 0;
	for (int i = 0 ; i < n; i++) {
		scanf ("%d", &A[i]);
		if (A[i]>max){
			max = A[i];
		}
		s+=A[i];
	}
	printf ("%d", s+max);
	return 0;
	
}
