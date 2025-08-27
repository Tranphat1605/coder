#include <iostream>
using namespace std;

bool shh(int n) {
    int s = 0;
    for (int i = 1 ; i <= n/2 ; i++) {
        if (n%i == 0) {
            s += i;
        }
    }
    if (s == n) {
        return true;
    } else {
        return false;
    }
};

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (shh(i)) {
            cout << i << " ";
        }
    }
    return 0;
}