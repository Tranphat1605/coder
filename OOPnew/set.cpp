#include <iostream>
using namespace std;

class set {
private:
    int n;
    int size;
    int *data;
    bool check(int x) const;
public:
    set(int size  = 10);
    ~set() {
        delete[] data;
    }
    set(int a[], int n, int size = 10);
    set(const set &b);
    set& operator=(const set &b);
    set operator+(int x) const;
    set operator-(int x) const;
    set operator+(const set &b) const;
    set operator-(const set &b) const;
    set operator*(const set &b) const;
    bool operator()(int x) const;
    int operator[](int x) const;
    friend istream &operator>>(istream &in, set &b);
    friend ostream &operator<<(ostream &out, const set &b);
};

bool set::check(int x) const {
    for (int i = 0; i < n; i++)
        if (data[i] == x) return true;
    return false;
}

set::set(int size) {
    this->size = size;
    data = new int[size];
    n = 0;
}

set::set(int a[], int n, int size) {
    this->size = size;
    data = new int[size];
    this->n = 0;
    for (int i = 0; i < n; i++) {
        if (!check(a[i])) data[this->n++] = a[i];
    }
}

set::set(const set &b) {
    n = b.n;
    size = b.size;
    data = new int[size];
    for (int i = 0; i < n; i++)
        data[i] = b.data[i];
}

set& set::operator=(const set &b) {
    if (this != &b) {
        delete[] data;
        n = b.n;
        size = b.size;
        data = new int[size];
        for (int i = 0; i < n; i++)
            data[i] = b.data[i];
    }
    return *this;
}

set set::operator+(int x) const {
    set t(*this);
    if (!t.check(x)) t.data[t.n++] = x;
    return t;
}

set set::operator-(int x) const {
    set t(*this);
    for (int i = 0; i < t.n; i++) {
        if (t.data[i] == x) {
            for (int j = i; j < t.n - 1; j++)
                t.data[j] = t.data[j + 1];
            t.n--;
            break;
        }
    }
    return t;
}

set set::operator+(const set &b) const {
    set t(*this);
    for (int i = 0; i < b.n; i++) {
        if (!t.check(b.data[i])) {
            t.data[t.n++] = b.data[i];
        }
    }
    return t;
}

set set::operator-(const set &b) const {
    set t;
    for (int i = 0; i < n; i++) {
        if (!b.check(data[i])) {
            t = t + data[i];
        }
    }
    return t;
}

set set::operator*(const set &b) const {
    set t;
    for (int i = 0; i < n; i++) {
        if (b.check(data[i])) {
            t = t + data[i];
        }
    }
    return t;
}

bool set::operator()(int x) const {
    return check(x);
}

int set::operator[](int x) const {
    return data[x];
}

istream &operator>>(istream &in, set &b) {
    cout << "Nhap so phan tu: ";
    in >> b.n;
    if (b.n > b.size) b.n = b.size;
    b.data = new int[b.size];
    int x;
    for (int i = 0; i < b.n; i++) {
        in >> x;
        if (!b.check(x)) b.data[i] = x;
    }
    return in;
}

ostream &operator<<(ostream &out, const set &b) {
    out << "{ ";
    for (int i = 0; i < b.n; i++)
        out << b.data[i] << " ";
    out << "}";
    return out;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    set A(arr1, 5);
    set B(arr2, 5);

    cout << "Tap A la: " << A << endl;
    cout << "Tap B la: " << B << endl;

    set C = A + B;
    cout << "Hop cua A va B la: " << C << endl;

    set D = A - B;
    cout << "Hieu cua A va B la: " << D << endl;

    set E = A * B;
    cout << "Giao cua A va B la: " << E << endl;

    set F = A + 6;
    cout << "Tap A + 6 la: " << F << endl;

    set G = A - 3;
    cout << "Tap A - 3 la: " << G << endl;

    return 0;
}
