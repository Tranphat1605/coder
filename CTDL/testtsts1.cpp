#include <stdio.h>

typedef int elementtype;
struct node 
{
    elementtype data;
    node* next;
    node* pre;
};

typedef struct node* list;

void intit(list &l) {
    l = NULL;
}

void insert_top(list &l, elementtype x) {
    node *q;
    node*
}