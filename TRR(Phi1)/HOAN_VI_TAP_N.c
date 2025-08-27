#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void swap(int *a, int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void swap_list(int a[], int n, int i){
	int l=i;
	int r=n;
	while(l<=r){
		swap(&a[l],&a[r]);
		l++;
		r--;
	}
}
int a[100];
int n;
int stop=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	while(stop==0){
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		int i=n-1;
		while(i>=1){
			if(a[i]>a[i+1]){
				i--;
			}
			else break;
		}
		if(i!=0){
			for(int j=n;j>=i+1;j--){
				if(a[j]>a[i]){
					swap(&a[j],&a[i]);
					break;
				}
			}
			swap_list(a,n,i+1);
		}
		else {
			stop=1;
		}
	}
}