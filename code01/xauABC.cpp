#include <bits/stdc++.h>

using namespace std;

void abc(int n, string s) {
    if (n == s.size()) {
        cout << s << endl;
        return; 
    }
    for (char x : {'A', 'B', 'C'}) {
        if ( s.empty() || s.back() != x) {
            abc(n, s + x);
        }
    }
}

int main () {
    int n; 
    cin >> n;
    abc(n, "");
    return 0;
}