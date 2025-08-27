#include <bits/stdc++.h>

using namespace std;

void chinhhop(int n, int k, vector<int> &s, vector<bool> &check) {
    if (s.size() == k) {
        for (int x : s) {
            cout << x << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            s.push_back(i);
            check[i] = true;
            chinhhop(n, k, s, check);
            s.pop_back();
            check[i] = false;
        }
    }
}


int main() {
    int n, k;   
    cin >> n >> k;
    vector<int> s;  
    vector<bool> check(n + 1, false);
    chinhhop(n, k, s, check);
    return 0;
}