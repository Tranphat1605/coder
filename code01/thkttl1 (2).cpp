#include <stdio.h> 
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if ((a + b) <= c || (b + c) <= a || (a + c) <= b) {
        printf("Khong phai hinh tam giac");
    } else {
        if ((a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) && (a == b || b == c || c == a)) {
            printf("Tam giac vuong can");
        }
        if ((a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)) {
            printf("Tam giac vuong");
        }
        if (a == b && b == c) {
            printf("Tam giac deu");
        }
        else if (a == b || b == c || c == a) {
            printf("Tam giac can");
        } 
        if ((a != b && b != c && c != a) && (a * a + b * b != c * c && a * a + c * c != b * b && b * b + c * c != a * a)) {
            printf("Tam giac binh thuong");
        }
    }

    return 0;
}
