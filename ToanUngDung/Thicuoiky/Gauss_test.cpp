#include <iostream>
#include <Eigen/Dense> // Thư viện chính cho ma trận
#include <cstdlib>     // Để dùng system("pause")

using namespace std;
using namespace Eigen;

int main() {
    // 1. Khai báo ma trận hệ số A và vectơ kết quả b
    // Hệ phương trình ví dụ:
    //  2x +  y -  z = 8
    // -3x -  y + 2z = -11
    // -2x +  y + 2z = -3

    Matrix3d A;
    Vector3d b;

    // Nhập dữ liệu cho ma trận A (hàng lượt từ trái qua phải)
    A << 2,  1, -1,
        -3, -1,  2,
        -2,  1,  2;

    // Nhập dữ liệu cho vectơ b
    b << 8, -11, -3;

    // 2. Giải hệ phương trình Ax = b bằng phương pháp ColPivHouseholderQr
    // Đây là phương pháp ổn định và chính xác tương đương Gauss-Jordan nâng cao
    Vector3d x = A.colPivHouseholderQr().solve(b);

    // 3. In kết quả
    cout << "Ma tran he so A:" << endl << A << endl << endl;
    cout << "Vecto ket qua b:" << endl << b << endl << endl;
    cout << "-----------------------------------" << endl;
    cout << "Nghiem cua he phuong trinh la:" << endl;
    cout << "x = " << x(0) << endl;
    cout << "y = " << x(1) << endl;
    cout << "z = " << x(2) << endl;
    cout << "-----------------------------------" << endl;

    // Giữ màn hình để xem kết quả
    system("pause");
    return 0;
}