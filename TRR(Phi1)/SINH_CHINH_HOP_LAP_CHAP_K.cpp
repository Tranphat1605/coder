#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int a[10000006];
bool condition=true;

void init(){
	for(int i=1;i<=k; i++){
		a[i]=1;
	}
}

void Generation(){
	while(condition){
		for(int i=1; i<=k ;  i++){
			cout<<a[i]<<" ";
		}
		cout<< endl;
		int i=k;
		while(i>=1&&a[i]==n){
			i--;
		}
		if(i){
			a[i]++;
			for(int j=i+1; j<=n ;j++){
				a[j]=1;
			}
		}
		else{
			condition=false;
		}
	}
}
int main(){
	cin>>n>>k;
	init();
	Generation();
	return 0;
}