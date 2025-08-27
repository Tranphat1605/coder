#include <stdio.h> 

int main () {
    int n; 
    int t = 0;
    scanf("%d", &n);
    double A[n+2]; 
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &A[i]);
    }
    A[0] = A[1] + 1;
    A[n+1] = A[n] + 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] < A[i+1] && A[i] < A[i-1]) {
            t++;
        }
    }
    printf("%d", t);
    return 0;
}
#include <stdio.h> 
int main () {
	
}

