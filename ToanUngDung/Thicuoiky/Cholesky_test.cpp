#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    // 1. Khai báo ma trận đối xứng và xác định dương
    Matrix3d A;
    A << 4,  12, -16,
         12, 37, -43,
        -16, -43, 98;

    cout << "Ma tran A ban dau:\n" << A << "\n\n";

    // 2. Thuc hien phan ra Cholesky (LLT)
    LLT<Matrix3d> lltOfA(A);

    // 3. Kiem tra xem ma tran co thoa man dieu kien xac dinh duong khong
    if(lltOfA.info() == Success) {
        // Lay ma tran tam giac duoi L
        Matrix3d L = lltOfA.matrixL();
        
        cout << "Ma tran tam giac duoi L:\n" << L << "\n\n";
        cout << "Ma tran L chuyen vi (L^T):\n" << L.transpose() << "\n\n";

        // 4. Kiem tra lai tich L * L^T
        cout << "Kiem tra lai tich L * L^T:\n" << L * L.transpose() << endl;
    } else {
        cout << "Loi: Ma tran khong phai la ma tran xac dinh duong!" << endl;
    }

    system("pause");
    return 0;
}