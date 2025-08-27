#include <stdio.h> 

#include <math.h> 

int n,r = 0, len = 1; 

long long res[100000]; 

void giaithuakep(int n) 

{ 

    res[0] = 1; 

    for (int i = n; i > 0; i -= 2) 

    { 

        for (int j = 0; j < len; j++) 

        { 

            int tmp = r; 

            r = (res[j] * i + r) / 10; 

            res[j] = (res[j] * i + tmp) % 10; 

        } 

        while (r > 0) 

        { 

            res[len] = r % 10; 

            len++; 

            r = r / 10; 

        } 

    } 

    for (int i = len - 1; i >= 0; i--) 

        printf("%d", res[i]); 

} 

int main() 

{ 

    printf("Nhap n: "); 

    scanf("%d", &n); 

    printf("n!! = "); 

    giaithuakep(n); 

    return 0; 

} 
