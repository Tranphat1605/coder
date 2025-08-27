#include <stdio.h>
#include <math.h>

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int sangso(int l, int r){
    int prime[r - l + 1];
    int s = 0;
    
    for (int i = 0; i < r - l + 1; i++) {
        prime[i] = 1;
    }
    
    for (int i = 2; i <= sqrt(r); i++) {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i){
            prime[j - l] = 0;
        }
    }
    
    for (int i = max(l, 2); i <= r; i++){
        if (prime[i - l]){
            s += i;
        }
    }
    
    return s;
}

int main() {
    int l, r, s = 0;
    scanf("%d %d", &l, &r);
    s = sangso(l, r);
    printf("%d", s);
    return 0;
}

