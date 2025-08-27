#include <bits/stdc++.h>

using namespace std;

int ans[100006];
int cnt = 1;

void Try(int i, int target){
	if(i == 2){
		ans[i] = target;
		cout << cnt++ << ". ";
		for (int j = 0 ; j < 3 ; j++){
			cout << ans[j] << ' ';
		}
		cout << endl;
		return;
	}
	for (int j = 0 ; j <= target ; j++){
		ans[i] = j;
		Try(i + 1, target - j);
	}
}
int main(){
	Try(0 , 15);
}