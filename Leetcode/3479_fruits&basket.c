#include <stdio.h>
#include <stdbool.h>

int cmp(const void*a, const void*b) {
    return *(int*)a-*(int*)b;
}
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    qsort(baskets, basketsSize, sizeof(int), cmp);
    int cout = 0;
    bool check[basketsSize];   //check đã sử dụng chưa, sử dụng là true
    for (int i = 0; i < basketsSize; i++) {
        check[i] = false;
    }
    for (int i = 0; i < fruitsSize; i++) {
        bool placed = false;   // check sử dụng chưa, sử dụng là true
        for (int j = 0; j < basketsSize; j++) {
            if (check[j] == false && fruits[i] <= baskets[j]) {
                check[j] = true;
                placed = true;
                break;
            }
        }
        if (placed == false) {
            cout++;
        }
    }
    return cout;
}