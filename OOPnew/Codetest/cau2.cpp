#include <iostream>
using namespace std;
struct BaseA
{
    int prop_a;
};
struct BaseB
{
    int *prop_b;
};
struct BaseC : public BaseA, public BaseB
{
};
int main()
{
    BaseC *ptr = new BaseC;
    ptr->prop_b = new int(3);
    cout << ptr->prop_a << " " << *(ptr->prop_b);
    return 0;
}