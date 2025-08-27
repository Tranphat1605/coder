#include <stdio.h>

int ucln(int a,int b){
    if(a==0) return b;
    return ucln(b%a,a);
}
int bcnn(int a,int b){
    return a*b/ucln(a,b);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("UCLN cua a va b la: %d\n",ucln(a,b));
    printf("BCNN cua a va b la: %d",bcnn(a,b));
    return 0;
}