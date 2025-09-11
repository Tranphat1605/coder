#include <iostream>
using namespace std;

class Poly{
    private:
        int bacn;
        int *a;

    public:
        Poly(int n = 2);
        Poly(const Poly &n);
        ~Poly();
        Poly operator+(const Poly &n) const;
        Poly operator-(const Poly &n) const;
        friend istream &operator>>(istream &in, Poly &n);
        friend ostream &operator<<(ostream &out, Poly &n);
        Poly& operator=(const Poly &n);
        const int& operator[](int i) const;
        int operator()(int x);
};

Poly::Poly(int n){
    bacn = n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

Poly::Poly(const Poly &n){
    bacn = n.bacn;
    a = new int[n.bacn];
    for (int i = 0; i < n.bacn; i++)
        a[i] = n.a[i];
}

Poly::~Poly(){
    delete [] a;
}

Poly Poly::operator+(const Poly &n) const{
    int bac_max = max (bacn, n.bacn);
    Poly t(bac_max);
    for (int i = 0; i <= min(bacn, n.bacn); i++) {
        t.a[i] = a[i] + n.a[i];
    }
    if (bacn > n.bacn) {
        for (int i = n.bacn + 1; i <= bacn; i++) {
            t.a[i] = a[i];
        }
    } else {
        for (int i = bacn + 1; i <=  n.bacn; i++) {
            t.a[i] = n.a[i];
        }
    }
    return t;
}

Poly Poly::operator-(const Poly &n) const{
    int bac_max = max (bacn, n.bacn);
    Poly t(bac_max);
    for (int i = 0; i <= min(bacn, n.bacn); i++) {
        t.a[i] = a[i] - n.a[i];
    }
    if (bacn > n.bacn) {
        for (int i = n.bacn + 1; i <= bacn; i++) {
            t.a[i] = a[i];
        }
    } else {
        for (int i = bacn + 1; i <= n.bacn; i++) {
            t.a[i] = -n.a[i];
        }
    }
    return t;
}

Poly &Poly::operator=(const Poly &n){
    if (this == &n) return *this;
    delete [] a;
    bacn = n.bacn;
    a = new int[n.bacn];
    for (int i = 0; i < n.bacn; i++)
        a[i] = n.a[i];
    return *this;
}

const int& Poly::operator[](int i) const {
    return a[i-1];
}

int Poly::operator()(int x) {
    int res = 0, mu = 1;
    for (int i = 0; i < bacn; i++) {
        res += a[i] * mu;
        mu *= x;
    }
    return res;
}

istream &operator>>(istream &in, Poly &n){
    for (int i = 0; i < n.bacn; i++) in >> n.a[i];
    return in;
}

ostream &operator<<(ostream &out, Poly &n){
    for (int i = 0; i < n.bacn; i++) out << n.a[i] << " ";
    return out;
}

int main () {
    Poly p1 (3), p2 (5);
    cout << "Nhap da thuc p1: ";
    cin >> p1;
    cout << "Nhap da thuc p2: ";
    cin >> p2;
    cout << "Tong 2 da thuc la: ";
    Poly p3 = p1 + p2;
    cout << p3 << endl;
    cout << "Hieu 2 da thuc la: ";
    p3 = p1 - p2;
    cout << p3 << endl;
    cout << "He so thu 2 cua p1 la: " << p1[2] << endl;
    cout << "P1(5) = " << p1(5) << endl;
    return 0;
}