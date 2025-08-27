#include <stdio.h> 

int n, a[100], ok;

void ktao() {
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sinhth() {
	int i = n - 1;
	while (i >= 1 && a[i] > a[i+1]) {
		i--;
	}
	if ( i == 0) {
		ok = 0;
	}
	else {
		int j = n;
		while (a[i] > a[j]) { 
		j--;
		}
		swap(&a[i],&a[j]);
		int l = i+1, r = n;
		while (l<n) {
			swap(&a[l],&a[r]);
			r--;
			l++;
		}
	}
}

int main () {
	scanf ("%d", &n);
	ktao();
	ok = 1;
	while(ok){ 
		for (int i = 1; i <= n; i++) {
			printf ("%d", a[i]);
		}
		printf ("\n");
		sinhth();
	}
	return 0; 
}