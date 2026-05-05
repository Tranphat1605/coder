#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap cap ma tran: ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    cout << "Nhap ma tran A:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<double>> L(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];

            if (i == j)
                L[i][j] = sqrt(A[i][i] - sum);
            else
                L[i][j] = (A[i][j] - sum) / L[j][j];
        }
    }

    cout << "Ma tran L:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << L[i][j] << " ";
        cout << endl;
    }
    return 0;
}

