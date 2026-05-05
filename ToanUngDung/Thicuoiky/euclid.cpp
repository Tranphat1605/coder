#include <iostream>
using namespace std;

// Cách 1: Sử dụng đệ quy (Gọn nhẹ)
int gcdRecursive(int n, int m) {
    if (m == 0) return n; // gcd(n, 0) = n
    return gcdRecursive(m, n % m);
}

// Cách 2: Sử dụng vòng lặp (Tối ưu bộ nhớ)
int gcdIterative(int n, int m) {
    while (m != 0) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main() {
    int a, b;
    cout << "Nhap hai so a va b: ";
    cin >> a >> b;

    cout << "GCD cua " << a << " va " << b << " (De quy) la: " << gcdRecursive(a, b) << endl;
    cout << "GCD cua " << a << " va " << b << " (Vong lap) la: " << gcdIterative(a, b) << endl;

    // Tinh luon LCM dua tren GCD: LCM(a, b) = (a * b) / GCD(a, b)
    int lcm = (a * b) / gcdIterative(a, b);
    cout << "LCM cua " << a << " va " << b << " la: " << lcm << endl;

    return 0;
}