#include <stdio.h>
#include <math.h>

int prime(int n){
    if(n < 2){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n = 10;
    int a[10] = {2, 3, 19, 88, 100, 28, 47, 31, 14, 25};
    for(int i = 0; i < n; i++){
        if(prime(a[i])){
            printf("%d ", a[i]);
        }
    }
    return 0;
}
