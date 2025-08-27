#include <stdio.h>
#include <math.h>
float tinh(int x, int n) {
	float s = 1;
	for (int i = 1; i<=n; i++ ){
		s += pow(x,i)/i;
	}
	return s;
}
int main () {
	int x,n;
	scanf ("%d %d", &x, &n);
	float s  = tinh(x, n);
	printf ("%f", s);
	return 0;
}
