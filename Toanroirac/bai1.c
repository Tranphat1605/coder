#include <stdio.h>

void init(int b[], int n);
void out(int b[], int n);
int isLast(int b[], int n);
void gen(int b[], int n);
void method(int b[], int n);

int main() {
    int n;
    printf("Nhap so N: ");
    scanf("%d", &n);
    printf("Day nhi phan la:\n");
    int b[n + 1];
    method(b, n);
    return 0;
}

void init(int b[], int n) {
    for (int i = 1; i <= n; i++) {
        b[i] = 0;
    }
}

void out(int b[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", b[i]);
    }
    printf("\n");
}

int isLast(int b[], int n) {
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) return 0;
    }
    return 1;
}

void gen(int b[], int n) {
    int i = n;
    while (b[i] == 1) {
        b[i--] = 0;
    }
    b[i] = 1;
}

void method(int b[], int n) {
    init(b, n);
    out(b, n);
    while (!isLast(b, n)) {
        gen(b, n);
        out(b, n);
    }
}
