#include <stdio.h>
int main () {
    int A[1000],n;
    scanf ("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++){
        scanf ("%d", &A[i]);
    }
    for (int i = 0; i < n; i++){
    	if (i%2==0) s+=A[i];
	}
    printf ("%d", s);
    return 0;
}
