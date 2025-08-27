#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// gcd thường
int64 ucln(int64 a, int64 b){
    if (a == 0 || b == 0) return llabs(a + b);
    a = llabs(a); b = llabs(b);
    while (b != 0) {
        int64 r = a % b;
        a = b;
        b = r;
    }
    return a; // >= 0
}

// Euclid mở rộng: trả về g = gcd(a,b) và tìm x,y sao cho a*x + b*y = g (g >= 0)
int64 egcd(int64 a, int64 b, int64 &x, int64 &y){
    if (b == 0){
        x = (a >= 0 ? 1 : -1); // đảm bảo g = |a|
        y = 0;
        return llabs(a);
    }
    int64 x1, y1;
    int64 g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g; // >= 0
}

// Giải ax + by = c
void solve(int64 a, int64 b, int64 c){
    int64 x0, y0;
    int64 g = egcd(a, b, x0, y0);          // a*x0 + b*y0 = g
    if (c % g != 0){
        cout << "NO\n";
        return;
    }
    // Nhân lên theo q = c/g để được nghiệm cho c
    __int128 q = (__int128)c / g;           // tránh tràn trung gian
    x0 = (int64)((__int128)x0 * q);
    y0 = (int64)((__int128)y0 * q);

    cout << "YES\n";
    cout << x0 << " " << y0 << "\n";        // một nghiệm

    // Nếu muốn in nghiệm tổng quát:
    // x = x0 + t*(b/g),  y = y0 - t*(a/g) với t ∈ Z
    // cout << "x = " << x0 << " + t*" << (b/g)
    //      << ", y = " << y0 << " - t*" << (a/g) << "\n";
}

int main() {
    int64 a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}