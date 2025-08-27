#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

node* makenode(int x) {
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

int sz(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void duyet(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_top(node** head, int x) {
    node* p = makenode(x);
    p->next = *head;
    *head = p;
}

void insert_bot(node** head, int x) {
    node* p = makenode(x);
    if (*head == NULL) {
        *head = p;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

void insert(node** head, int x, int k) {
    int n = sz(*head);
    if (k < 1 || k > n + 1) {
        printf("Vi tri khong hop le\n");
        return;
    }
    if (k == 1) {
        insert_top(head, x);
        return;
    }
    node* temp = *head;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }
    node* p = makenode(x);
    p->next = temp->next;
    temp->next = p;
}

int main() {
    node* head = NULL;
    while (1) {
        printf("---------------DSLK---------------\n");
        printf("1. Them node vao dau\n");
        printf("2. Them node vao cuoi\n");
        printf("3. Them node vao vi tri k\n");
        printf("4. Duyet\n");
        printf("5. Thoat\n");
        printf("----------------------------------\n");
        printf("Nhap lua chon: ");
        int lc;
        scanf("%d", &lc);
        if (lc == 1) {
            int x;
            printf("Nhap x: ");
            scanf("%d", &x);
            insert_top(&head, x);
        } else if (lc == 2) {
            int x;
            printf("Nhap x: ");
            scanf("%d", &x);
            insert_bot(&head, x);
        } else if (lc == 3) {
            int x, k;
            printf("Nhap x: ");
            scanf("%d", &x);
            printf("Nhap k: ");
            scanf("%d", &k);
            insert(&head, x, k);
        } else if (lc == 4) {
            duyet(head);
        } else if (lc == 5) {
            break;
        }
    }
    return 0;
}
