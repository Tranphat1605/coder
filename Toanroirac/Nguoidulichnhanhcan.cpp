#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n; // 🔧 Thiếu biến này trong đoạn gốc
int c[105][105], X[100]; // Ma trận chi phí và mảng lưu hành trình
int visited[105]; // Đánh dấu thành phố đã đi qua
int d = 0; // Tổng chi phí hiện tại
int ans = INT_MAX; // Kết quả tốt nhất tìm được
int dem = 0; // Đếm số lần gọi Try
int cmin = INT_MAX; // Chi phí nhỏ nhất giữa 2 thành phố bất kỳ

// Nhập dữ liệu đầu vào và tìm cmin
void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 0) {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}

// Hàm quay lui tìm hành trình tối ưu
void Try(int i) {
    ++dem;
    for (int j = 2; j <= n; j++) { // Bỏ j=1 vì X[1]=1 cố định
        if (!visited[j]) {
            visited[j] = 1;
            X[i] = j;
            d += c[X[i - 1]][X[i]];

            if (i == n) {
                // Hoàn thành 1 hành trình, cộng thêm chi phí về lại điểm xuất phát
                ans = min(ans, d + c[X[n]][X[1]]);
            } else if (d + (n - i + 1) * cmin < ans) {
                // Cắt nhánh nếu không thể có lời giải tốt hơn
                Try(i + 1);
            }

            // Quay lui
            visited[j] = 0;
            d -= c[X[i - 1]][X[i]];
        }
    }
}

int main() {
    nhap();
    X[1] = 1; // Xuất phát từ thành phố 1
    visited[1] = 1;
    Try(2);
    cout << "Chi phi nho nhat: " << ans << "\n";
    cout << "So lan goi ham Try: " << dem << "\n";
    return 0;
}
