#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cmp1(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int cmp2(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int n, i, j; 
    scanf("%d", &n);
    int A[n], B[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < n; i ++) {
    	B[i] = A[i];
	}
    qsort(A, n, sizeof(int), cmp1);
    int max = A[n-1];
    qsort(A, n, sizeof(int), cmp2);
    int min = A[n-1];
    
    for (i = 0; i < n; i++) {
        if (A[i] == max) {
            for (j = 0; j < n; j++) {
                if (A[j] == min) {
                    swap(&B[i], &B[j]);
                    break;
                }
            }
            break;
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    return 0;
}

