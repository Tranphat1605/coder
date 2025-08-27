#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int elementtype;

struct node {
    elementtype data;
    node *next;
};

struct linkedlist {
    node *f; // front
    node *r; // rear
};

typedef struct linkedlist queue;

void init(queue &l) {
    l.f = NULL;
    l.r = NULL;
}

int empty(queue l) {
    return ((l.f == NULL) && (l.r == NULL));
}

void append(queue &l, elementtype x) {
    node *p = new node;
    p->data = x;
    p->next = NULL;
    if (l.f == NULL) l.f = l.r = p;
    else {
        l.r->next = p;
        l.r = p;
    }
}

void pop(queue &l, elementtype &x) {
    node *q;
    if (empty(l)) {
        cout << "Queue is empty!\n";
    } else {
        x = l.f->data;
        q = l.f;
        l.f = l.f->next;
        if (l.f == NULL) l.r = NULL;
        delete q;
    }
}

void show(queue l) {
    if (empty(l)) {
        cout << "Queue is empty!\n";
        return;
    }
    node *p = l.f;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main (){
    queue l; // khai bao l la hang doi
    init(l) ; // khoi tao hang doi l
    append(l, 10);
    append(l, 20);
    append(l, 30);
    show(l);
    int x;
    pop(l, x);
    show(l);
    return 0;
}