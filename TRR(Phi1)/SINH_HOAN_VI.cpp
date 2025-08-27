#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000006];
int constrain=1;

void init(){
	for (int i=1;i<=n; i++){
		a[i]=i;
	}
}

void Generation(){
	while(constrain){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		int i=n-1;
		while(i>=1&&a[i]>a[i+1]){
			i--;
		}
		if(i){
			for(int j=n;j>=i+1;j--){
				if(a[j]>a[i]){
					swap(a[j],a[i]);
					break;
				}
			}
			reverse(a+i+1,a+n+1);
		}
		else{
			constrain=0;
		}
	}
}
int main(){
	cin>>n;
	init();
	Generation();
	return 0;
}