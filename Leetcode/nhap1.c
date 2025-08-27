#include <stdio.h>
#include <stdlib.h>
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* res = (int*)malloc((*returnSize) * sizeof(int));

    long val = 1;
    for (int i = 0; i <= rowIndex; i++) {
        res[i] = (int)val;
        val = val * (rowIndex - i) / (i + 1);
    }

    return res;
}

int singleNumber(int* nums, int numsSize) {
    int a[30000] = {0};
    for (int i = 0; i < numsSize; i++) {
        a[nums[i]]++;
    }
    for (int i = 0; i < 30000; i++) {
        if (a[i] == 1) {
            return i;
        }
    }
    return -1;
}

int cmp(const void*a, const void*b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return *x - *y;
}

int missingNumber(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return -1;
}

int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return *x - *y;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int thieu = 1;
    int lap = -1;
    for (int i = 1; i < numsSize; i++) {
      if (nums[i] == nums[i-1]) {
          lap = nums[i];
      }
      else if (nums[i] > nums[i-1] + 1){
        thieu = nums[i-1] + 1;
      }
    }
    if (nums[numsSize-1] != numsSize && thieu == 1 && lap != 1) {
        thieu = numsSize;
    }
    *returnSize = 2;
    int* res = (int*)malloc(*returnSize) * sizeof(int);
    res[0] = lap;
    res[1]= thieu;
    return res;
}






    printf("=========================================================================================================\n");
    printf("|                                          DU AN QUAN LY VAT TU                                          |\n");
    printf("| Sinh vien thuc hien: Duong Si An                                                                       |\n");
    printf("| Sinh vien thuc hien: Tran Van Phat     MSSV: 102240047           Lop: 24T_DT1                          |\n");
    printf("| Giao Vien huong dan: Do Thi Tuyet Hoa                                                                  |\n");
    printf("=========================================================================================================\n\n");