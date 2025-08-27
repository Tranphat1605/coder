#include <iostream>

using namespace std;

typedef int elementtype;
typedef struct node *stack;

struct node {
    elementtype data;
    node *next;
};

void init(stack &l) {
    l = NULL;
}

int empty(stack l) {
    return (l == NULL);
}

void push(stack &l, elementtype x) {
    stack p = new node;
    p->data = x;
    p->next = l;
    l = p;
}

elementtype pop(stack &l) {
    elementtype x = l->data;
    stack p = l;
    l = l->next;
    delete p;
    return x;
}

void pop1(stack &l) {
    if (empty(l)) {
        cout << "Ngan xep rong" << endl;
        return;
    }
    stack p = l;
    l = l->next;
    delete p;
}

void pop2(stack &l, elementtype &x) {
    if (!empty(l)) {
        stack q = l;
        x = l->data;
        l = l->next;
        delete q;
    }
}

void show(stack l) {
    stack p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main () {
    stack l;
    init(l);
    push(l, 10);
    push(l, 20);
    push(l, 30);
    show(l);
    cout << "Pop: " << pop(l) << endl;
    show(l);
    pop1(l);
    show(l);
    return 0;
}