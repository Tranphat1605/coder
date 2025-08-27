#include <stdio.h>
int n;
int a[1005];
int b[1005];
void quaylui(int x){
	for(int i=0;i<2;i++){
		b[x]=i;
		if(x==n){
			for(int k=0;k<n;k++){
				int ans=b[k+1]*a[k];
				printf("%d ",ans);
			}
			printf("\n");
		}
		else quaylui(x+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	int x=1;
	quaylui(x);
}