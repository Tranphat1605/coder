#include <iostream>
#include <vector>
using namespace std;

void sieveEratosthenes(long long n) {
    // Tạo mảng boolean đánh dấu, mặc định ban đầu tất cả là true (số nguyên tố)
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 và 1 không phải số nguyên tố

    for (long long p = 2; p * p <= n; p++) {
        // Nếu p chưa bị xóa, thì p là số nguyên tố
        if (isPrime[p]) {
            // Xóa tất cả các bội của p bắt đầu từ p*p
            for (long long i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    // In danh sách các số nguyên tố tìm được
    cout << "Cac so nguyen to tu 2 den " << n << " la: " << endl;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            cout << p << " ";
    }
    cout << endl;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    sieveEratosthenes(n);
    return 0;
}