#include <stdio.h> 
#include <math.h>
int ucln (int a, int b){
	int r; 
	if (a == 0 ||b == 0) {
		return a + b;
	}
	while ( b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
} 

void nhap(int n, int A[]){
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
	}
}

void xuat(int n, int A[]) {
	for (int i = 0; i < n; i++){
		printf ("%d", A[i]);
	}
}

int shh(int n) {
	int s = 1;
	for (int i = 2; i <= n/2; i++) {
		if (n%i==0) s+=i;
	}
	if (s == n) {
		return 1;
	} else {
		return 0;
	}
	
}

int main () {
	int n;
	scanf ("%d", &n);
	int A[n];
	nhap(n, A);
	for (int i = 0; i < n; i++){
		if (shh(A[i])==1) {
			printf ("%d ", A[i]);
		}
	}
	return 0;
}
