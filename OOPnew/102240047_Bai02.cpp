#include <bits/stdc++.h>
using namespace std;

typedef struct Hocsinh {
    string hoten;
    float diemvan;
    float diemtoan;
    float dtb;
} HS;

float diemtrungbinh(const HS& a) {
    return (2.0f * a.diemvan + 3.0f * a.diemtoan) / 5.0f;
}

string xeploai(HS a) {
    if (diemtrungbinh(a) >= 8) return "Gioi";
    else if (diemtrungbinh(a) >= 7.0 && diemtrungbinh(a) < 8) return "Kha";
    else if (diemtrungbinh(a) >= 5 && diemtrungbinh(a) < 7) return "Trung binh";
    else return "Yeu";
}


istream& operator>>(istream& is, HS& a) {
    is >> ws;
    getline(is, a.hoten);
    is >> a.diemvan >> a.diemtoan;
    a.dtb = diemtrungbinh(a);
    return is;
}

ostream& operator<<(ostream& os, const HS& a) {
    os << a.hoten << " "
       << fixed << setprecision(2) << a.diemvan << " "
       << fixed << setprecision(2) << a.diemtoan << " "
       << fixed << setprecision(2) << a.dtb;
    return os;
}


void bubblesort(HS a[], int n, bool tang) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            bool needSwap = tang ? (a[j].dtb > a[j+1].dtb)
                                 : (a[j].dtb < a[j+1].dtb);
            if (needSwap) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void tangg(const HS a[], int n) {
    if (n <= 0) return;
    HS* b = new HS[n];
    for (int i = 0; i < n; ++i) b[i] = a[i];
    bubblesort(b, n, true);
    for (int i = 0; i < n; ++i) cout << b[i] << " " << xeploai(b[i]) << "\n";
    delete[] b;
}

void giamm(const HS a[], int n) {
    if (n <= 0) return;
    HS* b = new HS[n];
    for (int i = 0; i < n; ++i) b[i] = a[i];
    bubblesort(b, n, false);
    for (int i = 0; i < n; ++i) cout << b[i] << " " << xeploai(b[i]) << "\n";
    delete[] b;
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    if (!(cin >> n) || n <= 0) return 0;

    HS* a = new HS[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap hoc sinh #" << i + 1 << ":\n";
        cin >> a[i];
    }

    cout << "\nDanh sach goc:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << xeploai(a[i]) << "\n";
    }

    int ch;
    cout << "\nSap xep theo DTB:\n1) Tang dan\n2) Giam dan\nLua chon: ";
    cin >> ch;

    if (ch == 2) giamm(a, n);
    else tangg(a, n);

    delete[] a;
    return 0;
}
