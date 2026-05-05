#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 20000; // Giới hạn sàng đủ lớn để bao quanh M
bool Sieve[MAX + 1];

// Bước 1: Tạo sàng Eratosthenes
void createSieve() {
    fill(Sieve, Sieve + MAX + 1, true);
    Sieve[0] = Sieve[1] = false;
    for (int p = 2; p * p <= MAX; p++) {
        if (Sieve[p]) {
            for (int i = p * p; i <= MAX; i += p)
                Sieve[i] = false;
        }
    }
}

// Bước 2: Hàm tìm số nguyên tố gần nhất của em (đã sửa lỗi)
long long findClosestPrime(int n) {
    if (n <= 2) return 2;

    // Tìm số nguyên tố lớn hơn n
    int i = n + 1;
    while (i <= MAX && !Sieve[i]) {
        i++;
    }

    // Tìm số nguyên tố nhỏ hơn n
    int j = n - 1;
    while (j >= 2 && !Sieve[j]) {
        j--;
    }

    if (abs(n - i) < abs(n - j)) return i;
    if (abs(n - i) > abs(n - j)) return j;
    
    // Trường hợp cách đều
    cout << "Co 2 so nguyen to cach deu: " << j << " và " << i << endl;
    return j; // Trả về số nhỏ hơn làm đại diện
}

int main() {
    createSieve();
    
    int M = 8128; // Giả sử M là số hoàn hảo lớn nhất vừa tìm được
    long long closest = findClosestPrime(M);
    
    cout << "So nguyen to gan " << M << " nhat la: " << closest << endl;
    
    return 0;
}