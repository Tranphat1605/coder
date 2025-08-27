#include <iostream>
using namespace std;

typedef int elementtype;

struct node {
    elementtype data;
    node* next;
};

typedef node* queue;

// Khởi tạo hàng đợi rỗng
void init(queue &q) {
    q = NULL;
}

// Kiểm tra hàng đợi có rỗng không
int empty(queue q) {
    return (q == NULL);
}

void append(queue &l, elementtype x) { // them vao cuoi
    node* p = new node;
    p->data = x;
    p->next = NULL;
    if (empty(l)) l = p;
    else {
        p = l;
        while (p->next != NULL) p = p->next;
        p->next = l;
    }
}

void pop(queue &l, elementtype &x) {  // lay phan tu ra
    node *q; 
    if(empty(l)) cout << "Queue is empty!\n";
    else {
        x = l->data;
        q = l;
        l = l->next;
        delete q;
    }
}

void dispose(queue &l) { // xoa toan bo
    elementtype x;
    while (!empty(l)) pop(l, x);
}

void show(queue l) {
    node* p = l;
    if (empty(l)) cout << "Queue is empty!\n";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
