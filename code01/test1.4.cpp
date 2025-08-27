#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c[101];
    int s = 0;

    // Ð?c c? dòng bao g?m kho?ng tr?ng
    printf("Nh?p chu?i: ");
    fgets(c, sizeof(c), stdin);

    // Duy?t qua t?ng ký t? trong chu?i
    for (int i = 0; i < strlen(c); i++) {
        if (isspace(c[i])) { // Ki?m tra n?u ký t? là kho?ng tr?ng
            ++s;
        }
    }

    printf("S? ký t? kho?ng tr?ng: %d\n", s);
    return 0;
}

