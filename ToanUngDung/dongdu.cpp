
// TrungHoa.cpp

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int TrungHoa(int k, int m[], int a[], int X[], int X_1[], int &M)
{
    M = 1;
    int ans = 0;
    for (int i = 0; i < k; ++i)
        M = M * m[i];
    for (int i = 0; i < k; ++i)
        X[i] = M / m[i];
    for (int i = 0; i < k; ++i)
    {
        int j = 1;
        while ((j * m[i] + 1) % X[i] != 0)
        {
            j++;
        }
        X_1[i] = (j * m[i] + 1) / X[i];
    }
    for (int i = 0; i < k; ++i)
        ans = ans + (a[i] * X[i] * X_1[i]);
    return ans;
}
int main()
{
    int k;
    int M;
    cout << "Nhap so luong phuong trinh can tinh : ";
    cin >> k;
    int m[k + 1], a[k + 1], X[k + 1], X_1[k + 1];
    bool kt;
    for (int i = 0; i < k; ++i)
    {
        cout << "a[" << i + 1 << "] " << " = ";
        cin >> a[i];
        cout << "m[" << i + 1 << "] " << " = ";
        cin >> m[i];
        do
        {
            kt = true;
            for (int j = 0; j < i; ++j)
                if (gcd(m[i], m[j]) != 1)
                {
                    cout << "Nhap lai m[" << i + 1 << "] " << " = ";
                    cin >> m[i];
                    kt = false;
                    break;
                }
        } while (!kt);
    }
    int i = 0;
    int ans = TrungHoa(k, m, a, X, X_1, M);
    int x = ans % M;
    cout << "Phuong trinh can tim la : " << x << " + " << "k" << " * " << M << '\n';
}

// Input: 
//     - k: số lượng phương trình
//     - a[i]: số dư của phương trình thứ i
//     - m[i]: mô đun của phương trình thứ i (đôi một nguyên tố cùng nhau)

// Output:
//     - Nghiệm tổng quát: x = x0 + k*M

// Bước 1: Kiểm tra các m[i]
//     For i = 1 → k:
//         For j = 1 → i-1:
//             Nếu gcd(m[i], m[j]) ≠ 1 thì báo lỗi (không áp dụng được CRT).

// Bước 2: Tính tích mô-đun
//     M = 1
//     For i = 1 → k:
//         M = M * m[i]

// Bước 3: Tính các X[i]
//     For i = 1 → k:
//         X[i] = M / m[i]

// Bước 4: Tìm nghịch đảo X[i] theo modulo m[i]
//     For i = 1 → k:
//         Tìm X_1[i] sao cho (X[i] * X_1[i]) ≡ 1 (mod m[i])
//         (thực hiện bằng cách thử j = 1, 2, 3,… cho đến khi thỏa)

// Bước 5: Tính nghiệm riêng x0
//     x0 = 0
//     For i = 1 → k:
//         x0 = x0 + a[i] * X[i] * X_1[i]

// Bước 6: Lấy nghiệm chuẩn hóa
//     x0 = x0 mod M

// Bước 7: Xuất nghiệm tổng quát
//     x = x0 + t*M   với t ∈ Z
