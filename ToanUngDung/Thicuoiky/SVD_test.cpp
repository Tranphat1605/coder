#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {


    // 1. Nhập kích thước ma trận từ bàn phím hoặc định nghĩa sẵn
    // int m, n;
    // cout << "Nhap so hang m: "; cin >> m;
    // cout << "Nhap so cot n: "; cin >> n;

    // MatrixXd A(m, n);
    // cout << "Nhap cac phan tu cua ma tran A (" << m << "x" << n << "):" << endl;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> A(i, j);
    //     }
    // }

    // cout << "\nMa tran A vua nhap:\n" << A << endl;


    int m = 3, n = 3; 
    MatrixXd A(m, n);

    // Gán giá trị theo thứ tự hàng ngang, từ trái sang phải
    A << 1,3,6,1,3,8,2,6,9;


    // 2. Thuc hien phan ra SVD
    // ComputeFullU | ComputeFullV dam bao lay ma tran U (mxm) va V (nxn) day du
    JacobiSVD<MatrixXd> svd(A, ComputeFullU | ComputeFullV);

    // 3. Lay ma tran U (Kich thuoc m x m)
    MatrixXd U = svd.matrixU();

    // 4. Tao ma tran Sigma (Kich thuoc m x n)
    // Mac dinh ban dau tat ca bang 0
    MatrixXd Sigma = MatrixXd::Zero(m, n);
    
    // Lay cac gia tri suy bien (singular values)
    VectorXd s = svd.singularValues();
    
    // Dien cac gia tri suy bien vao duong cheo chinh cua Sigma
    // So luong gia tri suy bien luon bang min(m, n)
    for (int i = 0; i < s.size(); i++) {
        Sigma(i, i) = s(i);
    }

    // 5. Lay ma tran Vt (Kich thuoc n x n)
    MatrixXd Vt = svd.matrixV().transpose();

    // --- HIEN THI KET QUA ---
    cout << "\n=== KET QUA PHAN RA SVD ===" << endl;
    cout << "1. Ma tran U (" << m << "x" << m << "):\n" << U << endl;
    cout << "\n2. Ma tran Sigma (" << m << "x" << n << "):\n" << Sigma << endl;
    cout << "\n3. Ma tran Vt (" << n << "x" << n << "):\n" << Vt << endl;

    // 6. Kiem tra lai (U * Sigma * Vt)
    cout << "\n----------------------------------------" << endl;
    MatrixXd A_reconstructed = U * Sigma * Vt;
    cout << "Kiem tra lai tich (U * Sigma * Vt):" << endl;
    cout << A_reconstructed << endl;

    return 0;
}