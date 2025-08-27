#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[1000006];
bool condition=true;
int used[1000006];

void Backtrack(int l){
	if(l==k+1){
		for(int j=1;j<=k;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			a[l]=i;
			used[i]=1;
			Backtrack(l+1);
			used[i]=0;
		}
	}
}
int main(){
	cin>>n>>k;
	Backtrack(1);
}