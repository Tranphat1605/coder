#include <bits/stdc++.h> 

using namespace std;

int x, k, n, f;
vector<int> pl, a;
vector<bool> used;

bool dff(int cout, int sum) {
	if (sum > f) return false;
	if (sum == f) {
		if (cout == k-1) return true;
		if (dff(cout + 1, 0)) return true;
	}
	
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		used[i] = true;
		pl[i] = cout;
		if (dff(cout, sum+a[i])) return true;
		used[i] = false;
	}
	return false;
}

void solve() {
	if (x%k>0) {
		cout << "ze" << endl;
		return;
	}
	f = x/k;
	if (dff(0, 0)) {
		for (int i = 0; i < n; i++) {
			cout << pl[i] + 1 << " ";
		}	
		return;
	}
	cout << "ze";
}

int main () {
	cin >> n >> k;
	a.resize(n);
	pl.resize(n);
	used.resize(n, false);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		x += a[i];
	}
	solve () ;
	return 0;
} 