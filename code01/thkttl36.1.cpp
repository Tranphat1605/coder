#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxn 5007
int n;
void multi(char* res, int num) {
    int sodu = 0;
    int len = strlen(res);
    
    for (int i = 0; i < len; i++) {
        int tmp = (res[i] - '0') * num + sodu;
        res[i] = (tmp % 10) + '0';
        sodu = tmp / 10;
    }
    
    while (sodu) {
        res[len] = (sodu % 10) + '0';
        sodu /= 10;
        len++;
    }
    res[len] = '\0';
}
void giaithuakep(int n, char* res) {
    res[0] = '1';
    res[1] = '\0';
    for (int i = n; i > 0; i -= 2) {
        multi(res, i);
    }

    int len = strlen(res);
    for (int i = 0; i < len / 2; i++) {
        char tmp = res[i];
        res[i] = res[len - 1 - i];
        res[len - 1 - i] = tmp;
    }
}
int main() {
    char res[maxn] = {0};
    printf("Nhap n: ");
    scanf("%d",&n);
    giaithuakep(n, res);
    printf("%d!! = %s\n", n, res);
    return 0;
}
