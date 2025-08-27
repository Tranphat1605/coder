#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node; 

node* makenode(int x){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode; 
}

int rong(node* head){
    return (head == NULL)
}

void duyet(node *head) {
    while (head != NULL){
        printf("%d", head->data);
        head = head->next;
    }
}

int dem(node* head) {
    int s = 0;
    while (head!=NULL) {
        head = head->next;
        s++;
    }
    return s;
}

void chendau(node **head, int x){
    node* p = makenode(x);
    p->next = (*head);
    (*head) = p;
}

void chencuoi(node **head, int x) {
    node* newnode = makenode(x) ;
    if (*head == NULL) {
        newnode->data = x;
        *head = newnode;
        return;
    }
    node* temp = *head;
    while (temp != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

voi chenbatki(node **head, int k, int n) {
    int n = size(*head);
    if (n < 1 || n > k+1) {
        printf("Vi tri khong hop le!");
        return;
    }
    if (n == 1) {
        chendau(head, x);
        return; 
    } 
    node *temp = *head;
    for (int i = 1; i < k - 1; i++){
        temp = temp->next;
    }
    node *newnode = makenode(x);
    newnode->next = temp->next;
    temp->next = newnode;
}

void xoadau(node **head){
    if (*head == NULL) {
        return;
    }
    node *temp = *head;
    *head = tem->next;
}

void xoacuoi(node **head){
    if(*head == NULL) {
        return;
    }
    node *tmp = *head;
    if (tmp->next == NULL) {
        *head = NULL;
        free(tmp);
    }
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    } 
    node *last = tmp->next;
    tmp->next = NULL;
    free(last);
}

void xoabatki(node **head, int k) {
    int n = size(*head);
    if (k < 1 || k > n+1 ) {
        printf("Vi tri khong hop le!");
    }
    if (k == 1) {
        xoadau(head);
    } else {
        node *sau = *head;
        node *truoc = *head;
        for (int i = 1; i <= k-1; i++) {
            sau = truoc;
            truoc = truoc->next;
        }
        sau->next = truoc->next;
        free(truoc);
    }
}

node* search_x(node* head, int x){
    if(rong(head)) return NULL;
    node *p = *head;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

node* node_max(node *head) {
    node *p = *head;
    node* min = *head;
    while (p != NULL) {
        if (min->data > p->data) {
            min = p;
        }
    }
    return p;
}

int data_max(node *head) {
    node *p = node_max(head);
    return p->data;
}

void sortlist(node** head){
    for (node *i = *head; i != NULL; i = i->next) {
        node *min = i;
        for (node *j = i->next; j != NULL; j = j->next) {
            if (min->data > j->data) {
                min = j;
            }
        }
        int tmp = min->data;
            min->data = i->data;
            i->data = tmp;
    }
}

void replace_x_y(node *head, int x, int y) {
    node *p = search_x(head, x);
    if(p != NULL) {
        p->data = y
    }
}
 
void replacceall_x_y(node*head, int x, int y) {
    if(rong(head)) return NULL;
    node *p = head;
    while(p != NULL) {
        if(p->data == x) p->data = y;
        p = p->next;
    }
}