#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int n = strlen(haystack);
    int m = strlen(needle);
    if (m == 0) {
        return 0;
    }
   
    for (int i = 0; i <= n-m; i++) {
        int j = 0;
        while (j < m && haystack[i+j] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main () {
    char s1[8] = "aabcddef";
    char s2[8] = "mkj";
    printf("%d", strStr(s1, s2));
    return 0;
}