#include <stdio.h>
#include <math.h> 
int main () {
	int n; 
	scanf ("%d", &n );
	int A[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &A[i]);
	}
	if (A[0]%2==0 && A[1]%2==0) {
		for (int i = 0; i < n; i++) {
			if (A[i]%2==1) {
				printf ("%d", A[i]);
				break;
			}
		}
	} else {
		for (int i =0; i < n; i++) {
			if (A[i]%2==0) {
				printf ("%d", A[i]);
				break;
			}
		}
	}
	return 0;
}
