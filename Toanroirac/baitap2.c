#include <stdio.h> 

int n,k,a[100];
int b[100];

void tryy(int i) {
	if (i == k) {
		int j;
		for (j = 0; j < k; j++) {
			printf ("%d", a[j]);
		}
		printf ("\n");
		return;
	}
	int j;
	for (j = 1; j <= n; j++) {
		if (!b[j]) {
			a[i] = j;
			b[j] = 1;
			tryy(i+1);
			b[j] = 0;
		}
	}
}

int main() {
	printf ("Nhap n va k: ");
	scanf ("%d %d", &n, &k) ;
	tryy(0) ;
	return 0;
}