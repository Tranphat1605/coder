
#include <iostream>
using namespace std;

unsigned long long f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return f(n - 1) + f(n - 2);
}


int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}
