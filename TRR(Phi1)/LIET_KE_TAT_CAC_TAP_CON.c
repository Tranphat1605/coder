#include <stdio.h>
int a[100];
int n;
int main(){
	scanf("%d",&n);
	int stop=0;
	while(stop==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				printf("%d ",i);
			}
		}
		printf("\n");
		int j=n;
		while(j>=1){
			if(a[j]==1){
				a[j]=0;
				j--;
			}
			else break;
		}
		if(j!=0){
			a[j]=1;
		}
		else stop=1;
	}
}