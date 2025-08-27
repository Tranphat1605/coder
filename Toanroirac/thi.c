#include <stdio.h>
#include <stdlib.h>
#define ll long long
void out(ll a[],ll k){
    ll i=1;
    for(i;i<=k;i++)
        printf("%lld",a[i]);
    printf("\n");
}
int in(ll i,ll a[],ll n,ll k){
	int s = 0;
    int j=0;
    for(j;j<=n;j++){
        a[i]=j;
        if(i==k-1){
            a[k]=n-a[i];
            s++;
        }
        else in(i+1,a,n-a[i],k);
    }
    return s;
}

int main()
{
    ll a[1000],n,k;
    scanf("%lld %lld",&n,&k);
    long long p = in(1,a,n,k);
    printf ("%lld", p);
    return 0;
}
