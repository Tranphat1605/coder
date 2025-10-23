#include <iostream>
using namespace std;
class Point {
    int x, y;
public:
    Point(int a=0, int b=0): x(a), y(b) {}
    
    int getX() const { return x; }   // OK
    void setX(int a){ x = a; }       // không const
};

int main() {
    const Point p(5,2);  // const object
    cout << p.getX();    // ✅ gọi được
    // p.setX(5);        // ❌ lỗi, vì setX không const
}
