#include <stdio.h>
#include <stdlib.h>
int n,a[100],k,ok;
void ktao(int k){
    int i=1;
    for(i;i<=k;i++){
        a[i]=i;
    }
}
void gen(int k, int n){
    int i=k;
    while(i>=1 && a[i]==n-k+i) --i;
    if(i==0) ok=0;
    else{
        a[i]++;
        int j=i+1;
        for(j;j<=k;++j){
            a[j]=a[j-1]+1;
        }
    }
}
int main()
{
    scanf("%d",&n);
    k=0;
    for(k;k<=n;k++){
        ok=1;
        ktao(k);
        while(ok){
            int i=1;
            for(i;i<=k;i++){
                printf("%c",a[i]+96);
            }
            printf("\n");
            gen(k,n);
        }
    }
    return 0;
}