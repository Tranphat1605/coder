#include <stdio.h>
#include <math.h>

float hamfx(float x) {
    return x/(x*x +1);
}

float hinhthang(float a, float b, float n) {
    float h = (b-a)/n;
    float j = (hamfx(a) + hamfx(b)) / 2;
    for (int i = 1; i < n; i++) {
        j += hamfx(a + i*h);
    }
    return h*j;
}

float parabol1(float a, float b, float n) {
    float h = (b-a)/(2*n);
    float j = (hamfx(a) + hamfx(b));
    for (int i = 1; i < 2*n; i++) {
        if (i%2 == 0) {
            j +=4* hamfx(a + i*h);
        } 
        else {
            j +=2* hamfx(a + i*h);
        }
    }
    return h*(j/3);
}

int main () {
    float a, b, n;
    printf("Nhap canh a, b: ");
    scanf ("%f %f", &a, &b);
    printf("Nhap n: ");
    scanf("%f", &n);
    printf("Tich phan phuong phap hinh thang la: %f\n", hinhthang(a, b, n));
    printf("Tich phan phuong phap parabol la: %f", parabol1(a, b, n));
    return 0;
}