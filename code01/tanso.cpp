#include <stdio.h> 
int main () {
	int n; 
	scanf ("%d", &n);
	int A[n];
	int dem[1001] = {0}; 
	for (int i = 0; i < n; i++) {
		scanf ("%d", &A[i]);
		dem[A[i]]++;
	}
	int tanso = 0;
	for (int i = 0; i < 1001; i++) {
		if (dem[i] > tanso) {
			tanso = dem[i];
		}
	}
	printf ("%d", tanso);
	return 0;
}
