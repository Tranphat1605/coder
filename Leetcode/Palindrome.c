#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x <0) return false;
    if (x < 10 && x >= 0) return true;
    int daonguoc = 0, tmp = x;
    while (tmp > 0) {
        daonguoc = daonguoc * 10 + tmp % 10;
        tmp /= 10;
    }
    return daonguoc == x;
}