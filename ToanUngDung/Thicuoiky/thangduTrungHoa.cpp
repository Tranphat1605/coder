// #include <iostream>
// #include <vector>

// using namespace std;

// // Hàm Euclid mở rộng để tìm nghịch đảo mô-đun
// // Tìm x sao cho (a * x) % m == 1
// long long extendedGCD(long long a, long long m, long long &x, long long &y) {
//     if (m == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     long long x1, y1;
//     long long d = extendedGCD(m, a % m, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / m);
//     return d;
// }

// // Hàm tìm nghịch đảo mô-đun của a theo mô-đun m
// long long modInverse(long long a, long long m) {
//     long long x, y;
//     long long g = extendedGCD(a, m, x, y);
//     if (g != 1) return -1; // Không tồn tại nghịch đảo
//     return (x % m + m) % m;
// }

// // Hàm giải hệ phương trình thặng dư Trung Hoa
// long long solveCRT(const vector<long long>& a, const vector<long long>& m) {
//     long long M = 1;
//     for (long long x : m) M *= x;

//     long long result = 0;
//     for (int i = 0; i < a.size(); i++) {
//         long long Mi = M / m[i];
//         long long yi = modInverse(Mi, m[i]);
        
//         // Công thức: x = tổng (ai * Mi * yi) mod M
//         result = (result + a[i] * Mi % M * yi) % M;
//     }

//     return (result + M) % M;
// }

// int main() {
//     int k;
//     cout << "Nhap so luong phuong trinh (k): ";
//     cin >> k;

//     vector<long long> a(k), m(k);
//     cout << "Nhap cac cap (a_i, m_i) sao cho x \u2261 a_i (mod m_i):" << endl;
//     for (int i = 0; i < k; i++) {
//         cout << "Phuong trinh " << i + 1 << " (a m): ";
//         cin >> a[i] >> m[i];
//     }

//     long long x = solveCRT(a, m);
    
//     long long M = 1;
//     for (long long val : m) M *= val;

//     cout << "-----------------------------------" << endl;
//     cout << "Nghiem duy nhat cua he la: x = " << x << " (mod " << M << ")" << endl;
//     cout << "Gia tri x nho nhat la: " << x << endl;

//     return 0;
// }




#include <iostream>
#include <vector>

using namespace std;

// 1. Tự viết hàm tìm GCD (Ước chung lớn nhất) bằng thuật toán Euclid
long long findGCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 2. Thuật toán Euclid mở rộng để tìm nghịch đảo mô-đun
// Tìm x sao cho (a * x) % m == 1
long long extendedGCD(long long a, long long m, long long &x, long long &y) {
    if (m == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extendedGCD(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a / m) * y1;
    return d;
}

// 3. Hàm tìm nghịch đảo mô-đun (không dùng thư viện)
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGCD(a, m, x, y);
    if (g != 1) return -1; // Không tồn tại nếu không nguyên tố cùng nhau
    return (x % m + m) % m; // Đảm bảo kết quả dương
}

// 4. Kiểm tra điều kiện các m_i nguyên tố cùng nhau từng đôi một
bool checkPairwiseRelativelyPrime(const vector<long long>& m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = i + 1; j < m.size(); j++) {
            if (findGCD(m[i], m[j]) != 1) return false;
        }
    }
    return true;
}

int main() {
    int k;
    cout << "Nhap so luong phuong trinh (k): ";
    cin >> k;

    vector<long long> a(k), m(k);
    cout << "Nhap danh sach a1...ak: ";
    for (int i = 0; i < k; i++) cin >> a[i];
    cout << "Nhap danh sach m1...mk: ";
    for (int i = 0; i < k; i++) cin >> m[i];

    // Kiểm tra điều kiện
    if (!checkPairwiseRelativelyPrime(m)) {
        cout << "Loi: Cac m_i khong nguyen to cung nhau tung doi mot!" << endl;
        return 0;
    }

    // Tính M = m1 * m2 * ... * mk
    long long M = 1;
    for (int i = 0; i < k; i++) M *= m[i];

    // Tính nghiệm theo công thức CRT
    long long x = 0;
    for (int i = 0; i < k; i++) {
        long long Mi = M / m[i];
        long long yi = modInverse(Mi, m[i]);
        
        // Cộng dồn: a_i * M_i * y_i
        // Dùng % M ở mỗi bước để tránh tràn số long long
        long long term = (a[i] * Mi) % M;
        term = (term * yi) % M;
        x = (x + term) % M;
    }

    cout << "-----------------------------------" << endl;
    cout << "Nghiem duong nho nhat: x = " << (x + M) % M << endl;
    cout << "Tong quat: x = " << (x + M) % M << " + k * " << M << endl;

    return 0;
}