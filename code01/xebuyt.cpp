#include <stdio.h> 
#include <math.h> 

int main () {
	 int n; 
	 scanf ("%d", &n);
	 int A[2*n];
	 int s[n];
	 for (int i = 0; i < 2*n; i++) {
	 	scanf ("%d", &A[i]);
	 }
	 for (int i = 0; i < 2*n; i+=2) {
	 	for (int j = 0; j < n; j++) {
	 		s[j] = -(A[i]) + (A[i+i]);
		 }
	 }
	 int min = -100000;
	 for (int i = 0; i < n; i++) {
	 	if (s[i] >= min) {
	 		min = s[i];
		 }
	 }
	 printf ("%d", min);
	 return 0;
}
