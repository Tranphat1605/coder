#include <stdio.h>
#include <math.h> 
int main () {
	long long n;
	int a,p;
	p = 1;
	printf ("Nhap so n: ");
	scanf ("%lld", &n);
	if (n%2==0) {
		a = 0;
		for (int i=1; i<=(n/2);i++) {
			a += 2;
			p *= a;
		}
	} else {
		a = 1;
		for (int i=1; i<(n+1)/2; i++) {
			a += 2;
			p *= a;
		}
	} 
	printf ("%lld", p);
	return 0;
}
