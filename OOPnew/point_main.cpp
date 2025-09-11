#include "point.hpp" 

int main () {
    point p1, p2, p3;
    p1.SetPt(1, 2);
    p2.SetPt(3, 4);
    p3.SetPt(5, 6);
    p1.Display();
    p2.Display();
    p3.Display();
}