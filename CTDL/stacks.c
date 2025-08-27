#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;
const int MX = 10;

struct node {
    elementtype data[10];
    unsigned int n;
};

typedef struct node stack;

void init(stack* l) {
    l->n = 0;
}

int empty(stack l) {
    return l.n == 0;
}

int over(stack l) {
    return l.n == MX;
}

void push(stack* l, elementtype x) {
    if (over(*l)) {
        printf("Danh sach da day\n");
        return;
    }
    l->data[l->n++] = x;
}

elementtype pop(stack* l) {
    if (empty(*l)) {
        printf("Danh sach rong\n");
        return -1;
    }
    return l->data[--l->n];
}

void pop1(stack* l) {
    if (empty(*l)) {
        printf("Danh sach rong\n");
        return;
    }
    l->n--;
}

void printstack(stack l) {
    for (int i = l.n - 1; i >= 0; i--) {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}

int main() {
    stack l;
    elementtype a[5] = {1, 2, 3, 4, 5};

    init(&l);

    // pop(&l);
    for (int i = 0; i < 5; i++) {
        push(&l, a[i]);
    }

    printstack(l);

    elementtype x = pop(&l);
    printf("Pop: %d\n", x);
    printstack(l);

    pop1(&l);
    printstack(l);

    return 0;
}
