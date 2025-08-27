#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10000

void CompessString(char *s) {
    int n = strlen(s);
    int i = 0;
    int count = 1;
    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            printf("%d%c", count, s[i - 1]);
            count = 1;
        }   
    }
    printf("%d%c", count, s[i - 1]);
}

void deComprssString(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        int count = 0;
        while (isdigit(s[i])) {
            count = count * 10 + s[i] - '0';
            i++;
        }
        if (s[i] != '\0' && isalpha(s[i])) {
            for (int j = 0; j < count; j++) {
                printf("%c", s[i]);
            }
            i++;
        }
    }
}

int main () {
    char s1[MAX];
    char s2[MAX];
    scanf("%s", s1);
    scanf("%s", s2);
    CompessString(s1);
    printf("\n");
    deComprssString(s2);
    return 0;
}