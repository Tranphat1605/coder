#include "stack.hpp" 

using namespace std;

int main () {
    int n;
    cout << "Nhap so nguyen can doi!" << endl;
    cin >> n;
    stack s(8);
    do {
        s.Push(n%16);
        n/=16;
    } while (n);
    int x;
    char HEX[] = "0123456789ABCDEF";
    while (s.isempty()==false) {
        cout << HEX[s.Pop()];
    }
    return 0;
}