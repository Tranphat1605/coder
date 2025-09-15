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
void xuly(float a[10][10],float maVT[10][10], int n){
    float M[10][10], M1[10][10], Temp[10][10];

    for(int k=n-1; k>=1; k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i != k){
                    if(i == j){
                        M[i][j] = 1;
                        M1[i][j] = 1;
                    } else {
                        M[i][j] = 0;
                        M1[i][j] = 0;
                    }
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

    // Xuất ma trận kết quả
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

// Giải bậc 2: ax^2 + bx + c = 0
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
        double x1 = u+v - b/3.0;
        nghiem.push_back(x1);
    } else {
        double r = sqrt(-p*p*p/27.0);
        double phi = acos(-q/(2*sqrt(-p*p*p/27.0)));
        for (int k=0; k<3; k++) {
            double xk = 2*sqrt(-p/3.0)*cos((phi+2*3.1416*k)/3.0) - b/3.0;
            nghiem.push_back(xk);
        }
    }
    return nghiem;
}

// Giải bậc 4: ax^4 + bx^3 + cx^2 + dx + e = 0 (Ferrari)
vector<double> giaiBac4(double a, double b, double c, double d, double e) {
    vector<double> nghiem;
    b/=a; c/=a; d/=a; e/=a;

    double p = c - 3*b*b/8;
    double q = b*b*b/8 - b*c/2 + d;
    double r = -3*b*b*b*b/256 + b*b*c/16 - b*d/4 + e;

    if (fabs(q) < 1e-12) {
        // trường hợp đặc biệt (bi-quadratic)
        vector<double> y = giaiBac2(1, p, r);
        for (double yi: y) {
            if (yi >= 0) {
                nghiem.push_back(sqrt(yi) - b/4);
                nghiem.push_back(-sqrt(yi) - b/4);
            }
        }
    } else {
        // Ferrari tổng quát
        vector<double> z = giaiBac3(1, -p/2, -r, (4*p*r - q*q)/8);
        double y = z[0];
        double R = sqrt(0.25*b*b - c + y);
        double D, E;
        if (fabs(R) < 1e-12) {
            D = sqrt(3.0/4*b*b - 2*c + 2*sqrt(y*y - 4*r));
            E = sqrt(3.0/4*b*b - 2*c - 2*sqrt(y*y - 4*r));
        } else {
            D = sqrt(3.0/4*b*b - R*R - 2*c + (4*q)/R);
            E = sqrt(3.0/4*b*b - R*R - 2*c - (4*q)/R);
        }
        nghiem.push_back(-b/4 + 0.5*( R+D ));
        nghiem.push_back(-b/4 + 0.5*( R-D ));
        nghiem.push_back(-b/4 + 0.5*(-R+E ));
        nghiem.push_back(-b/4 + 0.5*(-R-E ));
    }
    return nghiem;
}

// Lấy nghiệm từ hàng đầu tiên ma trận Frobenius
vector<double> timGiaTriRieng(float a[10][10], int n) {
    vector<double> nghiem;
    if (n == 2) nghiem = giaiBac2(1, -a[1][1], -a[1][2]);
    if (n == 3) nghiem = giaiBac3(1, -a[1][1], -a[1][2], -a[1][3]);
    if (n == 4) nghiem = giaiBac4(1, -a[1][1], -a[1][2], -a[1][3], -a[1][4]);

    cout << "Gia tri rieng: ";
    for (double x : nghiem) cout << x << " ";
    cout << endl;
    return nghiem;
}

vector<double> timVectorRieng(float maVT[10][10], double lambda, int n) {
    vector<double> y(n+1);
    for(int i=0; i<n; i++){
        y[i+1] = pow(lambda, n-1-i);
    }

    vector<double> x(n+1, 0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            x[i] += maVT[i][j] * y[j];
        }
    }
    return x;
}


int main(){
    int n = 3;
    float maVT[10][10];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) maVT[i][j] = 0;
            else
            maVT[i][j] = (i==j)?1:0;
        }
    }
    float a[10][10] = {
        {0,0,0,0},       
        {0,2,1,0},       
        {0,1,3,1},       
        {0,0,1,2},       
    };
    xuly(a,maVT, n);
vector<double> nghiem = timGiaTriRieng(a, n);
for(double lambda : nghiem) {
    vector<double> x = timVectorRieng(maVT, lambda, n);
    cout << "Vector rieng ung voi lambda = " << lambda << " : ";
    for(int i=1;i<=n;i++) {
        if (fabs(x[i]) < 1e-9) x[i] = 0; // làm tròn
        cout << x[i] << " ";
    }
    cout << endl;
}


}
