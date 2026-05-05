#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm phân tích thừa số nguyên tố
void primeFactorize(long long n) {
    if (n <= 1) {
        cout << n << " khong co thua so nguyen to." << endl;
        return;
    }

    long long temp = n; // Dùng biến tạm để không làm thay đổi n gốc
    cout << n << " = ";
    bool first = true;

    // 1. Kiểm tra thừa số 2 trước để tối ưu các bước sau
    int count2 = 0;
    while (temp % 2 == 0) {
        count2++;
        temp /= 2;
    }
    if (count2 > 0) {
        cout << 2;
        if (count2 > 1) cout << "^" << count2;
        first = false;
    }

    // 2. Kiểm tra các số lẻ từ 3 đến căn bậc hai của temp
    for (long long i = 3; i <= sqrt(temp); i += 2) {
        int count = 0;
        while (temp % i == 0) {
            count++;
            temp /= i;
        }
        if (count > 0) {
            if (!first) cout << " * ";
            cout << i;
            if (count > 1) cout << "^" << count;
            first = false;
        }
    }

    // 3. Nếu còn lại temp > 1 thì đó là số nguyên tố cuối cùng
    if (temp > 1) {
        if (!first) cout << " * ";
        cout << temp;
    }
    cout << endl;
}

int main() {
    long long n;
    cout << "Nhap vao so n: ";
    cin >> n;

    // Kiểm tra số nguyên tố
    if (isPrime(n)) {
        cout << n << " la so nguyen to!" << endl;
    } else {
        cout << n << " khong phai la so nguyen to." << endl;
    }

    // Thực hiện phân tích
    cout << "Tich cac thua so nguyen to cua " << n << " la:" << endl;
    primeFactorize(n);

    return 0;
}