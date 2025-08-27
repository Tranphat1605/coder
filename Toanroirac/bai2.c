#include <stdio.h>
void init(int b[], int n);
void out(int b[], int n);
int islast(int b[], int n);
void gen(int b[], int n);
void method(int b[], int n);
int main(){
int n;
printf("Nhap so n: ");
scanf("%d",&n);
printf("Hoan vi la:\n",n);
int b[n+1];
method(b,n);
return 0;	
}
void nhap (int b[], int n){
	for (int i=1;i<=n;i++) {
	b[i]=i;}
}
void xuat (int b[], int n){
	for (int i=1;i<=n;i++) {
	printf("%d ",b[i]);}
	printf("\n");
}
int islast(int b[], int n){
	for(int i=1;i<=(n-1);i++){
		if(b[i]<b[i+1]) return 0;
	}
	return 1;
}
void gen(int b[], int n){
	int i=n-1;
	while(b[i]>b[i+1]) {
	i--;}
	int j=n;
	while(b[j]<b[i]) j--;
	int t=b[i]; b[i]=b[j]; b[j]=t;
	int l=i+1; int r=n;
	while(l<=r){
		int t=b[l];
		b[l]=b[r];
		b[r]=t;
		l++;r--;
	}
	
}
void method(int b[], int n){
	nhap(b,n);
	xuat(b,n);
	int stop=islast(b,n);
	while(stop==0){
		gen(b,n);
		xuat(b,n);
		stop=islast(b,n);
	} 

}