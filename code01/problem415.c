#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char so[1000000];
char s[1000000];
long long sum(const char *s) {
    long long res = 0;
    while (*s) {
        res *= 10;
        res += *s - '0';
        s++;
    }
    return res;
}

int main() {
    
    fgets(s, sizeof(s), stdin);  
    char *token = strtok(s, " ");
    
    long long tong = 0;

    while (token != NULL) {
        int d = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (isdigit(token[i])) {
                so[d++] = token[i];
            }
        }
        so[d] = '\0'; 

        if (d != 0) {
            tong += sum(so);
        }

        token = strtok(NULL, " ");
    }

    printf("%lld\n", tong);
    return 0;
}