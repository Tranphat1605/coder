#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589793;
const double EPS = 1e-10;

double lamTron(double x, int doChinhXac = 3) {
    return round(x * pow(10, doChinhXac)) / pow(10, doChinhXac);
}

void nhanMaTran(double a[10][10], double b[10][10], double c[10][10], int soHangA, int soCotA, int soCotB) {
    for (int i = 0; i < soHangA; i++)
        for (int j = 0; j < soCotB; j++) {
            c[i][j] = 0;
            for (int k = 0; k < soCotA; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void truMaTran(double a[10][10], double b[10][10], double c[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void maTranDonVi(double a[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = (i == j) ? 1.0 : 0.0;
}

int giaiBacHai(double a, double b, double c, double nghiem[2]) {
    double delta = b * b - 4 * a * c;
    int dem = 0;
    if (delta >= 0) {
        nghiem[dem++] = (-b + sqrt(delta)) / (2 * a);
        nghiem[dem++] = (-b - sqrt(delta)) / (2 * a);
    }
    return dem;
}

void nhanMaTranVoiVector(double a[10][10], double b[10], double c[10], int soHangA, int soCotA) {
    for (int i = 0; i < soHangA; i++) {
        c[i] = 0;
        for (int j = 0; j < soCotA; j++) {
            c[i] += a[i][j] * b[j];
        }
    }
}

void phuongPhapLuyThua(double a[10][10], int n, double& triRieng, double vectorRieng[10]) {
    double x[10] = {0};
    double xMoi[10] = {0};
    x[0] = 1.0;
    double lambdaCu = 0, lambdaMoi = 0;
    int lapToiDa = 100;

    for (int lap = 0; lap < lapToiDa; lap++) {
        nhanMaTranVoiVector(a, x, xMoi, n, n);
        double chuan = 0;
        for (int i = 0; i < n; i++) chuan += xMoi[i] * xMoi[i];
        chuan = sqrt(chuan);
        lambdaMoi = xMoi[0] / x[0];
        for (int i = 0; i < n; i++) x[i] = xMoi[i] / chuan;
        if (fabs(lambdaMoi - lambdaCu) < EPS) break;
        lambdaCu = lambdaMoi;
    }
    triRieng = lambdaMoi;
    for (int i = 0; i < n; i++) vectorRieng[i] = x[i];
}

void trucChuanGramSchmidt(double U[10][10], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < j; k++) {
            double tichVoHuong = 0;
            for (int i = 0; i < m; i++) tichVoHuong += U[i][j] * U[i][k];
            for (int i = 0; i < m; i++) U[i][j] -= tichVoHuong * U[i][k];
        }
        double chuan = 0;
        for (int i = 0; i < m; i++) chuan += U[i][j] * U[i][j];
        chuan = sqrt(chuan);
        if (chuan > EPS) {
            for (int i = 0; i < m; i++) U[i][j] /= chuan;
        }
    }
}

int main() {
    int m, n;
    cout << "Nhap so hang m: "; cin >> m;
    cout << "Nhap so cot n: "; cin >> n;
    if (m > 10 || n > 10 || m <= 0 || n <= 0) {
        cout << "Kich thuoc ma tran khong hop le!" << endl;
        return 1;
    }

    double A[10][10];
    cout << "Nhap ma tran A (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    double AT_A[10][10] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                AT_A[i][j] += A[k][i] * A[k][j];

    double V[10][10] = {0}, sigma[10] = {0};
    double triRieng, vectorRieng[10];

    for (int i = 0; i < n; i++) {
        double AT_A_Temp[10][10];
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                AT_A_Temp[j][k] = AT_A[j][k];
        phuongPhapLuyThua(AT_A_Temp, n, triRieng, vectorRieng);
        sigma[i] = (triRieng > 0) ? sqrt(triRieng) : 0;
        for (int j = 0; j < n; j++) V[j][i] = vectorRieng[j];
    }

    double U[10][10] = {0};
    for (int k = 0; k < n; k++) {
        if (fabs(sigma[k]) < EPS) continue;
        for (int i = 0; i < m; i++) {
            double tong = 0;
            for (int j = 0; j < n; j++) tong += A[i][j] * V[j][k];
            U[i][k] = tong / sigma[k];
        }
    }
    if (m > n) {
        for (int j = n; j < m; j++) U[j][j] = 1.0;
    }
    trucChuanGramSchmidt(U, m, n);

    double S[10][10] = {0};
    for (int i = 0; i < min(m, n); i++) S[i][i] = sigma[i];

    cout << "\nMa tran U (" << m << "x" << m << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            cout << fixed << setprecision(3) << lamTron(U[i][j]) << " ";
        cout << endl;
    }

    cout << "\nMa tran Sigma (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(3) << lamTron(S[i][j]) << " ";
        cout << endl;
    }

    cout << "\nMa tran V (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(3) << lamTron(V[i][j]) << " ";
        cout << endl;
    }

    return 0;
}
