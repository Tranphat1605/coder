#include <stdio.h> 

int c(int n, int k) {
	if ( n == k || k == 1) {
		return 1;
	} 
	else {
		return c(n-1,k-1) + c(n-1, k);
	}
}
int main () {
	int k,n;
	scanf ("%d %d", &k, &n);
	long long s = c(n,k);
	printf ("%lld", s);
	return 0;
}
