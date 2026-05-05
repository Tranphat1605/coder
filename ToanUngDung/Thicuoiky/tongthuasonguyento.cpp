#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính tổng các ước dựa trên phân tích thừa số nguyên tố
long long tinhTongCacUoc(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long temp = n;
    long long tong = 1;

    // 1. Xử lý thừa số 2
    if (temp % 2 == 0) {
        long long p_pow = 1;
        long long p_sum = 1;
        while (temp % 2 == 0) {
            p_pow *= 2;      // Tính 2^1, 2^2, 2^3...
            p_sum += p_pow;  // Cộng dồn 1 + 2 + 4 + 8...
            temp /= 2;
        }
        tong *= p_sum;
    }

    // 2. Xử lý các số lẻ từ 3 đến sqrt(temp)
    for (long long i = 3; i <= sqrt(temp); i += 2) {
        if (temp % i == 0) {
            long long p_pow = 1;
            long long p_sum = 1;
            while (temp % i == 0) {
                p_pow *= i;
                p_sum += p_pow;
                temp /= i;
            }
            tong *= p_sum;
        }
    }

    // 3. Nếu còn lại một số nguyên tố lớn hơn sqrt(temp)
    if (temp > 1) {
        tong *= (1 + temp); // Theo công thức (temp^2 - 1) / (temp - 1) = temp + 1
    }

    return tong;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;

    long long ketQua = tinhTongCacUoc(n);
    
    cout << "Tong cac uoc cua " << n << " la: " << ketQua << endl;

    cout << "Cac so hoan hao trong khoang tu 1 den " << n << " la: " << endl;
    for (long long i = 1; i <= n; i++) {
        long long sumDivisors = tinhTongCacUoc(i) - i; // Loại bỏ chính nó
        if (sumDivisors == i) {
            cout << i << " ";
        }
    }
    
    // Kiểm tra số hoàn hảo (Perfect Number)
    // if (ketQua == 2 * n) {
    //     cout << n << " la so hoan hao!" << endl;
    // }

    return 0;
}