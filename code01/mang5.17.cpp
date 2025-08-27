#include <stdio.h> 
#include <math.h>


int main () {
	int n; 
	int maxvl =-1000;
	scanf ("%d", &n);
	int A[n];
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		if (A[i] > maxvl) {
			maxvl = A[i];
		} 
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += (maxvl - A[i]);
	}
	printf ("%d", s);
	return 0;
}
