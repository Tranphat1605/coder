#include <stdio.h>

void printSubset(int arr[], int n, int mask) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) { // Kiểm tra bit thứ i có bằng 1 không
            printf("%d ", arr[i]);
        }
    }
    printf("}\n");
}

void generateSubsets(int N) {
    int arr[N]; 
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1; // Tạo tập {1, 2, ..., N}
    }

    int total = 1 << N; // 2^N tập con
    for (int mask = 0; mask < total; mask++) {
        printSubset(arr, N, mask);
    }
}

int main() {
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N phai lon hon 0!\n");
        return 1;
    }

    printf("Cac tap con cua tap {1, 2, ..., %d} la:\n", N);
    generateSubsets(N);

    return 0;
}

