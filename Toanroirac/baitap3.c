#include <stdio.h>

int n, k, a[100];

void tryy(int i, int start) {
    if (i == k) {
        for (int j = 0; j < k; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
        return;
    }

    for (int j = start; j <= n; j++) {
        a[i] = j;
        tryy(i + 1, j + 1);
    }
}

int main() {
    printf("Nhap n va k: ");
    scanf("%d %d", &n, &k);
    
    tryy(0, 1);
    return 0;
}
