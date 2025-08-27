#include <bits/stdc++.h>

using namespace std;

char one[] = {'a' , 'b', 'c'};
char two[] = {'d', 'e'};
char three[] = {'m', 'n', 't'};
char ans[100006];

void Try(int i){
	if(i == 0){
		for (int j = 0 ; j < 3 ; j++){
			ans[i] = one[j];
			Try(i + 1);
		}
	}
	else if(i == 1){
		for (int j = 0 ; j < 2 ; j++){
			ans[i] = two[j];
			Try(i + 1);
		}
	}
	else{
		for (int j = 0 ; j < 3 ; j++){
			ans[i] = three[j];
			for (int j = 0 ; j < 3 ; j++){
				cout << ans[j] ;
			}
			cout << endl;
		}
		return ;
	}
}
int main(){
	Try(0);
	return 0;	
}