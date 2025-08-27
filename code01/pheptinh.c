#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

long long tinhbieuthuc(char *s) {
    long long kq = 0, count = 0, tichtmp = 1;
    char pheptoan = '+';   
    bool flag = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            count = count * 10 + (s[i] - '0');
        }

        if (!isdigit(s[i]) || s[i + 1] == '\0') {  
            if (pheptoan == '*') {
                tichtmp *= count;
                flag = true;
            } else {
                if (flag) {
                    count = tichtmp * count;
                    tichtmp = 1;
                    flag = false;
                }
                if (pheptoan == '+') {
                    kq += count;
                } else if (pheptoan == '-') {
                    kq -= count;
                }
            }

            pheptoan = s[i];
            count = 0;
        }
    }
    return kq;
}

int main() {
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = '\0';  
    printf("%lld\n", tinhbieuthuc(s));
    return 0;
}
