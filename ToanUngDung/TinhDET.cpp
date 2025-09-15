#include <iostream>
using namespace std;
void MTcon(int mat[10][10], int temp[10][10], int p, int q, int n) {
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

int DT(int mat[10][10], int n) {
    if (n == 1) return mat[0][0];

    int det = 0;
    int temp[10][10];  
    int sign = 1;

    for (int f = 0; f < n; f++) {
        MTcon(mat, temp, 0, f, n);
        det += sign * mat[0][f] * DT(temp, n - 1);
        sign = -sign; 
    }
    return det;
}

int main() {
    int n;
    cout << "Nhap cap ma tran vuong S: ";
    cin >> n;
    int S[10][10];
    cout << "Nhap cac phan tu ma tran S(kieu INT):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }

    cout << "Dinh thuc cua ma tran S = " << DT(S, n) << endl;
    return 0;
}
