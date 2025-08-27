#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
#define EPSILON 1e-6

void doiDong(float a[MAX][MAX], int dong1, int dong2, int cot) {
    for (int j = 1; j <= cot; j++) {
        float temp = a[dong1][j];
        a[dong1][j] = a[dong2][j];
        a[dong2][j] = temp;
    }
}

void damBaoCheoKhac0(float a[MAX][MAX], int n) {
    for (int i = 1; i <= n; i++) {
        if (fabs(a[i][i]) < EPSILON) {
            int timThay = 0;
            for (int k = i + 1; k <= n; k++) {
                if (fabs(a[k][i]) > EPSILON) {
                    doiDong(a, i, k, n + 1);
                    timThay = 1;
                    break;
                }
            }
            if (!timThay) {
                printf("Khong tim duoc dong phu hop de doi cho dong %d\n", i);
                exit(1);
            }
        }
    }
}

void chuanHoaHeSo(float a[MAX][MAX], int n) {
    for (int i = 1; i <= n; i++) {
        float t = a[i][i];
        for (int j = 1; j <= n + 1; j++) {
            a[i][j] /= t;
        }
    }
}

void khoiTaoDu(float a[MAX][MAX], float r[MAX], float x[MAX], int n) {
    for (int i = 1; i <= n; i++) {
        r[i] = a[i][n + 1];
        x[i] = 0;
        for (int j = 1; j <= n; j++) {
            r[i] -= a[i][j] * x[j];
        }
    }
}

void inTrangThai(int buoc, float x[MAX], float r[MAX], int n) {
    printf("  x = [ ");
    for (int i = 1; i <= n; i++) {
        printf("%.6f ", x[i]);
    }
    printf("]\n  r = [ ");
    for (int i = 1; i <= n; i++) {
        printf("%.6f ", r[i]);
    }   
    printf("]\n\n");
}

void giaiHeBangPhuongPhapDu(float a[MAX][MAX], float x[MAX], int n) {
    float r[MAX];
    int tiepTuc = 1, buoc = 0;
    khoiTaoDu(a, r, x, n);
    inTrangThai(buoc, x, r, n);

    while (tiepTuc) {
        float lonNhat = fabs(r[1]);
        int k = 1;
        for (int i = 2; i <= n; i++) {
            if (fabs(r[i]) > lonNhat) {
                lonNhat = fabs(r[i]);
                k = i;
            }
        }
        x[k] += r[k];
        float d = r[k];
        tiepTuc = 0;
        for (int i = 1; i <= n; i++) {
            r[i] -= a[i][k] * d;
            if (fabs(r[i]) >= EPSILON) {
                tiepTuc = 1;
            }
        }
        buoc++;
        inTrangThai(buoc, x, r, n);
    }
}

void inKetQua(float x[MAX], int n) {
    printf("Ket qua cuoi cung:\n");
    for (int i = 1; i <= n; i++) {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
}

void docFile(const char* tenFile, float a[MAX][MAX], int* n) {
    FILE* f = fopen(tenFile, "r");
    if (!f) {
        printf("Khong mo duoc file.\n");
        exit(1);
    }

    fscanf(f, "%d", n);
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= *n + 1; j++) {
            fscanf(f, "%f", &a[i][j]);
        }
    }

    fclose(f);
}

int main() {
    int n;
    float a[MAX][MAX], x[MAX];

    docFile("input.txt", a, &n);
    damBaoCheoKhac0(a, n);
    chuanHoaHeSo(a, n);
    giaiHeBangPhuongPhapDu(a, x, n);
    inKetQua(x, n);

    return 0;
}
