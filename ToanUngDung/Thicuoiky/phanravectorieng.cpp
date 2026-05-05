#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

// Hàm nhân hai ma trận vuông cấp n
void nhanMaTran(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }
}

// Đưa ma trận về dạng Frobenius bằng Danilevskii
bool duaVeFrobenius(vector<vector<double>>& A, vector<vector<double>>& maVT, int n) {
    for (int k = n - 2; k >= 0; k--) {
        if (abs(A[k + 1][k]) < EPS) {
            bool swapped = false;
            for (int j = k - 1; j >= 0; j--) {
                if (abs(A[k + 1][j]) > EPS) {
                    for (int row = 0; row < n; row++) swap(A[row][k], A[row][j]);
                    for (int row = 0; row < n; row++) swap(maVT[row][k], maVT[row][j]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) return false;
        }

        vector<vector<double>> M(n, vector<double>(n, 0)), M_inv(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) M[i][i] = M_inv[i][i] = 1.0;

        for (int j = 0; j < n; j++) {
            if (j == k) M[k][j] = 1.0 / A[k + 1][k];
            else M[k][j] = -A[k + 1][j] / A[k + 1][k];
            M_inv[k][j] = A[k + 1][j];
        }

        vector<vector<double>> Temp(n, vector<double>(n, 0)), TmpVT(n, vector<double>(n, 0));
        nhanMaTran(M_inv, A, Temp, n);
        nhanMaTran(Temp, M, A, n);
        nhanMaTran(maVT, M, TmpVT, n);
        maVT = TmpVT;
    }
    return true;
}

// Tính P(x) và P'(x) bằng lược đồ Horner để tối ưu tốc độ
pair<double, double> tinhDaThuc(const vector<double>& p, double x, int n) {
    double val = pow(x, n);
    double der = n * pow(x, n - 1);
    for (int i = 0; i < n; i++) {
        val -= p[i] * pow(x, n - 1 - i);
        if (n - 1 - i > 0) der -= (n - 1 - i) * p[i] * pow(x, n - 2 - i);
    }
    return {val, der};
}

// Giải phương trình bậc 2/3 bằng công thức hoặc Newton cho n > 3
vector<double> timLambdas(const vector<vector<double>>& A, int n) {
    vector<double> nghiem;
    // Thuật toán Newton-Raphson tìm nghiệm thực
    vector<double> p; 
    for(int j = 0; j < n; j++) p.push_back(A[0][j]);
    for (double x0 = -20.0; x0 <= 20.0 && nghiem.size() < n; x0 += 0.5) {
        double x = x0;
        for (int iter = 0; iter < 200; iter++) {
            pair<double, double> res = tinhDaThuc(p, x, n);
            if (abs(res.second) < 1e-10) break;
            double x_next = x - res.first / res.second;
            if (abs(x_next - x) < 1e-8) {
                bool exists = false;
                for (double r : nghiem) if (abs(r - x_next) < 1e-4) exists = true;
                if (!exists) nghiem.push_back(x_next);
                break;
            }
            x = x_next;
        }
    }
    sort(nghiem.rbegin(), nghiem.rend()); // Sắp xếp trị riêng từ lớn đến bé
    return nghiem;
}

int main() {
    int n;
    cout << "Nhap cap ma tran n: "; cin >> n;
    vector<vector<double>> A(n, vector<double>(n)), maVT(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        maVT[i][i] = 1.0;
        for (int j = 0; j < n; j++) cin >> A[i][j];
    }

    if (!duaVeFrobenius(A, maVT, n)) {
        cout << "Ma tran khong the dua ve dang Frobenius!" << endl;
        return 0;
    }

    vector<double> lambdas = timLambdas(A, n);
    
    cout << fixed << setprecision(4) << "\nCac tri rieng tim duoc: ";
    for (double l : lambdas) cout << l << "  ";
    cout << "\n" << string(40, '-') << endl;

    for (double l : lambdas) {
        cout << "Lambda = " << setw(8) << l << " | Vector rieng: ";
        vector<double> y(n), x(n, 0);
        for (int i = 0; i < n; i++) y[i] = pow(l, n - 1 - i);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) x[i] += maVT[i][j] * y[j];
            cout << setw(8) << (abs(x[i]) < 1e-6 ? 0 : x[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}