#include <stdio.h>
int a[1005];
int n;
int use[1005];
void lien_quan_mobile(int i){
	for(int j=1;j<=n;j++){
		if(!use[j]){
			a[i]=j;
			use[j]=1;
			if(i==n){
				for(int k=1;k<=n;k++){
					printf("%d ",a[k]);
				}
				printf("\n");
			}
			else {
				lien_quan_mobile(i+1);
			}
			use[j]=0;
		}	
	}
}
int main(){
	scanf("%d",&n);
	lien_quan_mobile(1);
}