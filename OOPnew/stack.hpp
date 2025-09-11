#include <iostream>

using namespace std; 
#define MAX 100
#ifndef stack_h
#define stack_h
class stack{
    private:
        int *data;
        int maxsize;
        int top;
    public:
        stack(int size = MAX);
        ~stack();
        void Push(int);
        int Pop();
        bool isfull();
        bool isempty();
        void show();
};

#endif

// stack::stack() {
//     data = new int[MAX];
//     maxsize = MAX;
//     top = -1;
// }

// stack::~stack() {
//     delete[] data;
// }

stack::stack(int size) {
    data = new int[size];
    maxsize = size;
    top = -1;
}

stack::~stack() {
    delete[] data;
}
bool stack::isfull() {
    return top == maxsize - 1;
}

bool stack::isempty() {
    return top == -1;
}

void stack::Push(int x) {
    if (isfull()) {
        cout << "Stack is full" << endl;
        return;
    }
    data[++top] = x;
}


void stack::show() {
    for (int i = 0; i <= top; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int stack::Pop() {
    if (isempty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return data[top--];
}