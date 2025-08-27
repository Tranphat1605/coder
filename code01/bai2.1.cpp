#include <stdio.h>
int main (){
	long long dt;
	scanf ("%lld", &dt); 
	int m[10];
	int i=0;
	while (dt>0) {
		m[i]=dt%10;dt /=10; i++; 
	} 
	for (int j=i-1; j>=0; j--) {
		printf ("%d ", m[j] ) ;
	} 
	return 0 ; 
} 

