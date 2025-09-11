
#include "stack.hpp"
using namespace std;

int main () {
    stack s;
    s.Push(1);
    s.Push(5);
    s.Push(7);
    s.Pop();
    s.show();
    return 0;
}