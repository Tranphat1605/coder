// Tìm số hoàn hảo từ 1 đến N

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm tính tổng các ước thực sự (không tính chính nó)
// Sử dụng phân tích thừa số nguyên tố để tối ưu tốc độ
long long sumOfProperDivisors(long long n) {
    if (n < 2) return 0;
    long long temp = n;
    long long totalSum = 1; // 1 luôn là ước của mọi số n > 1

    // Xử lý thừa số 2
    if (temp % 2 == 0) {
        long long p_pow = 1;
        long long p_sum = 1;
        while (temp % 2 == 0) {
            p_pow *= 2;
            p_sum += p_pow;
            temp /= 2;
        }
        totalSum *= p_sum;
    }

    // Xử lý các thừa số lẻ từ 3 trở đi
    for (long long i = 3; i * i <= temp; i += 2) {
        if (temp % i == 0) {
            long long p_pow = 1;
            long long p_sum = 1;
            while (temp % i == 0) {
                p_pow *= i;
                p_sum += p_pow;
                temp /= i;
            }
            totalSum *= p_sum;
        }
    }

    // Nếu còn lại một số nguyên tố lớn hơn sqrt
    if (temp > 1) {
        totalSum *= (1 + temp);
    }

    // Tổng các ước thực sự = Tổng tất cả các ước - chính nó
    return totalSum - n;
}



int main() {
    long long N;
    cout << "Nhap gia tri N: ";
    cin >> N;

    vector<long long> perfectNumbers;
    
    // Duyệt từ 2 đến N-1
    for (long long i = 2; i < N; i++) {
        if (sumOfProperDivisors(i) == i) {
            perfectNumbers.push_back(i);
        }
    }

    // Xuất kết quả
    cout << "------------------------------------" << endl;
    cout << "So luong so hoan hao nho hon " << N << " la: " << perfectNumbers.size() << endl;
    if (perfectNumbers.size() > 0) {
        cout << "Danh sach cac so: ";
        for (int i = 0; i < perfectNumbers.size(); i++) {
            cout << perfectNumbers[i] << (i == perfectNumbers.size() - 1 ? "" : ", ");
        }
        cout << endl;
    }
    
    return 0;
}