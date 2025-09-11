
#include <iostream>
using namespace std;

class point {
    int x, y;
    public:
        // point(int xx = 0, int yy = 0); 
        // point(point &p);
        void SetPt(int, int);
        void Display();
};



void point::SetPt(int xx, int yy) {
    x = xx;
    y = yy;
}

void point::Display() {
    cout << "(" << x << ", " << y << ")" << endl ;
}

point::~point() {};