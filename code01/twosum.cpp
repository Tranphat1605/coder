#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int main() {
    int a[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }
    int n;
    scanf("%d", &n);

    // Kh?i t?o hash table
    int *hash = (int*) calloc(2000001, sizeof(int)); // Gi? s? giá tr? c?a a[i] n?m trong kho?ng [-1e6, 1e6]

    for (int i = 0; i < SIZE; i++) {
        int complement = n - a[i];
        if (hash[complement + 1000000]) {
            printf("%d %d\n", hash[complement + 1000000] - 1, i);
            free(hash);
            return 0;
        }
        hash[a[i] + 1000000] = i + 1;
    }

    printf("Không t?m th?y c?p s? nào.\n");
    free(hash);
    return 0;
}

