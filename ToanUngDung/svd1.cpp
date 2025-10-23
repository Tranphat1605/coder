#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

double clean(double x) {
    if (fabs(x) < 1e-9) return 0;
    return round(x*1000)/1000.0; // làm tròn 3 chữ số thập phân
}

int main(){
    // Khai báo ma trận A
    MatrixXd A(3,4);
    A << 1,1,2,3,
         2,0,1,-4,
         3,1,3,-1;

    // Phân rã SVD
    JacobiSVD<MatrixXd> svd(A, ComputeFullU | ComputeFullV);
    MatrixXd U = svd.matrixU();
    MatrixXd V = svd.matrixV();
    VectorXd S = svd.singularValues();

    // Tạo ma trận Sigma (3x4)
    MatrixXd Sigma = MatrixXd::Zero(3,4);
    for(int i=0;i<S.size();i++) Sigma(i,i) = S(i);

    // In kết quả
    cout << "Ma tran U (3x3):\n";
    for(int i=0;i<U.rows();i++){
        for(int j=0;j<U.cols();j++) cout << clean(U(i,j)) << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "Ma tran Sigma (3x4):\n";
    for(int i=0;i<Sigma.rows();i++){
        for(int j=0;j<Sigma.cols();j++) cout << clean(Sigma(i,j)) << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "Ma tran V (4x4):\n";
    for(int i=0;i<V.rows();i++){
        for(int j=0;j<V.cols();j++) cout << clean(V(i,j)) << " ";
        cout << "\n";
    }
}
