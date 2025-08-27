#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct NganXep {
    char* phanTu[100];
    int dinh;
} NganXep;

void khoiTaoNganXep(NganXep* s) {
    s->dinh = -1;
}

int nganXepRong(NganXep* s) {
    return s->dinh == -1;
}

void dayVaoNganXep(NganXep* s, char* str) {
    s->phanTu[++(s->dinh)] = strdup(str);
}

char* layTuNganXep(NganXep* s) {
    if (nganXepRong(s)) {
        return "";
    }
    return s->phanTu[(s->dinh)--];
}

int laToanTu(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

char* tienToSangHauTo(char* bieuThucTienTo) {
    NganXep s;
    khoiTaoNganXep(&s);
    int doDai = strlen(bieuThucTienTo);
    
    for (int i = doDai - 1; i >= 0; i--) {
        if (laToanTu(bieuThucTienTo[i])) {
            char* toanHang1 = layTuNganXep(&s);
            char* toanHang2 = layTuNganXep(&s);
            
            char* tam = (char*)malloc(strlen(toanHang1) + strlen(toanHang2) + 2);
            sprintf(tam, "%s%s%c", toanHang1, toanHang2, bieuThucTienTo[i]);
            
            dayVaoNganXep(&s, tam);
        } else {
            char tam[2] = {bieuThucTienTo[i], '\0'};
            dayVaoNganXep(&s, tam);
        }
    }
    return layTuNganXep(&s);
}

int main() {
    char bieuThucTienTo[100];
    
    fgets(bieuThucTienTo, 100, stdin);
    bieuThucTienTo[strcspn(bieuThucTienTo, "\n")] = '\0';
    
    char* bieuThucHauTo = tienToSangHauTo(bieuThucTienTo);
    printf("%s", bieuThucHauTo);
    
    return 0;
}