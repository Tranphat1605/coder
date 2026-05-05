#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double clean(double x) {
    if (fabs(x) < 1e-9) return 0;
    return round(x*1000)/1000.0;
}

// ================= Danilevskii =================
void nhan(double a[10][10], double b[10][10], double c[10][10], int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            c[i][j]=0;
            for(int k=1;k<=n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
}

void xuly(double a[10][10], double maVT[10][10], int n){
    double M[10][10], M1[10][10], Temp[10][10];
    for(int k=n-1;k>=1;k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k){
                    M[i][j]=(i==j)?1:0;
                    M1[i][j]=(i==j)?1:0;
                } else {
                    M1[i][j]=a[k+1][j];
                    if(j==k) M[i][j]=1/a[k+1][k];
                    else M[i][j]=-a[k+1][j]/a[k+1][k];
                }
            }
        }
        nhan(M1,a,Temp,n);
        nhan(Temp,M,a,n);

        double TmpVT[10][10];
        nhan(maVT,M,TmpVT,n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                maVT[i][j]=TmpVT[i][j];
    }
}

vector<double> giaiBac2(double a, double b, double c){
    vector<double> nghiem;
    double d=b*b-4*a*c;
    if(d>=0){
        nghiem.push_back((-b+sqrt(d))/(2*a));
        nghiem.push_back((-b-sqrt(d))/(2*a));
    }
    return nghiem;
}

vector<double> giaiBac3(double a, double b, double c, double d){
    vector<double> nghiem;
    b/=a; c/=a; d/=a;
    double p=c-b*b/3.0;
    double q=2*b*b*b/27.0 - b*c/3.0 + d;
    double delta=q*q/4.0 + p*p*p/27.0;
    if(fabs(delta)<1e-9) delta=0;
    if(delta>0){
        double u=cbrt(-q/2.0+sqrt(delta));
        double v=cbrt(-q/2.0-sqrt(delta));
        nghiem.push_back(u+v-b/3.0);
    } else {
        double phi=acos(-q/(2*sqrt(-p*p*p/27.0)));
        for(int k=0;k<3;k++){
            double xk=2*sqrt(-p/3.0)*cos((phi+2*M_PI*k)/3.0)-b/3.0;
            nghiem.push_back(xk);
        }
    }
    return nghiem;
}

vector<double> timGiaTriRieng(double a[10][10], int n){
    if(n==2) return giaiBac2(1,-a[1][1],-a[1][2]);
    if(n==3) return giaiBac3(1,-a[1][1],-a[1][2],-a[1][3]);
    return {};
}

vector<double> timVectorRieng(double maVT[10][10], double lambda, int n){
    vector<double> y(n+1);
    for(int i=1;i<=n;i++) y[i]=pow(lambda,n-i);
    vector<double> x(n+1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            x[i]+=maVT[i][j]*y[j];
    return x;
}

// ================= Orthonormal hóa (Gram–Schmidt) =================
void gramSchmidt(vector<vector<double>> &U, int m){
    for(int j=1;j<=m;j++){
        // Chuẩn trực giao
        for(int k=1;k<j;k++){
            double dot=0;
            for(int i=1;i<=m;i++) dot+=U[i][j]*U[i][k];
            for(int i=1;i<=m;i++) U[i][j]-=dot*U[i][k];
        }
        // Chuẩn hóa
        double norm=0;
        for(int i=1;i<=m;i++) norm+=U[i][j]*U[i][j];
        norm=sqrt(norm);
        if(norm>1e-12){
            for(int i=1;i<=m;i++) U[i][j]/=norm;
        }
    }
}

// ================= SVD =================
int main(){
    int m=3, n=2; // ví dụ: A (3x2)

    double A[10][10]={
        {0,0,0},
        {0,1,3},
        {0,0,1},
        {0,1,0}
    };

    // --- B1: Tính A^T*A (n×n) ---
    double ATA[10][10];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            ATA[i][j]=0;
            for(int k=1;k<=m;k++)
                ATA[i][j]+=A[k][i]*A[k][j];
        }

    // --- B2: Danilevskii trên ATA để tìm V ---
    double maVT[10][10]={0};
    for(int i=1;i<=n;i++) maVT[i][i]=1;
    double B[10][10];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) B[i][j]=ATA[i][j];

    xuly(B,maVT,n);
    vector<double> eig=timGiaTriRieng(B,n);

    // --- B3: Singular values ---
    vector<double> sigma;
    for(double lam:eig){
        if(lam<0) lam=0;
        sigma.push_back(sqrt(lam));
    }

    // --- B4: V ---
    vector<vector<double>> V(n+1, vector<double>(n+1));
for(int idx=0; idx<n; idx++){
    vector<double> v = timVectorRieng(maVT, eig[idx], n);

    // --- chuẩn hóa vector về độ dài 1 ---
    double norm = 0;
    for(int i=1;i<=n;i++) norm += v[i]*v[i];
    norm = sqrt(norm);
    if(norm > 1e-12){
        for(int i=1;i<=n;i++) v[i] /= norm;
    }

    // gán vào ma trận V
    for(int i=1;i<=n;i++){
        if(fabs(v[i]) < 1e-9) v[i]=0;
        V[i][idx+1] = v[i];
    }
}


    // --- B5: U = m×m ---
    vector<vector<double>> U(m+1, vector<double>(m+1,0));
    for(int k=1;k<=n;k++){
        if(fabs(sigma[k-1])<1e-9) continue;
        for(int i=1;i<=m;i++){
            double sum=0;
            for(int j=1;j<=n;j++) sum+=A[i][j]*V[j][k];
            U[i][k]=sum/sigma[k-1];
        }
    }
    // Bổ sung các cột còn lại bằng Gram–Schmidt
    for(int j=n+1;j<=m;j++) U[j][j]=1; 
    gramSchmidt(U,m);

    // --- B6: Sigma (m×n) ---
    vector<vector<double>> S(m+1, vector<double>(n+1,0));
    for(int i=1;i<=min(m,n);i++) S[i][i]=sigma[i-1];

    // In kết quả
    cout << "Ma tran U ("<<m<<"x"<<m<<"):\n";
    for(int i=1;i<=m;i++){for(int j=1;j<=m;j++) cout<<clean(U[i][j])<<" "; cout<<"\n";}

    cout << "\nMa tran Sigma ("<<m<<"x"<<n<<"):\n";
    for(int i=1;i<=m;i++){for(int j=1;j<=n;j++) cout<<clean(S[i][j])<<" "; cout<<"\n";}

    cout << "\nMa tran V ("<<n<<"x"<<n<<"):\n";
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<clean(V[i][j])<<" "; cout<<"\n";}
}


// Thuật toán SVD(A, m, n):

// Bước 1: Tính A^T * A
//     - Tạo ma trận ATA (n×n).
//     - ATA[i][j] = ∑ (A[k][i] * A[k][j]) với k = 1 → m.

// Bước 2: Tìm trị riêng và vectơ riêng của ATA
//     - Áp dụng phương pháp Danilevskii đưa ATA về dạng Frobenius.
//     - Tính đa thức đặc trưng.
//     - Giải đa thức để tìm các trị riêng λi.
//     - Tính vectơ riêng tương ứng → ma trận V.

// Bước 3: Tính các giá trị kỳ dị (singular values)
//     - Với mỗi λi ≥ 0:
//         σi = sqrt(λi).
//     - Lưu σi vào ma trận Σ theo đường chéo chính.

// Bước 4: Tính ma trận U
//     - Với mỗi σi ≠ 0:
//         ui = (1 / σi) * (A * vi).
//     - Các cột ui tạo thành một phần ma trận U.

// Bước 5: Bổ sung trực chuẩn cho U
//     - Nếu số cột của U chưa đủ m:
//         Thêm các vectơ trực chuẩn bằng phương pháp Gram–Schmidt.
//     - Kết quả: U trực giao (U^T U = I).

// Bước 6: Xuất kết quả
//     - Ma trận U (m×m).
//     - Ma trận Σ (m×n).
//     - Ma trận V (n×n).
