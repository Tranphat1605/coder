#include <stdio.h>
int chan(int A[], int n) {
    int t = 0;
    for (int i = 0; i < n ; i++) {
        if (A[i]%2==0) t+= 1;
    }
    return t;
}
int main () {
    int n, A[10000],t;
    scanf ("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf ("%d", &A[i]);
    }
    t = chan(A, n);
    printf ("%d", t);
    return 0;
}
