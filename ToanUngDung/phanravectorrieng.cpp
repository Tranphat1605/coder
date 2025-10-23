#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void nhan(float a[10][10], float b[10][10], float c[10][10], int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            c[i][j] = 0;
            for(int k=1;k<=n;k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void xuly(float a[10][10], float maVT[10][10], int n){
    float M[10][10], M1[10][10], Temp[10][10];

    for(int k=n-1; k>=1; k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i != k){
                    M[i][j]  = (i==j)?1:0;
                    M1[i][j] = (i==j)?1:0;
                } else {
                    M1[i][j] = a[k+1][j];
                    if(j == k) M[i][j] = 1 / a[k+1][k];
                    else       M[i][j] = -a[k+1][j] / a[k+1][k];
                }
            }
        }
        nhan(M1, a, Temp, n);
        nhan(Temp, M, a, n);

        float TmpVT[10][10];
        nhan(maVT, M, TmpVT, n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                maVT[i][j] = TmpVT[i][j];
    }
}

// ================= Giải phương trình bậc 2,3 =================

vector<double> giaiBac2(double a, double b, double c) {
    vector<double> nghiem;
    double delta = b*b - 4*a*c;
    if (delta >= 0) {
        nghiem.push_back((-b + sqrt(delta)) / (2*a));
        nghiem.push_back((-b - sqrt(delta)) / (2*a));
    }
    return nghiem;
}

vector<double> giaiBac3(double a, double b, double c, double d) {
    vector<double> nghiem;
    b /= a; c /= a; d /= a;
    double p = c - b*b/3.0;
    double q = 2*b*b*b/27.0 - b*c/3.0 + d;
    double delta = q*q/4.0 + p*p*p/27.0;

    if (fabs(delta) < 1e-9) delta = 0;
    if (delta > 0) {
        double u = cbrt(-q/2.0 + sqrt(delta));
        double v = cbrt(-q/2.0 - sqrt(delta));
        nghiem.push_back(u+v - b/3.0);
    } else {
        double phi = acos(-q/(2*sqrt(-p*p*p/27.0)));
        for (int k=0; k<3; k++) {
            double xk = 2*sqrt(-p/3.0)*cos((phi+2*M_PI*k)/3.0) - b/3.0;
            nghiem.push_back(xk);
        }
    }
    return nghiem;
}

// ================= Tìm giá trị riêng từ Frobenius =================

vector<double> timGiaTriRieng(float a[10][10], int n) {
    vector<double> nghiem;
    if (n == 2) nghiem = giaiBac2(1, a[1][1], a[1][2]);
    if (n == 3) nghiem = giaiBac3(1, a[1][1], a[1][2], a[1][3]);
    // nếu cần thì bổ sung bậc 4 tương tự

    cout << "Gia tri rieng: ";
    for (double x : nghiem) cout << x << " ";
    cout << endl;
    return nghiem;
}

vector<double> timVectorRieng(float maVT[10][10], double lambda, int n) {
    vector<double> y(n+1);
    for(int i=0; i<n; i++)
        y[i+1] = pow(lambda, n-1-i);

    vector<double> x(n+1, 0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            x[i] += maVT[i][j] * y[j];
    return x;
}

// ================= MAIN =================
int main(){
    int n;
    cout << "Nhap cap ma tran n: ";
    cin >> n;

    float a[10][10];
    cout << "Nhap ma tran A ("<<n<<"x"<<n<<"):\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];

    // Khởi tạo ma trận maVT = đơn vị
    float maVT[10][10];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            maVT[i][j] = (i==j)?1:0;

    // Đưa A về Frobenius
    xuly(a, maVT, n);

    // Tìm trị riêng
    vector<double> nghiem = timGiaTriRieng(a, n);

    // Tìm và in vector riêng
    for(double lambda : nghiem) {
        vector<double> x = timVectorRieng(maVT, lambda, n);
        cout << "Vector rieng ung voi lambda = " << lambda << " : ";
        for(int i=1;i<=n;i++) {
            if (fabs(x[i]) < 1e-6) x[i] = 0;
            cout << x[i] << " ";
        }
        cout << endl;
    }
}



// Thuật toán Danilevskii(A, n):

// Bước 1: Khởi tạo ma trận maVT = I (ma trận đơn vị cấp n).

// Bước 2: Đưa ma trận A về dạng Frobenius:
//     For k = n-1 downto 1:
//         - Tạo ma trận M = I
//         - Tạo ma trận M1 = I
//         - Với hàng k của M và M1:
//             M1[k][j] = A[k+1][j]
//             Nếu j = k:   M[k][j] = 1 / A[k+1][k]
//             Nếu j ≠ k:   M[k][j] = -A[k+1][j] / A[k+1][k]

//         - Cập nhật A = M1 * A * M
//         - Cập nhật maVT = maVT * M

// Bước 3: Tìm trị riêng (λ):
//     - Đa thức đặc trưng nằm ở hàng đầu tiên của A (dạng Frobenius).
//     - Nếu n = 2 → giải phương trình bậc 2.
//     - Nếu n = 3 → giải phương trình bậc 3 (Cardano).
//     - Nếu n = 4 → giải phương trình bậc 4 (Ferrari).
//     - Các nghiệm thu được chính là trị riêng.

// Bước 4: Tìm vectơ riêng ứng với λ:
//     - Tạo vector y = (λ^(n-1), λ^(n-2), …, λ, 1).
//     - Tính x = maVT * y.
//     - Vector x chính là vectơ riêng ứng với λ.

// Bước 5: Xuất kết quả:
//     - Các giá trị riêng λ.
//     - Các vectơ riêng tương ứng.
