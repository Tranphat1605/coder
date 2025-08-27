#include <iostream>

using namespace std;

typedef int elementtype;
typedef struct node *stack;
struct node {
    elementtype data;
    node *next;
};


void init (stack &l) {
    l = NULL;
}

int emptyy(stack l) {
    return (l == NULL);
}

void pushh(stack &l, elementtype x) {
    node *p = new node;
    p->data = x;
    p->next = l;
    l = p;
}

void pop1(stack &l) {
    if (emptyy(l)) {
        cout << "danh sach rong" << endl;
        return;
    }
    node *p = l;
    l = l->next;
    delete p;
}


void pop2(stack &l, elementtype &x) {
    if (emptyy(l)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    node *p  = l; 
    x = l->data;
    l = l->next;
    delete p;
}

elementtype pop3(stack &l) {
    if (emptyy(l)) {
        cout << "danh sach rong!" << endl;
        return -1;
    }
    elementtype x = l->data; 
    node *p = l;
    l = l->next;
    delete p;
    return x;
}

void show(stack l) {
    stack p = l; 
    while (l != NULL) {
        cout << l->data << " ";
        l = l->next;
    }
}

node* search(stack l, elementtype x) {
    if (emptyy(l)) {
        cout << "danh sach rong" ;
        return NULL;
    }
    while (l != NULL) {
        if (l->data == x) {
            return l;
        }
        l = l->next;
    }
    return NULL;
}

void deletee_node_x(stack &l, elementtype x) {
    if (emptyy(l)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    if (l->data == x) {
        pop1(l);
        return;
    }
    stack p = search(l, x);
    if (p == NULL) {
        cout << "Khong tim thay noode can xoa" << endl;
    } else {
        node *q = l;
        while (q->next != NULL) {
            if (q->next == p) {
                q->next = p->next;
                delete p;
                break;
            }
            q = q->next;
        }
    }
}
int main() {
    elementtype a;
    stack l;
    init(l);
    pushh(l, 12);
    pushh(l, 14);
    pushh(l, 37);
    pushh(l, 6);
    show(l);
    cout << endl;
    pop2(l, a);
    cout << "a = " << a << endl;
    show(l);
    cout << endl;
    elementtype x = pop3(l);;
    return 0;
}