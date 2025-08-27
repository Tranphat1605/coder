#include <stdio.h>

int count = 0; 

void tryy(int index, int k, int n, int s) {
    if (index == k) { 
        if (s == n) { 
            count++;
        }
        return;
    }


    for (int value = 0; value <= n - s; value++) {
        tryy(index + 1, k, n, s + value);
    }
}

int main() {
    int k, n;
    printf("Nhap so nghiem x: ");
    scanf("%d", &k);
    printf("Nhap tong: ");
    scanf("%d", &n);

    if (k <= 0 || n < 0) {
        printf("Khong hop le");
        return 1;
    }

    tryy(0, k, n, 0);

    printf("So nghiem la: %d\n", count);
    return 0;
}
