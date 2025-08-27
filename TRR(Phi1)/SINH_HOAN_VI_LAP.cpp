#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000006];
bool constrain=true;

void init(){
	for (int i=1;i<=n; i++){
		a[i]=1;
	}
}

void Generation(){
	while(constrain){
		for (int i=1;i<=n ; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		int i=n;
		while(i>=1&&a[i]==n){
			i--;
		}
		if(i){
			a[i]++;
			for(int j=i+1;j<=n;j++){
				a[j]=1;
			}
		}
		else{
			constrain=false;
		}
	}
}
int main(){
	cin>>n;
	init();
	Generation();
	
}