#include <iostream>
using namespace std;

class Date {
protected:
    int d, m, y;
    bool check_y(int y) const;
    int check_m(int m, int y) const;
public:
    Date(int d = 1, int m = 1, int y = 2000);
    friend istream &operator>>(istream &is, Date &A);
    friend ostream &operator<<(ostream &os, const Date &A);
    Date &operator++();
    Date &operator--();
};

class Time {
protected:
    int h, mt, s;
public:
    Time(int h = 0, int mt = 0, int s = 0);
    friend istream &operator>>(istream &is, Time &T);
    friend ostream &operator<<(ostream &os, const Time &T);
    Time &operator++();
    Time &operator--();
};

class DateTime : public Date, public Time {
public:
    DateTime(int h = 0, int mt = 0, int s = 0, int d = 1, int m = 1, int y = 2000);
    DateTime &operator++();
    DateTime &operator--();
    friend istream &operator>>(istream &is, DateTime &DT);
    friend ostream &operator<<(ostream &os, const DateTime &DT);
};

bool Date::check_y(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::check_m(int m, int y) const {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (check_y(y)) days[2] = 29;
    return days[m];
}

Date::Date(int d, int m, int y) {
    this->d = d;
    this->m = m;
    this->y = y;
}

istream &operator>>(istream &is, Date &A) {
    is >> A.d >> A.m >> A.y;
    return is;
}

ostream &operator<<(ostream &os, const Date &A) {
    os << A.d << "/" << A.m << "/" << A.y;
    return os;
}

Date &Date::operator++() {
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

Date &Date::operator--() {
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

Time::Time(int h, int mt, int s): h(h), mt(mt), s(s) {}
istream &operator>>(istream &is, Time &T) {
    is >> T.h >> T.mt >> T.s;
    return is;
}

ostream &operator<<(ostream &os, const Time &T) {
    os << T.h << ":" << T.mt << ":" << T.s;
    return os;
}

Time &Time::operator++() {
    s++;
    if (s > 59) {
        s = 0;
        mt++;
        if (mt > 59) {
            mt = 0;
            h++;
            if (h > 23) {
                h = 0;
            }
        }
    }
    return *this;
}

Time &Time::operator--() {
    s--;
    if (s < 0) {
        s = 59;
        mt--;
        if (mt < 0) {
            mt = 59;
            h--;
            if (h < 0) {
                h = 23;
            }
        }
    }
    return *this;
}

DateTime::DateTime(int h, int mt, int s, int d, int m, int y) 
    : Date(d, m, y), Time(h, mt, s) {}

DateTime &DateTime::operator++() {
    int oldH = h, oldM = mt, oldS = s;
    Time::operator++();
    if (oldH == 23 && oldM == 59 && oldS == 59) Date::operator++();
    return *this;
}

DateTime &DateTime::operator--() {
    int oldH = h, oldM = mt, oldS = s;
    Time::operator--();
    if (oldH == 0 && oldM == 0 && oldS == 0) Date::operator--();
    return *this;
}

istream &operator>>(istream &is, DateTime &DT) {
    is >> (Date&)DT >> (Time&)DT;
    return is;
}

ostream &operator<<(ostream &os, const DateTime &DT) {
    os << (Date)DT << " " << (Time)DT;
    return os;
}

int main() {
    Date d1;
    Time t1;
    DateTime dt1;
    cout << "Nhap ngay thang nam: "; cin >> d1;
    cout << "Nhap gio phut giay: "; cin >> t1;
    cout << "Nhap ngay thang nam gio phut giay: "; cin >> dt1;
    cout << "Date: " << d1 << endl;
    cout << "Date++: " << ++d1 << endl;
    cout << "Date--: " << --d1 << endl;
    cout << endl;
    cout << "Time: " << t1 << endl;
    cout << "Time++: " << ++t1 << endl;
    cout << "Time--: " << --t1 << endl;
    cout << endl;
    cout << "DateTime: " << dt1 << endl;
    cout << "DateTime++: " << ++dt1 << endl;
    cout << "DateTime--: " << --dt1 << endl;
    return 0;
}
