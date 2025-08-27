#include <stdio.h> 

int n, a[100], ok;

void ktao(int a[100]) {
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
	}
}

void sinh() {
	int i = n; 
	while (i >= 1 && a[i] == 1) {
		a[i] = 0;
		i--;
	}
	if (i==0) {
		ok = 0;
	} else {
		a[i] = 1;
	}
}

int main () {
	scanf ("%d", &n);
	ok = 1;
	ktao(a);
	while (ok) {
		for (int i = 1; i <= n; i++) {
			printf ("%d", a[i]);
		}
		printf ("\n") ;
		sinh();
	}
	return 0;
}