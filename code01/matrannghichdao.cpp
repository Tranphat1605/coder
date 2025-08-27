#include <stdio.h>
#include <stdlib.h>

// Hàm ð? nh?p ma tr?n c?p nxn
void nhapMaTran(float mat[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}

// Hàm ð? xu?t ma tr?n c?p nxn
void xuatMaTran(float mat[][10], int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

// Hàm t?m ð?nh th?c c?a ma tr?n
float det(float mat[][10], int n) {
    float ratio, det = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                ratio = mat[i][j] / mat[j][j];
                for (int k = 0; k < n; k++) {
                    mat[i][k] -= ratio * mat[j][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        det *= mat[i][i];
    }
    return det;
}

// Hàm t?m ma tr?n ngh?ch ð?o
void maTranNghichDao(float mat[][10], float inv[][10], int n) {
    float temp[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = mat[i][j];
            if (i == j)
                inv[i][j] = 1;
            else
                inv[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        float divisor = temp[i][i];
        for (int j = 0; j < n; j++) {
            temp[i][j] /= divisor;
            inv[i][j] /= divisor;
        }
        for (int k = 0; k < n; k++) {
            if (i != k) {
                float factor = temp[k][i];
                for (int j = 0; j < n; j++) {
                    temp[k][j] -= factor * temp[i][j];
                    inv[k][j] -= factor * inv[i][j];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap cap cua ma tran: ");
    scanf("%d", &n);

    float mat[10][10], inv[10][10];
    nhapMaTran(mat, n);
    xuatMaTran(mat, n);

    if (det(mat, n) != 0) {
        maTranNghichDao(mat, inv, n);
        printf("Ma tran nghich dao:\n");
        xuatMaTran(inv, n);
    } else {
        printf("Ma tran khong co nghich dao\n");
    }

    return 0;
}

