#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
int ucln(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

double sum(int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        s += 1.0 / (2.0 * i + 1);
    }
    return s;
}

void tachmang(char s[]) {
    for (int i = 0; i < strlen(s); i++) {
        printf("%c ", s[i]);
    }
    printf("\n");
}

void hinhchunhat(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("a ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int chon;
    do {
        printf("0. Thoat\n");
        printf("1. Tim UCLN\n");
        printf("2. Tinh tong\n");
        printf("3. Xuat mang\n");
        printf("4. In hinh chu nhat\n");
        printf("Chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            case 1: {
                int a, b;
                printf("Nhap a, b: ");
                scanf("%d%d", &a, &b);
                printf("UCLN=%d\n", ucln(a, b));
                break;
            }
            case 2: {
                int n;
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("Tong=%f\n", sum(n));
                break;
            }
            case 3: {
                char s[100];
                printf("Nhap chuoi: ");
                getchar(); 
                scanf("%[^\n]", s);
                tachmang(s);
                break;
            }
            case 4: {
                int n, m;
                printf("Nhap n, m: ");
                scanf("%d%d", &n, &m);
                hinhchunhat(n, m);
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
                Sleep(2000);
                break;
            }
        }
    
    } while (chon != 0);
    return 0;
}