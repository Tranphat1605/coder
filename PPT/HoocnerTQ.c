#include <stdio.h>
#include <math.h>

int main() 
{
    int i, j, n;
    float c, a[10];
    
    printf("Nhap gia tri c cho truoc: ");
    scanf("%f", &c);
    printf("Nhap bac gia tri cua da thuc: ");
    scanf("%d", &n);
    printf("Nhap he so: \n");
    
    for (i = 0; i <= n; i++) {
        printf("He so thu %d = ", i + 1);
        scanf("%f", &a[i]);
    }

    for (i = n; i >= 1; i--)
        for (j = 1; j <= i; j++) a[j] = a[j - 1] * c + a[j];

    printf("Cac he so cua p(y + %0.3f) lan luoc la:\n", c);
    for (i = 0; i <= n; i++) {
        printf("He so bac %d = %0.3f\n", n - i, a[i]);
    }

    return 0;
}
