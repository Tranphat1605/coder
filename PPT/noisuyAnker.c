#include <stdio.h>

int main() {
    int n;
    float x[100], y[100], c;
    float w = 1.0, s = 0.0;

    printf("Nhap so diem n: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        printf("Nhap x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("Nhap y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    printf("Nhap diem c: ");
    scanf("%f", &c);

    for (int i = 0; i <= n; i++) {
        w = w*(c - x[i]);
        float d = c - x[i];

        for (int j = 0; j <= n; j++) {
            if (j != i) {
                d = d*(x[i] - x[j]);
            }
        }

        s = s + y[i] / d;
    }

    float result = w*s;
    printf ("Gia tri w la: %.4f\n", w);
    printf("Gia tri noi suy tai c = %.4f la: %.4f\n", c, result);

    return 0;
}

