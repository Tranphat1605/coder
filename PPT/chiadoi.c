#include <stdio.h>
#include <math.h>

#define esilon 0.0001  

double m[100];  
int n;  

double tinhdathuc(double x) {
    double p = m[0];
    for (int i = 1; i <= n; i++) {
        p = p * x + m[i];
    }
    return p;
}

double tinh2(double x) {
    return exp(x) + x - 2;  
}

void chiadoi(double (*f)(double), double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Khong hop le:\n");
        return;
    }

    double c;
    while (fabs(a - b) > esilon) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0) {
            break;
        } else if (f(c) > 0) {
            b = c;
        } else {
            a = c;
        }
    }
    printf("Nghiem gan dung la: %f\n", c);
}

int main() {
    double a, b;
    int chon;
    double (*f)(double);  

    do {
        printf("1. Ham tinh da thuc\n");
        printf("2. Ham tinh e^x + x - 2\n");
        printf("0. Thoat.\n");
        printf("Nhap lua chon.\n");
        scanf("%d", &chon);

        switch (chon) {
            case 0:
                printf("Thoat.");
                return 0;

            case 1:
                printf("Nhap bac da thuc: ");
                scanf("%d", &n);

                printf("Nhap he so\n");
                for (int i = 0; i <= n; i++) {
                    printf("He so bac %d: ", i);
                    scanf("%lf", &m[i]);
                }

                f = tinhdathuc;  
                break;

            case 2:
                f = tinh2;
                break;

            default:
                printf("Khong hop le. Chon lai!\n");
                continue;
        }

        do {
            printf("Nhap khoan a, b: ");
            scanf("%lf %lf", &a, &b);
            if (f(a) * f(b) >= 0) {
                printf("khoan khong hop le. Nhap lai:\n");
            }
        } while (f(a) * f(b) >= 0);

        chiadoi(f, a, b);
    } while (1);

    return 0;
}
