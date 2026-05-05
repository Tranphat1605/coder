#include <iostream>
using namespace std;

class date {
private:
    int d, m, y;
    bool check_y(int y) const;
    int check_m(int m, int y) const;
public:
    date(int d = 1, int m = 1, int y = 2000);
    friend istream &operator>>(istream &is, date &A);
    friend ostream &operator<<(ostream &os, const date &A);
    date &operator++();
    date operator++(int);
    date &operator--();
    date operator--(int);
    date operator+(int add) const;
    date operator-(int sub) const;
};

bool date::check_y(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int date::check_m(int m, int y) const {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (check_y(y)) days[2] = 29;
    return days[m];
}

date::date(int d, int m, int y) {
    this->d = d;
    this->m = m;
    this->y = y;
}

istream &operator>>(istream &is, date &A) {
    is >> A.d >> A.m >> A.y;
    return is;
}

ostream &operator<<(ostream &os, const date &A) {
    os << A.d << "/" << A.m << "/" << A.y;
    return os;
}

date &date::operator++() {
    d++;
    if (d > check_m(m, y)) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    return *this;
}

date date::operator++(int) {
    date t = *this;
    ++(*this);
    return t;
}

date &date::operator--() {
    d--;
    if (d == 0) {
        m--;
        if (m == 0) {
            m = 12;
            y--;
        }
        d = check_m(m, y);
    }
    return *this;
}

date date::operator--(int) {
    date t = *this;
    --(*this);
    return t;
}

date date::operator+(int add) const {
    date t = *this;
    t.d += add;
    while (t.d > check_m(t.m, t.y)) {
        t.d -= check_m(t.m, t.y);
        t.m++;
        if (t.m > 12) {
            t.m = 1;
            t.y++;
        }
    }
    return t;
}

date date::operator-(int sub) const {
    date t = *this;
    t.d -= sub;
    while (t.d <= 0) {
        t.m--;
        if (t.m == 0) {
            t.m = 12;
            t.y--;
        }
        t.d += check_m(t.m, t.y);
    }
    return t;
}

int main() {
    date A;
    cout << "Nhap ngay thang nam: ";
    cin >> A;
    cout << "Ngay ban dau la: " << A << endl;
    date B = ++A;
    cout << "Sau ++A: " << B << endl;
    date C = A++;
    cout << "Sau A++: " << C << endl;
    date D = --A;
    cout << "Sau --A: " << D << endl;
    date E = A--;
    cout << "Sau A--: " << E << endl;
    date F = A + 10;
    cout << "Sau A + 10 ngay: " << F << endl;
    date G = A - 10;
    cout << "Sau A - 10 ngay: " << G << endl;
    return 0;
}
