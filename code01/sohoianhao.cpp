#include <stdio.h>

int shh(int n){
	int s = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n%i==0) {
			s+=i;
		} 
	}
	if (s==n) {
		return n;
	}
	else {
		return 0;
	}
}

int main () {
	int n;
	scanf ("%d", &n);
	int A[n];
	int m = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		if (!shh(A[i])){
			A[m] = A[i];
			m++;
		}
	}
	for (int i = 0; i < m; i++ ){
		printf ("%d ", A[i]);
	}
	return 0;
}
