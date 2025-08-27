#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* pre;
};

typedef struct node node;

node *makenode(int x) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->pre = NULL;
    return newnode;
}

void duyet(node* newnode) {
    while (head != NULL) {
        printf ("%d ", newnode->data);
        head = head->next;
    }
}

void insert_top(node **head, int x) {
    node *p = makenode(x);
    p->next = *head;
    if (head != NULL) {
        (*head)->pre = p;
    }
    p = *head;
}

void insert_bot(node **head, int x) {
    node *p = makenode(x);
    if (*head == NULL) {
        *head = p;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = p;
    p->pre = tmp;
}

int si_ze(node *head) {
    int s = 0;
    while (head != NULL) {
        s++;
        head = head->next;
    }
    return s;
}
void insret_batki(node **head, int x, int k) {
    int n = si_ze(head);
    if (k < 1 || k > n+1) {
        printf("Vi tri ko hop le!");
    }
    if (k==1) {
        insert_top(x);
    }
    node *p = makenode(x);
    node *tmp = *head;
    while (tmp != k) {
        tmp = tmp->next;
    }
    p->next = tmp;
    tmp->pre->next = p;
    p->pre = tmp->pre;
    tmp->pre = p;
}