#include <stdio.h>
#include <string.h>

void timSoLonNhat(char* so, int n, int k) {
    int nganXep[n];
    int dinh = -1;
    int soChuSoCanXoa = k;

    for (int i = 0; i < n; i++) {
        while (dinh >= 0 && nganXep[dinh] < so[i] - '0' && soChuSoCanXoa > 0) {
            dinh--;
            soChuSoCanXoa--;
        }
        if (dinh < n - k - 1) {
            nganXep[++dinh] = so[i] - '0';
        } else {
            soChuSoCanXoa--;
        }
    }

    for (int i = 0; i <= dinh; i++) {
        printf("%d", nganXep[i]);
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("Nh?p n và k: ");
    scanf("%d %d", &n, &k);
    char so[n + 1];
    printf("Nh?p s? có %d ch? s?: ", n);
    scanf("%s", so);

    printf("S? l?n nh?t sau khi xóa %d ch? s?: ", k);
    timSoLonNhat(so, n, k);

    return 0;
}

