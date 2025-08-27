#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

void sangnt(int l, int r) {
    int A[r - l + 1];
    for (int i = 0; i < r - l + 1; i++) {
        A[i] = 1;
    }

    for (int i = 2; i <= sqrt(r); i++) {
        for (int j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i) {
            A[j - l] = 0;
        }
    }
    for (int i = max(l, 2); i <= r; i++) {
        if (A[i - l]) {
        	printf("%d ",i ); 
        }
    }

}

int main() {
    int r, l;
    scanf("%d %d", &l, &r);
    sangnt(l, r);

    return 0;
}
