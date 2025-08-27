#include <stdio.h> 
int main () {
	int n;
	scanf ("%d", &n);
	long long  s = 0;
	for (int i = 0; i<=n; i++) {
		if (i%2!=0) s+=i;
	}
	printf ("%lld", s);
	return 0;
}
