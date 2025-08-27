// cho hệ thức truy hồi 5f(n-1)-6f(n-2) f1 = 1, f2 = 5 viết hàm đệ qiuy tính fn




#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0) return 1;
    if (n == 1) return 12;
    return 4 * f(n - 1) + 32 * f(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

vector<int> memo(1000, -1); // Khởi tạo mảng lưu kết quả, -1 là chưa tính

int f(int n) {
    if (memo[n] != -1) return memo[n]; // Đã tính rồi thì trả lại
    if (n == 1) return memo[n] = 1;
    if (n == 2) return memo[n] = 5;
    return memo[n] = 5 * f(n - 1) - 6 * f(n - 2);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}


