#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> Matrix;

// Hàm khởi tạo ma trận n x n toàn số 0
Matrix createMatrix(int n) {
    return vector<vector<double>>(n, vector<double>(n, 0.0));
}

// Hàm thực hiện phân rã Cholesky A = L * L^T
bool choleskyDecomposition(const Matrix& A, Matrix& L, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            
            if (j == i) { // Tính các phần tử trên đường chéo chính
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                
                double val = A[j][j] - sum;
                if (val < 0) return false; // Ma trận không xác định dương
                L[j][j] = sqrt(val);
            } else { // Tính các phần tử phía dưới đường chéo
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return true;
}

void printMatrix(const Matrix& M, int n, string name) {
    cout << "Ma tran " << name << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << setprecision(4) << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Ví dụ ma trận đối xứng và xác định dương
    // A = [4  12 -16]
    //     [12 37 -43]
    //     [-16 -43 98]
    Matrix A = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}
    };
    
    int n = A.size();
    Matrix L = createMatrix(n);

    if (choleskyDecomposition(A, L, n)) {
        printMatrix(A, n, "A");
        printMatrix(L, n, "L (Tam giac duoi)");
        
        // In ra L^T để em dễ hình dung
        Matrix Lt = createMatrix(n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) Lt[i][j] = L[j][i];
        printMatrix(Lt, n, "L^T (Chuyen vi)");
        
        cout << "Kiem tra: A = L * L^T" << endl;
    } else {
        cout << "Ma tran khong phai la ma tran xac dinh duong!" << endl;
    }

    system("pause");
    return 0;
}