#include <stdio.h>
 
int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int A[n][m];
    int q = m*n;
    int c1 = 0, c2 = m - 1, h1 = 0, h2 = n - 1;
 
    while (c1 <= c2 && h1 <= h2) {
        for (i = c1; i <= c2; i++) {
            A[h1][i] = q;
            q--;
        }
 
        for (i = h1 + 1; i <= h2; i++) {
            A[i][c2] = q;
            q--;
        }
 
        if (h1 < h2 && c1 < c2) {
            for (i = c2 - 1; i >= c1; i--) {
                A[h2][i] = q;
                q--;
            }
 
            for (i = h2 - 1; i > h1; i--) {
                A[i][c1] = q;
                q--;
            }
        }
 
        c1++;
        c2--;
        h1++;
        h2--;
    }
 
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}

