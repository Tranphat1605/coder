#include <stdio.h> 

int main () {
	int n;
	int t = 0;
	scanf ("%d", &n) ;
	if (n==0) printf ("1") ;
	else {

	while (n>0){
		t++;
		n /= 10;
	} 
	printf ("%d", t);
} }
