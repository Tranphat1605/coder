#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

double lamtron(double x) {
    if (fabs(x) < 1e-9) return 0;
    return round(x*1000)/1000.0;
}

// ================= Nhan ma tran =================
void nhan(double a[10][10], double b[10][10], double c[10][10], int n){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            c[i][j]=0;
            for(int k=1;k<=n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
}

// ================= Danilevskii =================
void danilevskii(double a[10][10], double ma_vt[10][10], int n){
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

        double tmp_vt[10][10];
        nhan(ma_vt,M,tmp_vt,n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ma_vt[i][j]=tmp_vt[i][j];
    }
}

// ================= Giai bac 2, 3 =================
int giai_bac2(double a, double b, double c, double nghiem[3]){
    double d=b*b-4*a*c;
    int dem=0;
    if(d>=0){
        nghiem[++dem]=(-b+sqrt(d))/(2*a);
        nghiem[++dem]=(-b-sqrt(d))/(2*a);
    }
    return dem;
}

int giai_bac3(double a, double b, double c, double d, double nghiem[4]){
    b/=a; c/=a; d/=a;
    double p=c-b*b/3.0;
    double q=2*b*b*b/27.0 - b*c/3.0 + d;
    double delta=q*q/4.0 + p*p*p/27.0;
    int dem=0;
    if(fabs(delta)<1e-9) delta=0;
    if(delta>0){
        double u=cbrt(-q/2.0+sqrt(delta));
        double v=cbrt(-q/2.0-sqrt(delta));
        nghiem[++dem]=u+v-b/3.0;
    } else {
        double phi=acos(-q/(2*sqrt(-p*p*p/27.0)));
        for(int k=0;k<3;k++){
            double xk=2*sqrt(-p/3.0)*cos((phi+2*PI*k)/3.0)-b/3.0;
            nghiem[++dem]=xk;
        }
    }
    return dem;
}

int tim_gtri_rieng(double a[10][10], int n, double eig[10]){
    if(n==2) return giai_bac2(1,-a[1][1],-a[1][2],eig);
    if(n==3) return giai_bac3(1,-a[1][1],-a[1][2],-a[1][3],eig);
    return 0;
}

// ================= Tinh vector rieng =================
void tim_vector_rieng(double ma_vt[10][10], double lambda, int n, double out[10]){
    double y[10];
    for(int i=1;i<=n;i++) y[i]=pow(lambda,n-i);
    for(int i=1;i<=n;i++){
        out[i]=0;
        for(int j=1;j<=n;j++)
            out[i]+=ma_vt[i][j]*y[j];
    }
}

// ================= Gram–Schmidt =================
void gram_schmidt(double U[10][10], int m){
    for(int j=1;j<=m;j++){
        for(int k=1;k<j;k++){
            double dot=0;
            for(int i=1;i<=m;i++) dot+=U[i][j]*U[i][k];
            for(int i=1;i<=m;i++) U[i][j]-=dot*U[i][k];
        }
        double chuan=0;
        for(int i=1;i<=m;i++) chuan+=U[i][j]*U[i][j];
        chuan=sqrt(chuan);
        if(chuan>1e-12){
            for(int i=1;i<=m;i++) U[i][j]/=chuan;
        }
    }
}

// ================= SVD =================
int main(){
    int m, n;
    cout << "Nhap so hang m: "; cin >> m;
    cout << "Nhap so cot n: "; cin >> n;

    double A[10][10];
    cout << "Nhap ma tran A ("<<m<<"x"<<n<<"):" << endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }

    // --- B1: Tinh A^T*A (n×n) ---
    double ATA[10][10];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            ATA[i][j]=0;
            for(int k=1;k<=m;k++)
                ATA[i][j]+=A[k][i]*A[k][j];
        }

    // --- B2: Danilevskii ---
    double ma_vt[10][10]={0};
    for(int i=1;i<=n;i++) ma_vt[i][i]=1;
    double B[10][10];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) B[i][j]=ATA[i][j];

    danilevskii(B,ma_vt,n);
    double eig[10];
    int so_eig=tim_gtri_rieng(B,n,eig);

    // --- B3: Sigma ---
    double sigma[10];
    for(int i=1;i<=so_eig;i++){
        double lam=eig[i];
        if(lam<0) lam=0;
        sigma[i]=sqrt(lam);
    }

    // --- B4: V ---
    double V[10][10]={0};
    for(int idx=1; idx<=n; idx++){
        double v[10];
        tim_vector_rieng(ma_vt, eig[idx], n, v);
        double chuan=0;
        for(int i=1;i<=n;i++) chuan+=v[i]*v[i];
        chuan=sqrt(chuan);
        if(chuan>1e-12)
            for(int i=1;i<=n;i++) v[i]/=chuan;
        for(int i=1;i<=n;i++){
            if(fabs(v[i])<1e-9) v[i]=0;
            V[i][idx]=v[i];
        }
    }

    // --- B5: U ---
    double U[10][10]={0};
    for(int k=1;k<=n;k++){
        if(fabs(sigma[k])<1e-9) continue;
        for(int i=1;i<=m;i++){
            double tong=0;
            for(int j=1;j<=n;j++) tong+=A[i][j]*V[j][k];
            U[i][k]=tong/sigma[k];
        }
    }
    if(m>n){
        for(int j=n+1;j<=m;j++) U[j][j]=1;
    }
    gram_schmidt(U,m);

    // --- B6: Sigma (m×n) ---
    double S[10][10]={0};
    for(int i=1;i<=min(m,n);i++) S[i][i]=sigma[i];

    // In ket qua
    cout << "\nMa tran U ("<<m<<"x"<<m<<"):\n";
    for(int i=1;i<=m;i++){for(int j=1;j<=m;j++) cout<<lamtron(U[i][j])<<" "; cout<<"\n";}

    cout << "\nMa tran Sigma ("<<m<<"x"<<n<<"):\n";
    for(int i=1;i<=m;i++){for(int j=1;j<=n;j++) cout<<lamtron(S[i][j])<<" "; cout<<"\n";}

    cout << "\nMa tran V ("<<n<<"x"<<n<<"):\n";
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<lamtron(V[i][j])<<" "; cout<<"\n";}
}



// Thuật toán SVD(A, m, n):

// Nhập ma trận A kích thước (m×n).

// Bước 1: Tính A^T * A
//     Tạo ma trận ATA (n×n).
//     Với i = 1 → n:
//         Với j = 1 → n:
//             ATA[i][j] = 0
//             Với k = 1 → m:
//                 ATA[i][j] += A[k][i] * A[k][j]

// Bước 2: Tìm trị riêng và vectơ riêng của ATA (dùng Danilevskii)
//     - Khởi tạo maVT = ma trận đơn vị (n×n).
//     - Đưa ATA về dạng Frobenius bằng phép biến đổi Danilevskii:
//         Lặp k từ n-1 về 1:
//             Xây dựng ma trận M, M1
//             Cập nhật ATA = M1 * ATA * M
//             Cập nhật maVT = maVT * M
//     - Giải đa thức đặc trưng của ATA:
//         Nếu n=2: giải bậc 2.
//         Nếu n=3: giải bậc 3.
//         Thu được các trị riêng λ1, λ2, ...

// Bước 3: Tính các giá trị kỳ dị (singular values)
//     Với mỗi trị riêng λi:
//         Nếu λi < 0 thì đặt λi = 0
//         σi = sqrt(λi)
//     Đặt các σi lên đường chéo của ma trận Sigma (kích thước m×n).

// Bước 4: Tìm ma trận V
//     Với mỗi trị riêng λi:
//         Tính vectơ riêng vi = maVT * y(λi)
//         Chuẩn hóa vi (chia cho chuẩn Euclid)
//         Đặt vi làm cột của ma trận V (n×n).

// Bước 5: Tính ma trận U
//     Với mỗi σi ≠ 0:
//         ui = (A * vi) / σi
//         Đặt ui làm cột của ma trận U.
//     Nếu số cột U < m:
//         Bổ sung thêm vectơ đơn vị rồi dùng Gram–Schmidt để trực chuẩn.
//     Kết quả: U là ma trận trực giao (m×m).

// Bước 6: Xuất kết quả
//     In ma trận U (m×m).
//     In ma trận Sigma (m×n).
//     In ma trận V (n×n).
