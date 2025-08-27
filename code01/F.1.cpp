#include <stdio.h>
#include <string.h>

#define MAXN 500005

char so[MAXN];
char ket_qua[MAXN];

int main() {
    int so_chu_so, so_can_xoa;
    scanf("%d %d", &so_chu_so, &so_can_xoa);
    scanf("%s", so);

    int do_dai_ket_qua = 0; 
    int can_xoa = so_can_xoa; 

    for (int i = 0; i < so_chu_so; i++) {
        while (do_dai_ket_qua > 0 && can_xoa > 0 && ket_qua[do_dai_ket_qua - 1] < so[i]) {
            do_dai_ket_qua--;
            can_xoa--;
        }

        ket_qua[do_dai_ket_qua++] = so[i];
    }


    do_dai_ket_qua -= can_xoa;


    ket_qua[do_dai_ket_qua] = '\0';


    printf("%s\n", ket_qua);

    return 0;
}

