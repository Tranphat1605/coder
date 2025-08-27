#include <stdio.h>

unsigned long long c(int n, int k) {
    unsigned long long A[1000][1000];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= k; j++) {
            if (j == 0 || j == i) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            }
        }
    }

    return A[n][k];
}

int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    unsigned long long s = c(n, k);
    printf("%llu\n", s);
    return 0;
}

