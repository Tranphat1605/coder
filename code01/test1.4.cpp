#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char c[101];
    int s = 0;

    // �?c c? d�ng bao g?m kho?ng tr?ng
    printf("Nh?p chu?i: ");
    fgets(c, sizeof(c), stdin);

    // Duy?t qua t?ng k� t? trong chu?i
    for (int i = 0; i < strlen(c); i++) {
        if (isspace(c[i])) { // Ki?m tra n?u k� t? l� kho?ng tr?ng
            ++s;
        }
    }

    printf("S? k� t? kho?ng tr?ng: %d\n", s);
    return 0;
}

