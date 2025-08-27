#include <stdio.h>

#define MAX 100

void nhanMaTran(double A[][MAX], double B[][MAX],int n, double C[][MAX]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n;
    double a[MAX][MAX], M[MAX][MAX], M1[MAX][MAX];
    double b[MAX][MAX];

    printf("Nhap cap ma tran n: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua ma tran a[%d][%d]:\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    // Tính 2 ma trận M và M1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != n) {
                if (i == j) {
                    M[i][j] = 1;
                    M1[i][j] = 1;
                } else {
                    M[i][j] = 0;
                    M1[i][j] = 0;
                }
            } else {
                M1[i][j] = a[i-1][j];
                if (j == n) {
                    M[i][j] = 1.0 / a[i-1][n];
                } else {
                    M[i][j] = -a[i-1][j] / a[i-1][n];
                }
            }
        }
    }

    // Gọi hàm nhân 2 lần
    nhanMaTran(a, M, n, b); // B = A * M
    nhanMaTran(M1, b, n, a); // A = M1 * B

    // Xuất kết quả ma trận a

    printf("Ma tran ket qua:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
