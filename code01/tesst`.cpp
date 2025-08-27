#include <stdio.h>
#include <math.h>
int snt(int s){
	if (s<2){
		return 0;
	}
	for (int i = 2; i <= sqrt(s); i++){
		if (s%i==0) {
			return 0;
		}
	}
	return 1;
}
int main () {
	int n;
	int t = 0;
	scanf ("%d", &n);
	int A[n];
	for (int i = 0; i<n; i++) {
		scanf ("%d", &A[i]);
	}
	for (int i = 0; i < n; i++){
		if (snt(A[i])) {
			printf ("%d %d\n", i+1, A[i]);
			t++;
		} 
	} 
	if (t == 0) printf ("KHONG CO SO NGUYEN TO");
	return 0;
} 
