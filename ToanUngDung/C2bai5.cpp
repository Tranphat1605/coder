#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;

// 1. Kiểm tra ma trận đối xứng
bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (fabs(A[i][j] - A[j][i]) > EPS) return false;
        }
    }
    return true;
}

// 2. Kiểm tra xác định dương bằng định thức con chính (Sylvester criterion)
bool isPositiveDefinite(const vector<vector<double>>& A) {
    int n = A.size();
    for (int k=1; k<=n; k++) {
        // tạo ma trận con k x k
        vector<vector<double>> M(k, vector<double>(k));
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                M[i][j] = A[i][j];

        // tính định thức bằng Gauss
        double det = 1;
        vector<vector<double>> B = M;
        for(int i=0;i<k;i++){
            int pivot = i;
            for(int r=i+1;r<k;r++)
                if(fabs(B[r][i]) > fabs(B[pivot][i])) pivot = r;
            if(fabs(B[pivot][i]) < EPS) return false;
            if(pivot != i) swap(B[pivot], B[i]), det*=-1;

            det *= B[i][i];
            for(int r=i+1;r<k;r++){
                double factor = B[r][i]/B[i][i];
                for(int c=i;c<k;c++)
                    B[r][c] -= factor*B[i][c];
            }
        }
        if(det <= 0) return false;
    }
    return true;
}

// 3. Phân rã Cholesky: A = L * L^T
bool choleskyDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L) {
    int n = A.size();
    L.assign(n, vector<double>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            double sum = 0;
            if (j == i) {
                for (int k=0; k<j; k++)
                    sum += L[j][k] * L[j][k];
                double val = A[j][j] - sum;
                if (val <= 0) return false;
                L[j][j] = sqrt(val);
            } else {
                for (int k=0; k<j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap bac ma tran: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Nhap ma tran A:\n";
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> A[i][j];

    // Kiểm tra đối xứng
    if (!isSymmetric(A)) {
        cout << "Ma tran khong doi xung => khong phan ra Cholesky\n";
        return 0;
    }

    // Kiểm tra xác định dương
    if (!isPositiveDefinite(A)) {
        cout << "Ma tran khong xac dinh duong => khong phan ra Cholesky\n";
        return 0;
    }

    // Phân rã Cholesky
    vector<vector<double>> L;
    if (!choleskyDecomposition(A, L)) {
        cout << "Phan ra Cholesky that bai!\n";
        return 0;
    }

    cout << "\nMa tran L (tam giac duoi):\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << setw(10) << fixed << setprecision(4) << L[i][j] << " ";
        }
        cout << endl;
    }

    // Kiểm tra lại A = L * L^T
    cout << "\nKiem tra A = L * L^T:\n";
    vector<vector<double>> A_check(n, vector<double>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                A_check[i][j] += L[i][k]*L[j][k];

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << setw(10) << fixed << setprecision(4) << A_check[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
