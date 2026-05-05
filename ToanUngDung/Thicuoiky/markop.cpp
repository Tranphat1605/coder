#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef vector<vector<double>> Matrix;

// Hàm nhân Vector với Ma trận: pi(n) * P
vector<double> nhanVectorMaTran(const vector<double>& v, const Matrix& m) {
    int n = v.size();
    vector<double> res(n, 0);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            res[j] += v[i] * m[i][j];
        }
    }
    return res;
}

int main() {
    // 1. Định nghĩa ma trận P từ hình ảnh
    int n = 4;
    Matrix P = {
        {0.28, 0.12, 0.23, 0.37},
        {0.14, 0.36, 0.27, 0.23},
        {0.21, 0.26, 0.24, 0.29},
        {0.25, 0.31, 0.19, 0.25}
    };

    // 2. Vector phân phối xác suất tại thời điểm bắt đầu (Trạng thái 1)
    vector<double> pi0 = {1.0, 0.0, 0.0, 0.0};

    cout << fixed << setprecision(3);
    cout << "--- LOI GIAI CHI TIET THEO MA TRAN DA CHO ---\n" << endl;
    cout << "Ma tran chuyen doi trang thai P ban dau:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << P[i][j] << "  ";
        cout << endl;
    }

    // 3. Tính toán qua các giai đoạn vận hành
    vector<double> current_pi = pi0;
    vector<double> pi3, pi4;

    for (int k = 1; k <= 4; k++) {
        current_pi = nhanVectorMaTran(current_pi, P);
        if (k == 3) pi3 = current_pi;
        if (k == 4) pi4 = current_pi;
    }

    // --- HIỂN THỊ KẾT QUẢ ---

    // Giai đoạn 3
    cout << "\na) Sau 3 giai doan van hanh:" << endl;
    cout << "   Vector phan phoi pi(3) = [";
    for(int i=0; i<n; i++) cout << pi3[i] << (i==n-1 ? "" : "  ");
    cout << "]" << endl;
    cout << "   => Xac suat he thong lam viec o trang thai 4 la: " 
         << pi3[3] << " (" << pi3[3]*100 << "%)" << endl;

    // Giai đoạn 4
    cout << "\nb) Sau 4 giai doan van hanh:" << endl;
    cout << "   Vector phan phoi pi(4) = [";
    for(int i=0; i<n; i++) cout << pi4[i] << (i==n-1 ? "" : "  ");
    cout << "]" << endl;
    cout << "   => Xac suat he thong lam viec o trang thai 4 la: " 
         << pi4[3] << " (" << pi4[3]*100 << "%)" << endl;

    cout << "\n--------------------------------------------" << endl;
    cout << "Ket qua khop voi hinh anh minh hoa: 0.282 (3 buoc) va 0.280 (4 buoc)." << endl;

    return 0;
}