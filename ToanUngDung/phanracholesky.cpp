#include <bits/stdc++.h>
using namespace std;

// Hàm nhập ma trận
void nhap(vector<vector<double>> &A, int n) {
    cout << "Nhap ma tran " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
}

// Kiểm tra ma trận vuông
bool isSquare(const vector<vector<double>> &A) {
    int n = A.size();
    for (auto row : A) {
        if ((int)row.size() != n) return false;
    }
    return true;
}

// Kiểm tra ma trận đối xứng
bool isSymmetric(const vector<vector<double>> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (fabs(A[i][j] - A[j][i]) > 1e-9) return false;
        }
    }
    return true;
}

// Kiểm tra xác định dương bằng leading principal minors (định thức con)
bool isPositiveDefinite(const vector<vector<double>> &A) {
    int n = A.size();
    for (int k = 1; k <= n; k++) {
        vector<vector<double>> sub(k, vector<double>(k));
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                sub[i][j] = A[i][j];

        // Tính định thức
        double det = 1;
        vector<vector<double>> B = sub;
        for (int i = 0; i < k; i++) {
            if (fabs(B[i][i]) < 1e-9) return false;
            det *= B[i][i];
            for (int j = i+1; j < k; j++) {
                double ratio = B[j][i] / B[i][i];
                for (int l = i; l < k; l++) {
                    B[j][l] -= ratio * B[i][l];
                }
            }
        }
        if (det <= 0) return false;
    }
    return true;
}

// Hàm phân rã Cholesky
vector<vector<double>> cholesky(const vector<vector<double>> &A) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];

            if (i == j) {
                L[i][j] = sqrt(A[i][i] - sum);
            } else {
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return L;
}

int main() {
    int n;
    cout << "Nhap cap ma tran: ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));

    nhap(A, n);

    if (!isSquare(A)) {
        cout << "Khong phai ma tran vuong!\n";
        return 0;
    }

    if (!isSymmetric(A)) {
        cout << "Khong phai ma tran doi xung!\n";
        return 0;
    }

    if (!isPositiveDefinite(A)) {
        cout << "Ma tran khong xac dinh duong!\n";
        return 0;
    }

    auto L = cholesky(A);

    cout << "Ma tran L sau khi phan ra Cholesky:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(4) << L[i][j] << " ";
        cout << endl;
    }
    return 0;
}

// Thuật toán Cholesky(A, n)

// Bước 1: Kiểm tra ma trận
//     - Nếu A không vuông → dừng, báo lỗi.
//     - Nếu A không đối xứng → dừng, báo lỗi.
//     - Nếu A không xác định dương → dừng, báo lỗi.

// Bước 2: Khởi tạo
//     - Tạo ma trận L[n][n] toàn số 0.

// Bước 3: Vòng lặp chính
//     For i = 0 → n-1:
//         For j = 0 → i:
//             sum = 0
//             For k = 0 → j-1:
//                 sum = sum + L[i][k] * L[j][k]

//             Nếu i == j:
//                 L[i][j] = sqrt( A[i][i] - sum )
//             Ngược lại (i > j):
//                 L[i][j] = ( A[i][j] - sum ) / L[j][j]

// Bước 4: Xuất kết quả
//     - In ra ma trận L.
