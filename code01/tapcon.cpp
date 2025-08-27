#include <bits/stdc++.h>

using namespace std;

void check(int n, int k, vector<int> &s, int start) {
    if (s.size()==k) {
        for (int x : s) {
            cout << x << " ";
        }
        cout << endl;
    }
    for ( int i = start; i <= n ; i++) {
        s.push_back(i);
        check(n, k, s, i + 1);
        s.pop_back(); 
    }
}

int main () {
    int n, k;
    cin >> n >> k; 
    vector <int> s;
    check(n, k, s, 1);
    return 0; 
}
