#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0) return 1;
    if (n == 1) return 12;
    return 4 * f(n - 1) + 32 * f(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}
