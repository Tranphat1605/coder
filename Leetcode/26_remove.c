#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int j = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i-1]) {
            nums[j++] = nums[i];
        }
    }
    return j;
}

int main () {
    int a[6] = {1,1,1,2,2,3};
    int x =removeDuplicates(a, 6);
    printf("%d", x);
    return 0;
}