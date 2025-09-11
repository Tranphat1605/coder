#include "point.h"
#include <iostream>
using namespace std;

void point::SetPt(int xx, int yy) {
    x = xx;
    y = yy;
}

void point::Display() {
    cout << "(" << x << ", " << y << ")" << endl ;
}