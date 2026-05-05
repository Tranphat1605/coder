#include <iostream>
#include <iomanip>
using namespace std;
void MTcon(float mat[10][10], float temp[10][10], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float DT(float mat[10][10], int n) {
    if (n == 1) return mat[0][0];

    float det = 0;
    float temp[10][10];  
    int sign = 1;

    for (int f = 0; f < n; f++) {
        MTcon(mat, temp, 0, f, n);
        det += sign * mat[0][f] * DT(temp, n - 1);
        sign = -sign; 
    }
    return det;
}
void MTDao(float mat[10][10], float temp[10][10], int n){
    float det=DT(mat,n);
    float mtcon[10][10];
    int sign;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            MTcon(mat,mtcon,row,col,n);
            sign=((row+col)%2==0)?1:-1;
           temp[col][row]=1/det * DT(mtcon,n-1)*sign;
        };
    }
}
int main() {
    int n;
    cout << "Nhap cap ma tran vuong S: ";
    cin >> n;
    float S[10][10],A[10][10];
    cout << "Nhap cac phan tu ma tran S:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    };
if(DT(S,n)==0) cout<<"Ma tran Det=0 khong co nghich dao!"; else {
    MTDao(S,A,n);
    cout<<"Ma tran nghich dao cua S: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout<<endl;
    }
}
    return 0;
}
