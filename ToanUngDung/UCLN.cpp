#include <bits/stdc++.h>

using namespace std;

int ucln (int a, int b){
	int r; 
	if (a == 0 ||b == 0) {
		return a + b;
	}
	while ( b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
} 
int main(){
    int a, b;
    cin >> a >> b;
    cout << ucln(a, b);
}
