#include<stdio.h>

long long giaithua(int n){

      long long A[100000],i,j,m=1;
      unsigned long long r=0,q;
      A[0]=1;
      for(i=2;i<=n;i++){
      for(j=0;j<m;j++){
           q=r;
           r=(A[j]*i+r)/10;
          A[j]=(A[j]*i+q)%10;
   }
     while(r>0){
          A[m]=r%10;
          m++;
          r=r/10;}
 }
        for(i=m-1;i>=0;i--)  printf("%d",A[i]);
}
int main(){

       int n;
       printf("nhap n (n<=2000): "); 
	   scanf("%d",&n);
       printf("%d! = ",n );
       giaithua(n);
}
