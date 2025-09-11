#include <bits/stdc++.h>
using namespace std;    

class Matrix {
    private:
        int n;
        int **A;
    public:
        Matrix (int n = 2);
        Matrix(const Matrix &n);
        ~Matrix(); 
        Matrix operator+(const Matrix &n) const;
        Matrix operator-(const Matrix &n) const;
        Matrix operator*(const Matrix &n) const;
        friend istream &operator>>(istream &in, Matrix &n);
        friend ostream &operator<<(ostream &out, Matrix &n);
        Matrix& operator=(const Matrix& n);
        int operator ()(int i, int j)const;
};
Matrix::Matrix (int n): n(n) { 
    A = new int*[n]; 
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < n; ++i) delete[] A[i];
    delete[] A;
}

Matrix::Matrix(const Matrix &q){
    n = q.n;
    A = new int*[n];
    for (int i = 0; i < n; i++) A[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) A[i][j] = q.A[i][j];
}

istream &operator>>(istream &in, Matrix &n){
    for (int i = 0; i < n.n; i++)
        for (int j = 0; j < n.n; j++) in >> n.A[i][j];
    return in;
}

ostream &operator<<(ostream &out, Matrix &n){
    for (int i = 0; i < n.n; i++){
        for (int j = 0; j < n.n; j++) out << n.A[i][j] << " ";
        out << endl;
    }
    return out;
}

Matrix Matrix::operator+(const Matrix &q) const {
    Matrix t(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            t.A[i][j] = A[i][j] + q.A[i][j];
        }
    }
    return t;
}

Matrix Matrix::operator-(const Matrix &q) const{
    Matrix t(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) t.A[i][j] = A[i][j] - q.A[i][j];
    return t;
}

Matrix Matrix::operator*(const Matrix& q) const{
    Matrix t(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            t.A[i][j] = 0;
            for (int k = 0; k < n; ++k)
                t.A[i][j] += A[i][k] * q.A[k][j];
        }
    return t;
}
Matrix& Matrix::operator=(const Matrix& q){
    if (this == &q) return *this;
    delete [] A;
    n = q.n;
    A = new int*[n];
    for (int i = 0; i < n; i++) A[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) A[i][j] = q.A[i][j];
    return *this;
}

int Matrix::operator ()(int i, int j)const{
    return A[i-1][j-1];
}

int main () {
    Matrix A, B, C, D;
    cout << "Nhap ma tran A: "; cin >> A;
    cout << "Nhap ma tran B: "; cin >> B;
    C = A + B;
    cout << "Ma tran A + B = \n" << C << endl;
    C = A - B;
    cout << "Ma tran A - B = \n" << C << endl;
    C = A * B;
    cout << "Ma tran A * B = \n" << C << endl;
    cout << "Nhap ma tran D: "; cin >> D;
    C = (A+B)+D;
    cout << "Ma tran (A+B)+D = \n" << C << endl;
    cout << A(1,1);
    return 0;
}

