#include <stdio.h>

#define MAX 100
#define max 100
// Hàm nhập dữ liệu
void nhap(float a[MAX][MAX], int *n) {
    printf("Nhap so diem n: ");
    scanf("%d", n);

    printf("Nhap cac gia tri y[i]:\n");
    for (int i = 0; i < *n; i++) {
        printf("y[%d] = ", i);
        scanf("%f", &a[i][0]);
    }
}

// Hàm tính bảng sai phân
void tinhSaiPhan(float a[MAX][MAX], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }
}

// Hàm xuất nửa dưới bảng sai phân
void xuat(float a[MAX][MAX], int n) {
    printf("\nBang sai phan (nua duoi):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%8.2f ", a[i-j][j]);
        }
        printf("\n");
    }
}

void saiphan(int n, float a[max][max], float y[] ) {
	for (int i=0; i<=n; i++) {
		a[i][0] = y[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			a[i][j] = a[i][j-1] - a[i-1][j-1];
		}
	}
	printf("\n Bang sai phan:\n\n");
	for (int i=0; i<=n; i++) {
	 	for (int j=0; j<=i; j++) printf("%10.3f", a[i][j]);
		printf("\n");
	}
}

// Hàm chính
int main() {
    int n;
    float a[MAX][MAX];
    float y[MAX];
    // nhap(a, &n);
    // tinhSaiPhan(a, n);
    // xuat(a, n);
    saiphan(n, a, y);
    return 0;
}

void saiphan(int n, float a[max][max], float y[] ) {
	for (int i=0; i<=n; i++) {
		a[i][0] = y[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			a[i][j] = a[i][j-1] - a[i-1][j-1];
		}
	}
	printf("\n Bang sai phan:\n\n");
	for (int i=0; i<=n; i++) {
	 	for (int j=0; j<=i; j++) printf("%10.3f", a[i][j]);
		printf("\n");
	}
}