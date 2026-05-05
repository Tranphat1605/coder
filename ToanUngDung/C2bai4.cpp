#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// ------------------ Tiện ích ma trận ------------------
vector<vector<double>> inverse(vector<vector<double>> A, int n){
    vector<vector<double>> I(n+1, vector<double>(n+1, 0));
    for(int i=1;i<=n;i++) I[i][i]=1;

    for(int i=1;i<=n;i++){
        if (fabs(A[i][i]) < 1e-12){
            for(int k=i+1;k<=n;k++){
                if (fabs(A[k][i]) > 1e-12){
                    swap(A[i], A[k]);
                    swap(I[i], I[k]);
                    break;
                }
            }
        }
        double pivot = A[i][i];
        for(int j=1;j<=n;j++){
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }
        for(int k=1;k<=n;k++){
            if(k==i) continue;
            double factor = A[k][i];
            for(int j=1;j<=n;j++){
                A[k][j] -= factor*A[i][j];
                I[k][j] -= factor*I[i][j];
            }
        }
    }
    return I;
}

// ------------------ Danilevskii ------------------
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
                    else M[i][j] = -a[k+1][j] / a[k+1][k];
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

// Giải bậc 2,3
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

vector<double> timGiaTriRieng(float a[10][10], int n) {
    vector<double> nghiem;
    if (n == 2) nghiem = giaiBac2(1, -a[1][1], -a[1][2]);
    if (n == 3) nghiem = giaiBac3(1, -a[1][1], -a[1][2], -a[1][3]);

    cout << "Gia tri rieng: ";
    for (double x : nghiem) cout << x << " ";
    cout << endl;
    return nghiem;
}

vector<double> timVectorRieng(float maVT[10][10], double lambda, int n) {
    vector<double> y(n+1);
    for(int i=1; i<=n; i++) y[i] = pow(lambda, n-i);

    vector<double> x(n+1, 0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            x[i] += maVT[i][j] * y[j];
    return x;
}

// ------------------ MAIN ------------------
int main(){
    int n = 3;
    float maVT[10][10];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            maVT[i][j] = (i==j && i!=0)?1:0;

    float a[10][10] = {
        {0,0,0,0},
        {0,2,4,0},
        {0,1,3,1},
        {0,0,1,3},
    };

    // B1: Đưa A về Frobenius
    xuly(a, maVT, n);

    // B2: Tìm trị riêng
    vector<double> nghiem = timGiaTriRieng(a,n);

    // B3: Tìm vector riêng
    vector<vector<double>> V(n+1, vector<double>(n+1));
    for(int idx=0; idx<n; idx++) {
        double lambda = nghiem[idx];
        vector<double> x = timVectorRieng(maVT, lambda, n);
        for(int i=1;i<=n;i++) if (fabs(x[i]) < 1e-9) x[i]=0;
        for(int i=1;i<=n;i++) V[i][idx+1] = x[i];
    }

    // Tạo Λ
    vector<vector<double>> Lambda(n+1, vector<double>(n+1,0));
    for(int i=1;i<=n;i++) Lambda[i][i] = nghiem[i-1];

    // Tính V^-1
    vector<vector<double>> Vsub(n+1, vector<double>(n+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            Vsub[i][j] = V[i][j];
    vector<vector<double>> Vinv = inverse(Vsub, n);

    // In kết quả
    cout << "\nMa tran V:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << V[i][j] << " ";
        cout << endl;
    }

    cout << "\nMa tran Lambda:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << Lambda[i][j] << " ";
        cout << endl;
    }

cout << "\nMa tran V^-1:\n";
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) {
        double val = Vinv[i][j];
        if (fabs(val) < 1e-9) val = 0;   // lọc sai số rất nhỏ về 0
        cout << val << " ";
    }
    cout << endl;
}

}
