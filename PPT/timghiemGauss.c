#include <stdio.h>
#include <math.h>


#define MAX 100
#define ESL 0.001

void dkht(float a[MAX][MAX], int n) {
    float x[max];
    int i;
    for (i = 0; i <= n; i ++) {
         
    }
}
void nhap(float a[MAX][MAX], int *n) {

    printf("Nhap so an n: ");
    scanf("%d", n);

    printf("Nhap ma tran he so (bao gom ca he so tu do):\n");
    for (int i = 0; i < *n; i++)
        for (int j = 0; j <= *n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
}

void doiHang(float a[MAX][MAX], int n) {
    if (a[0][0] == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i][0] != 0) {
                for (int j = 0; j <= n; j++) {
                    float temp = a[0][j];
                    a[0][j] = a[i][j];
                    a[i][j] = temp;
                }
                break;
            }
        }
    }
}

void nhapNghiem(float x[MAX], int n) {
    printf("Nhap gia tri ban dau cho x[i]:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }
}

void xuatNghiem(float x[MAX], int n) {
    for (int i = 0; i < n; i++)
        printf("%.3f      ", x[i]);
    printf("\n");
}

void gaussSeidel(float a[MAX][MAX], float x[MAX], int n) {
    float y[MAX], s;
    int i, j, t;

    do {
        t = 0;
        for (i = 0; i < n; i++) {
            s = 0;
            for (j = 0; j < n; j++)
                if (j != i)
                    s += a[i][j] * x[j];
            y[i] = (a[i][n] - s) / a[i][i];
            if (fabs(y[i] - x[i]) >= ESL)
                t = 1;
        }
        for (i = 0; i < n; i++)
            x[i] = y[i];
        xuatNghiem(x, n);
    } while (t == 1);
}

int main() {
    int n;
    float a[MAX][MAX], x[MAX];

    nhap(a, &n);
    doiHang(a, n);
    nhapNghiem(x, n);
    printf("Nghiem la:\n");
    printf("x1         x2          x3\n");
    gaussSeidel(a, x, n);
    return 0;
}