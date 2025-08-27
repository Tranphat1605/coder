#include <stdio.h>

int main() {
    long long a, b, r;
    scanf("%lld %lld", &a, &b);
    
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    
    printf("%lld", a);
    
    return 0;
}
