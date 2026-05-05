#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef vector<vector<double>> Matrix;

// In ma trận
void printMatrix(const Matrix &A) {
    for (auto &row : A) {
        for (double val : row)
            cout << fixed << setprecision(4) << val << " ";
        cout << endl;
    }
}

// Transpose
Matrix transpose(const Matrix &A) {
    int m = A.size(), n = A[0].size();
    Matrix AT(n, vector<double>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            AT[j][i] = A[i][j];
            
    return AT;
}

// Nhân ma trận
Matrix multiply(const Matrix &A, const Matrix &B) {
    int m = A.size(), p = B.size(), n = B[0].size();
    Matrix C(m, vector<double>(n, 0));
    for (int i = 0; i < m; i++)
        for (int k = 0; k < p; k++)
            for (int j = 0; j < n; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Chuẩn hóa vector
void normalize(vector<double> &v) {
    double norm = 0;
    for(double x:v) norm+=x*x;
    norm = sqrt(norm);
    if(norm<1e-5) return;
    for(double &x:v) x/=norm;
}

// Jacobi Eigenvalue
void jacobiEigen(Matrix &A, vector<double> &eig, Matrix &V) {
    int n = A.size();
    V.assign(n, vector<double>(n,0));
    for(int i=0;i<n;i++) V[i][i]=1;

    const int MAX_ITER=100;
    const double EPS=1e-10;

    for(int iter=0;iter<MAX_ITER;iter++){
        int p=0,q=1;
        double maxVal=fabs(A[p][q]);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(fabs(A[i][j])>maxVal){p=i;q=j;maxVal=fabs(A[i][j]);}
        if(maxVal<EPS) break;
        double phi=0.5*atan2(2*A[p][q],A[q][q]-A[p][p]);
        double c=cos(phi), s=sin(phi);
        for(int i=0;i<n;i++){
            double aip=A[i][p], aiq=A[i][q];
            A[i][p]=c*aip - s*aiq;
            A[i][q]=s*aip + c*aiq;
        }
        for(int i=0;i<n;i++){
            double api=A[p][i], aqi=A[q][i];
            A[p][i]=c*api - s*aqi;
            A[q][i]=s*api + c*aqi;
        }
        for(int i=0;i<n;i++){
            double vip=V[i][p], viq=V[i][q];
            V[i][p]=c*vip - s*viq;
            V[i][q]=s*vip + c*viq;
        }
    }

    eig.resize(n);
    for(int i=0;i<n;i++) eig[i]=A[i][i];
}

// Full SVD
void SVD(const Matrix &A, Matrix &U, Matrix &Sigma, Matrix &V){
    int m=A.size(), n=A[0].size();
    Matrix AT=transpose(A);
    Matrix ATA = multiply(AT,A);

    vector<double> eig;
    Matrix Vtmp;
    jacobiEigen(ATA,eig,Vtmp);

    // Sắp xếp singular values giảm dần
    vector<pair<double,int>> sigma_idx;
    for(int i=0;i<n;i++) sigma_idx.push_back({(eig[i]>0)?sqrt(eig[i]):0,i});
    sort(sigma_idx.rbegin(), sigma_idx.rend());

    // Tạo V
    V = Matrix(n, vector<double>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            V[j][i] = Vtmp[j][sigma_idx[i].second];

    // Tạo U từ A*V/σ
    vector<vector<double>> Ucols;
    for(int i=0;i<n;i++){double s = sigma_idx[i].first;
        vector<double> col(m,0);
        if(s>1e-12){
            for(int r=0;r<m;r++)
                for(int c=0;c<n;c++)
                    col[r]+=A[r][c]*V[c][i];
            for(int r=0;r<m;r++) col[r]/=s;
        }
        Ucols.push_back(col);
    }

    // Nếu m>n, thêm cột chuẩn hóa trực giao
    for(int i=n;i<m;i++){
        vector<double> col(m,0);
        col[i]=1.0;
        // Orthogonalize với cột trước
        for(auto &prev: Ucols){
            double dot=0;
            for(int j=0;j<m;j++) dot+=prev[j]*col[j];
            for(int j=0;j<m;j++) col[j]-=dot*prev[j];
        }
        normalize(col);
        Ucols.push_back(col);
    }

    // Chuyển sang U m×m
    U = Matrix(m, vector<double>(m,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            U[i][j] = Ucols[j][i];

    // Sigma m×n
    Sigma = Matrix(m, vector<double>(n,0));
    for(int i=0;i<min(m,n);i++)
        Sigma[i][i] = sigma_idx[i].first;
}

int main(){
    int m,n;
    cout<<"Nhap so dong m: ";
    cin>>m;
    cout<<"Nhap so cot n: ";
    cin>>n;

    Matrix A(m, vector<double>(n));
    cout<<"Nhap cac phan tu cua ma tran A:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    cout<<"\nMa tran A:\n";
    printMatrix(A);

    Matrix U,Sigma,V;
    SVD(A,U,Sigma,V);

    cout<<"\nMa tran U:\n";
    printMatrix(U);

    cout<<"\nMa tran Sigma:\n";
    printMatrix(Sigma);

    cout<<"\nMa tran V^T:\n";
    printMatrix(transpose(V));

    return 0;
}