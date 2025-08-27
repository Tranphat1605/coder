#include <stdio.h>
#include <nath.h>

int search(int *nums, int numsSize, int target){
    int l = 0, r = numsSize - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int searchInsert(int* nums, int numsSize, int target){
    int s = search(nums, numsSize, target);
    if (s >= 0 ) {
        return s;
    } else {
        return -s - 1;
    }
}