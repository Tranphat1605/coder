#include <iostream>
#include <vector>
#include <iomanip> // Để định dạng in số thập phân

using namespace std;

// Hàm in ma trận để dễ theo dõi từng bước
void printMatrix(const vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == n) cout << "| "; // Vạch ngăn cách cột hệ số tự do
            cout << setw(10) << setprecision(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------------" << endl;
}

void solveGaussJordan(vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        // 1. Tìm và chọn phần tử trụ (Pivot) - Đổi hàng nếu cần
        int pivotRow = i;
        while (pivotRow < n && matrix[pivotRow][i] == 0) pivotRow++;
        
        if (pivotRow == n) {
            continue; // Cột này toàn số 0, bỏ qua (Hệ có thể vô số nghiệm hoặc vô nghiệm)
        }
        swap(matrix[i], matrix[pivotRow]);

        // 2. Đưa phần tử trụ về bằng 1 (Chuẩn hóa hàng i)
        double divisor = matrix[i][i];
        for (int j = i; j <= n; j++) {
            matrix[i][j] /= divisor;
        }

        // 3. Khử các phần tử khác ở cột i về bằng 0 (cả phía trên và phía dưới hàng i)
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = i; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
        
        cout << "Sau khi khu cot " << i + 1 << ":" << endl;
        printMatrix(matrix, n);
    }
}

int main() {
    int n;
    cout << "Nhap so an cua he phuong trinh: ";
    cin >> n;

    // Ma trận bổ sung [A|B] kích thước n x (n+1)
    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Nhap ma tran bo sung (cac he so va hang so tu do):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMa tran ban dau:" << endl;
    printMatrix(matrix, n);

    solveGaussJordan(matrix, n);

    // Kiểm tra và in nghiệm
    cout << "KET QUA NGHIEM CUA HE PHUONG TRINH:" << endl;
    for (int i = 0; i < n; i++) {
        // Kiểm tra trường hợp vô nghiệm (Hàng toàn 0 nhưng vế phải khác 0)
        bool allZeros = true;
        for(int j = 0; j < n; j++) if(abs(matrix[i][j]) > 1e-9) allZeros = false;
        
        if(allZeros && abs(matrix[i][n]) > 1e-9) {
            cout << "He phuong trinh VO NGHIEM!" << endl;
            return 0;
        }
        
        cout << "An x" << i + 1 << " = " << matrix[i][n] << endl;
    }

    return 0;
}




// #include <iostream>
// #include <vector>
// #include <iomanip>
// #include <cmath> // Để dùng hàm abs()

// using namespace std;

// void printMatrix(const vector<vector<double>>& matrix, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= n; j++) {
//             if (j == n) cout << "| ";
//             cout << setw(10) << setprecision(4) << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "----------------------------------------------------" << endl;
// }

// void solveGaussJordan(vector<vector<double>>& matrix, int n) {
//     for (int i = 0; i < n; i++) {
//         int pivotRow = i;
//         while (pivotRow < n && abs(matrix[pivotRow][i]) < 1e-9) pivotRow++;
        
//         if (pivotRow == n) continue;
//         swap(matrix[i], matrix[pivotRow]);

//         double divisor = matrix[i][i];
//         for (int j = i; j <= n; j++) {
//             matrix[i][j] /= divisor;
//         }

//         for (int k = 0; k < n; k++) {
//             if (k != i) {
//                 double factor = matrix[k][i];
//                 for (int j = i; j <= n; j++) {
//                     matrix[k][j] -= factor * matrix[i][j];
//                 }
//             }
//         }
//     }
// }

// int main() {
//     // --- PHẦN SỬA ĐỔI Ở ĐÂY ---
    
//     // Ví dụ hệ phương trình:
//     // 1x + 2y + 1z = 8
//     // 1x + 3y + 0z = 7
//     // 1x + 0y + 2z = 9
    
//     vector<vector<double>> matrix = {
//         {1, 2, 1, 8},
//         {1, 3, 0, 7},
//         {1, 0, 2, 9}
//     };

//     int n = matrix.size(); // Tự động lấy số hàng (số ẩn)

//     // ---------------------------

//     cout << "Ma tran ban dau da tu dong nhap:" << endl;
//     printMatrix(matrix, n);

//     solveGaussJordan(matrix, n);

//     cout << "KET QUA NGHIEM CUA HE PHUONG TRINH:" << endl;
//     for (int i = 0; i < n; i++) {
//         bool allZeros = true;
//         for(int j = 0; j < n; j++) if(abs(matrix[i][j]) > 1e-9) allZeros = false;
        
//         if(allZeros && abs(matrix[i][n]) > 1e-9) {
//             cout << "He phuong trinh VO NGHIEM!" << endl;
//             return 0;
//         }
//         cout << "An x" << i + 1 << " = " << matrix[i][n] << endl;
//     }

//     system("pause"); // Giữ màn hình lại để xem
//     return 0;
// }