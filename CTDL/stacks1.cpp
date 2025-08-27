#include <iostream>
using namespace std;

typedef int elementtype;
const int MX = 10;

struct node {
    elementtype data[MX];
    unsigned int n;
};

typedef struct node stack;

void init(stack &l) {
    l.n = 0;
}

bool empty(stack& l) {
    return l.n == 0;
}

bool over(stack& l) {
    return l.n == MX;
}

void push(stack& l, elementtype x) {
    if (over(l)) {
        cout << "Danh sach da day\n";
        return;
    }
    l.data[l.n++] = x;
}

elementtype pop(stack& l) {
    if (empty(l)) {
        cout << "Danh sach rong\n";
        return -1;
    }
    return l.data[--l.n];
}

void pop1(stack& l) {
    if (empty(l)) {
        cout << "Danh sach rong\n";
        return;
    }
    l.n--;
}


void print(const stack& l) {
    for (int i = l.n - 1; i >= 0; --i) {
        cout << l.data[i] << " ";
    }
    cout << "\n";
}

int main() {
    stack l;
    init(l);
    push(l, 10);
    push(l, 20);
    push(l, 30);
    print(l);
    cout << "Pop: " << pop(l) << "\n";
    print(l);
    pop1(l);
    print(l);
    return 0;
}
