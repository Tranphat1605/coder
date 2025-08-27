#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 101

void giaiMa(char* maHoa, char* vanBanGoc) {
    int i = 0, j = 0;
    while (i < strlen(maHoa)) {
        char temp[3] = {maHoa[i], maHoa[i + 1], '\0'};
        int maASCII = atoi(temp);

        if ((maASCII >= 65 && maASCII <= 90) || (maASCII >= 97 && maASCII <= 122)) {
            vanBanGoc[j++] = (char)maASCII;
            i += 2;
        } else {
            temp[2] = maHoa[i + 2];
            maASCII = atoi(temp);
            vanBanGoc[j++] = (char)maASCII;
            i += 3;
        }
    }
    vanBanGoc[j] = '\0';
}

int main() {
    char maHoa[MAX_LENGTH];
    char vanBanGoc[MAX_LENGTH];

    printf("Nh?p chu?i ð? m? hóa: ");
    scanf("%s", maHoa);

    giaiMa(maHoa, vanBanGoc);

    printf("Chu?i g?c: %s\n", vanBanGoc);

    return 0;
}

