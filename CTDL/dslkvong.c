#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

typedef struct node {
    elementtype data;
    struct node* next;
} node;

void init(node** head) {
    *head = NULL;
}

int Empty(node* head) {
    return (head == NULL);
}

void show(node* head) {
    if (Empty(head)) {
        printf("Ds rong!!!\n");
        return;
    }
    node* p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void addnode(node** head, elementtype x) {
    node* q = (node*)malloc(sizeof(node));
    q->data = x;
    if (Empty(*head)) {
        *head = q;
        q->next = *head;
    } else {
        node* p = *head;
        while (p->next != *head) p = p->next;
        p->next = q;
        q->next = *head;
    }
}

void insert_top(node** head, elementtype x) {
    node* q = (node*)malloc(sizeof(node));
    q->data = x;
    if (Empty(*head)) {
        *head = q;
        q->next = *head;
    } else {
        node* p = *head;
        while (p->next != *head) p = p->next;
        q->next = *head;
        p->next = q;
        *head = q;
    }
}

node* search_x(node* head, elementtype x) {
    if (Empty(head)) return NULL;
    node* p = head;
    do {
        if (p->data == x) return p;
        p = p->next;
    } while (p != head);
    return NULL;
}

node* search_x_node(node* head, node* x) {
    if (Empty(head)) return NULL;
    node* p = head;
    do {
        if (p == x) return p;
        p = p->next;
    } while (p != head);
    return NULL;
}

void delete_x(node** head, node* x) {
    if (Empty(*head)) {
        printf("Danh sach rong!!!\n");
        return;
    }

    node *p = *head, *prev = NULL;
    do {
        if (p == x) break;
        prev = p;
        p = p->next;
    } while (p != *head);

    if (p != x) {
        printf("Khong ton tai x!!!\n");
        return;
    }

    if (p == *head && p->next == *head) {
        *head = NULL;
        free(p);
        return;
    }

    if (prev == NULL) {
        node* last = *head;
        while (last->next != *head) last = last->next;
        *head = p->next;
        last->next = *head;
    } else {
        prev->next = p->next;
    }
    free(p);
}

node* node_max(node* head, node* s) {
    if (Empty(head)) return NULL;
    node *p = head, *t = head;
    do {
        if (p->data > t->data) t = p;
        p = p->next;
    } while (p != s);
    return t;
}

elementtype data_max(node* head, node* s) {
    node* p = node_max(head, s);
    return p->data;
}

void sort_list(node* head) {
    if (Empty(head)) return;
    node* s = head;
    node* p = head;
    elementtype t;
    do {
        node* q = node_max(p, s);
        t = q->data;
        q->data = p->data;
        p->data = t;
        p = p->next;
    } while (p != head);
}

void insert_x(node* head, elementtype x, node* a) {
    node* p = search_x_node(head, a);
    if (p == NULL) {
        printf("Khong tim thay node!!!\n");
        return;
    }
    node* q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void replace_x_y(node* head, elementtype x, elementtype y){
    node* p = search_x(head, x);
    if (p != NULL) {
        p->data = y;
    }
}

void replace_all_x_y(node* head, elementtype x, elementtype y) {
    if (Empty(head)) return;
    node* p = head;
    do {
        if (p->data == x) p->data = y;
        p = p->next;
    } while (p != head);
}

int main() {
    node* head;
    init(&head);

    printf("Them cac phan tu vao danh sach:\n");
    addnode(&head, 5);
    addnode(&head, 3);
    insert_top(&head, 7);
    insert_top(&head, 5);
    addnode(&head, 2);
    printf("Danh sach sau khi them: ");
    show(head);

    printf("Kiem tra danh sach rong: %d\n", Empty(head));

    elementtype x = 5;
    node* found = search_x(head, x);
    if (found) {
        printf("Tim thay %d trong danh sach\n", x);
    } else {
        printf("Khong tim thay %d\n", x);
    }

    node* some_node = head->next;
    node* found_node = search_x_node(head, some_node);
    if (found_node) {
        printf("Tim thay node co gia tri %d\n", found_node->data);
    } else {
        printf("Khong tim thay node\n");
    }

    node* max_node = node_max(head, head);
    if (max_node) {
        printf("Node co gia tri lon nhat: %d\n", max_node->data);
    }

    elementtype max_value = data_max(head, head);
    printf("Gia tri lon nhat: %d\n", max_value);

    printf("Thay the mot phan tu 5 bang 10:\n");
    replace_x_y(head, 5, 10);
    printf("Danh sach sau khi thay the: ");
    show(head);

    printf("Thay the tat ca phan tu 5 bang 8:\n");
    replace_all_x_y(head, 5, 8);
    printf("Danh sach sau khi thay the tat ca: ");
    show(head);

    printf("Chen 6 sau node co gia tri 7:\n");
    node* node_to_insert_after = search_x(head, 7);
    insert_x(head, 6, node_to_insert_after);
    printf("Danh sach sau khi chen: ");
    show(head);

    printf("Sap xep danh sach:\n");
    sort_list(head);
    printf("Danh sach sau khi sap xep: ");
    show(head);

    printf("Xoa node co gia tri 7:\n");
    node* node_to_delete = search_x(head, 7);
    delete_x(&head, node_to_delete);
    printf("Danh sach sau khi xoa: ");
    show(head);

    printf("Xoa toan bo danh sach:\n");
    while (!Empty(head)) {
        delete_x(&head, head);
    }
    printf("Danh sach sau khi xoa het: ");
    show(head);
    printf("Kiem tra danh sach rong: %d\n", Empty(head));

    return 0;
}
