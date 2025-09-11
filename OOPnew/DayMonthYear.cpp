#include <iostream>


using namespace std;

typedef struct Date {
    int d;
    int m;
    int y;
} Date ;

bool check_y(int y) {
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
        return true;
    }
    return false;
}

int check_m (int m, int y) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (check_y(y)) {
        days[1] = 29;
    }
    return days[m - 1];
}

Date& operator++(Date &A) {
    A.d++;
    if (A.d > check_m(A.m, A.y)) {
        A.d = 1;
        A.m++;
        if (A.m > 12) {
            A.m = 1;
            A.y++;
        }
    }
    return A;
}

Date& operator ++(Date &A, int) {
    Date t = A;
    A++;
    return t;

}

Date& operator--(Date &A) {
    A.d--;
    if (A.d == 0) {
        A.m--;
        if (A.m == 0) {
            A.m = 12;
            A.y--;
        }
        A.d = check_m(A.m, A.y);
    }
    return A;
}

istream& operator>>(istream& is, Date& A) {
    is >> A.d >> A.m >> A.y;
    return is;
}

ostream& operator<<(ostream& os, Date& A) {
    os << A.d << "/" << A.m << "/" << A.y;
    return os;
}

int main  () {
    Date A;
    cin >> A;
    Date B = ++A;
    cout << B << endl;
    Date C = --A;
    cout << C << endl;
    return 0;
}