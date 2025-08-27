#include <bits/stdc++.h>

using namespace std;

int n, k;

int ans[10000006];
int cnt = 1;

void Try(int i, int start){
	if(i == k){
		cout << cnt++ << ". ";
		for (int j = 0 ; j < i ; j++){
			cout << ans[j] ;
		}
		cout << endl;
		return;
	}
	for (int j = start ; j <= n ; j++){
		ans[i] = j;
		Try(i + 1, j + 1);
	}
}
int main(){
	cin >> n >> k;
	Try(0, 1);
	return 0;
}