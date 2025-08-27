#include <stdio.h>

void out(int s[], int n) {
    for (int i = 1; i <= n; i++) {  
        printf("%d ", s[i]);
    }
    printf("\n");
}

void tryy(int i, int s[], int n, int b[]) {
    for (int j = 1; j <= n; j++) {
        if (b[j] == 1) {
            s[i] = j;
            b[j] = 0;
            if (i == n) { 
                out(s, n);
            } else {
                tryy(i + 1, s, n, b);
            }
            b[j] = 1;  
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int s[n + 1], b[n + 1];  

    for (int i = 1; i <= n; i++) {
        b[i] = 1;
    }

    tryy(1, s, n, b);  

    return 0;
}
