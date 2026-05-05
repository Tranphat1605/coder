#include <iostream>

using namespace std;

int x[100];

void inkq() {
    for (int j = 1; j <= x[0]; j++) {
        cout << x[j];
    }
    cout << endl;
}

void sinhbit(int n) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            inkq();
        } else {
            sinhbit(n+1);
        }
    }
}

int main () {
    int n;
    cout << "Nhap so luong bit: ";
    cin >> n;
    x[0] = n;
    sinhbit(1);
    return 0;
}