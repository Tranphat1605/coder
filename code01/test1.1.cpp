#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// H�m gi?i m� chu?i m� h�a ASCII
void giaiMa(char* ma_hoa) {
    int n = strlen(ma_hoa);
    char ket_qua[101];
    int index_ket_qua = 0;

    for (int i = 0; i < n;) {
        int ma = 0;

        // X? l� 2 ho?c 3 k� t? d? t?o th�nh m� ASCII h?p l?
        if (i + 1 < n) {
            ma = (ma_hoa[i] - '0') * 10 + (ma_hoa[i + 1] - '0');
            if (ma >= 65 && ma <= 90) { // K� t? hoa
                i += 2;
            } else if (i + 2 < n) {
                ma = ma * 10 + (ma_hoa[i + 2] - '0'); // K� t? thu?ng
                if (ma >= 97 && ma <= 122) {
                    i += 3;
                }
            }
        }

        // G�n k� t? d� gi?i m� v�o k?t qu?
        ket_qua[index_ket_qua++] = (char)ma;
    }

    ket_qua[index_ket_qua] = '\0'; // K?t th�c chu?i
    printf("%s\n", ket_qua);
}

int main() {
    char ma_hoa[101];
    printf("Nh?p chu?i m� h�a ASCII: ");
    scanf("%s", ma_hoa);

    printf("Chu?i g?c: ");
    giaiMa(ma_hoa);

    return 0;
}

