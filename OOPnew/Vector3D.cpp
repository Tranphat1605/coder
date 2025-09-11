#include <iostream>

using namespace std;

typedef struct vecto {
    int x;
    int y;
    int z;
} vecto; 

vecto operator+(vecto a, vecto b ) {
    vecto c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

vecto operator-(vecto a, vecto b ) {
    vecto c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

int operator*(vecto a, vecto b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

istream& operator>>(istream& is, vecto& a) {
    is >> a.x >> a.y >> a.z;
    return is;
}

ostream& operator<<(ostream& os, vecto& a) {
    os << a.x << " " << a.y << " " << a.z;
    return os;
}

int main() {
    vecto a,b,c;
    cin >> a >> b;
    c = a + b;
    cout << c << endl;
    c = a - b;
    cout << c << endl;
    cout << a * b << endl;
    return 0;
}