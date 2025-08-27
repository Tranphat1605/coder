#include <bits/stdc++.h>

using namespace std;



int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

void sangnt(int n) {
    int A[n - 1];
    for (int i = 0; i < n - 1; i++) {
        A[i] = 1;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = max(i * i, ((2 + i - 1) / i) * i); j <= n; j += i) {
            A[j - 2] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (A[i - 2]) {
            cout<<i<<" ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    sangnt(n);

    return 0;
}
