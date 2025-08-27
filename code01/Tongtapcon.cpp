#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool sumt(vector<long long> &a, long long i, long long s, long long k) {
	if (s==k) return true;
	if (i >= a.size() || s > k) return false;
	
	return sumt(a, i+1, s + a[i], k) || sumt (a, i+1, s, k) ;
	
}

int main () {
	long long n; 
	cin >> n; 
	long long k; 
	cin >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (sumt(a, 0, 0, k)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}