#include <stdio.h>

int n, stop;

void Ktao(int a[], int k) {
    for (int i = 1; i <= k; i++) a[i] = i;
}

void xuat(int a[], int k) {
    printf("{ ");
    for (int i = 1; i <= k; i++) printf("%d ", a[i]);
    printf("}\n");
}

int check(int a[], int k) {
    for (int i = k; i >= 1; i--)
        if (a[i] != n - k + i) return 0;
    return 1;
}

void sinhtohop(int a[], int k) {
    int i = k;
    while (i > 0 && a[i] == n - k + i) i--;
    if (i > 0) {
        a[i]++;
        for (int j = i + 1; j <= k; j++) a[j] = a[i] + j - i;
    }
}

void sinhcon(int a[], int k) {
    if (k == 0) {
        printf("\n{ }\n");
        return;
    }
    Ktao(a, k);
    xuat(a, k);
    stop = check(a, k);
    while (stop == 0) {
        sinhtohop(a, k);
        xuat(a, k);
        stop = check(a, k);
    }
}

int main() {
    printf("Nhap so n: ");
    scanf("%d", &n);

    int a[n];
    printf("Cac tap con la: ", n);

    for (int k = 0; k <= n; k++) {
        sinhcon(a, k);
    }

    return 0;
}
