#include <bits/stdc++.h>
using namespace std;

// Thuật toán Euclid mở rộng
int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    int A, B, C;
    cout << "Nhap A, B, C: ";
    cin >> A >> B >> C;

    int x0, y0;
    int d = gcdExtended(A, B, x0, y0);

    if (C % d != 0) {
        cout << "Phuong trinh vo nghiem.\n";
    } else {
        x0 *= C / d;
        y0 *= C / d;
        cout << "Nghiem rieng: x0 = " << x0 << ", y0 = " << y0 << endl;
        cout << "Nghiem tong quat:\n";
        cout << "x = " << x0 << " + " << B/d << " * t" << endl;
        cout << "y = " << y0 << " - " << A/d << " * t" << endl;
    }
    return 0;
}

// Thuật toán GiaiDiophantine(A, B, C):

// Bước 1: Sử dụng thuật toán Euclid mở rộng để tìm gcd(A, B) = d
//         đồng thời tìm các hệ số (x, y) sao cho:
//             A*x + B*y = d

// Bước 2: Kiểm tra điều kiện có nghiệm
//         Nếu C không chia hết cho d → phương trình vô nghiệm.

// Bước 3: Nếu C chia hết cho d
//         - Nhân cả x và y với (C/d) để được nghiệm riêng (x0, y0):
//               x0 = x * (C/d)
//               y0 = y * (C/d)

// Bước 4: Viết nghiệm tổng quát
//         x = x0 + (B/d)*t
//         y = y0 - (A/d)*t
//         với t ∈ Z (số nguyên tùy ý).

// Bước 5: Xuất nghiệm
//         - Nghiệm riêng (x0, y0).
//         - Nghiệm tổng quát.