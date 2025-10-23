#include <iostream>
#include <cmath>
#define pi 3.14
using namespace std;

class land {
    public:
        virtual double dientich() const = 0;
        virtual double chuvi() const = 0;
        virtual void display() const = 0;
        virtual ~land() {};
};

class hinhvuong : public land {
    private:
        double canh;
    public:
        hinhvuong(double c) : canh(c) {}
        double dientich() const {
            return canh * canh;
        }
        double chuvi() const {
            return canh * 4;
        }
        void display() const {
            cout << "Hinh vuong co canh: " << canh << endl;
            cout << "   Dien tich: " << dientich() << endl;
            cout << "   Chu vi: " << chuvi() << endl;
        }
};

class tamgiac : public land {
    private:
        double a;
    public:
        tamgiac(double c) : a(c) {}
        double dientich() const {
            return a * a * sqrt(3)/4;
        }
        double chuvi() const {
            return a * 3;
        }
        void display() const {
            cout << "Tam giac co canh: " << a << endl;
            cout << "   Dien tich: " << dientich() << endl;
            cout << "   Chu vi: " << chuvi() << endl;
        }
};

class hinhtron : public land {
    private:
        double r;
    public:
        hinhtron(double c) : r(c) {}
        double dientich() const {
            return pi * r * r;
        }
        double chuvi() const {
            return 2 * pi * r;
        }
        void display() const {
            cout << "Hinh tron co ban kinh: " << r << endl;
            cout << "   Dien tich: " << dientich() << endl;
            cout << "   Chu vi: " << chuvi() << endl;
        }
};

int main () {
    land* lands[3];
    lands[0] = new hinhvuong(8);
    lands[1] = new tamgiac(9);
    lands[2] = new hinhtron(10);
    cout << "=== DANH SACH CAC MANH DAT ===\n";
    double s = 0;
    for (int i = 0; i < 3; i++) {
        lands[i]->display();
        s += lands[i]->dientich();
    }
    cout << "Tong dien tich: " << s << endl;
    return 0;
}