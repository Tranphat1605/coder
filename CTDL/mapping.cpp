#include <iostream>
using namespace std;

const int MX = 10;
typedef int elementtype;
typedef struct node* list;
typedef list hashtable[MX];

struct node {
    elementtype data;
    struct node* next;
};

// Khởi tạo bảng băm rỗng
void initHash(hashtable h) {
    for (int i = 0; i < MX; ++i)
        h[i] = NULL;
}

// Hàm băm
int key(elementtype x) {
    return x % MX;
}

// Thêm phần tử vào bảng băm
void addnode1(hashtable h, elementtype x) {
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;

    int k = key(x); // chỉ số băm
    node *p = h[k];

    if (p == NULL) {
        h[k] = tmp;
        return;
    }

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = tmp;
}

int emptyy(hashtable h){
    for(int i = 0; i < MX; i++){
        if(h[i] != NULL) return 0;
    }
    return 1;
}

int emptyy1(list l){
    if(l == NULL) return 1;
    return 0;
}
void addnode2(list &l, elementtype x) {
    node *p, *q;
    p = new node;
    p->data = x;
    p->next = NULL;
    if (emptyy1(l)) l = p;
    else {
        q = l;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

void showlist(list l) {
    node *p = l;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

void showhash(hashtable h) {
    for (int i = 0; i < MX; i++) {
        cout << "[" << i << "]: ";
        showlist(h[i]);
        cout << endl;
    }
}

int sreach(list l, elementtype x) {
    node *q = l;
    while (q != NULL) {
        if (q->data == x) return 1;
        q = q->next;
    }
    return 0;
}

int search_hash(hashtable h, elementtype x) {
    int i = key(x);
    if (i >= 0 && i < MX) {
        return sreach(h[i], x);
    }
}

node *search_return_p(list l, elementtype x) {
    node *q = l;
    while (q != NULL) {
        if (q->data == x) return q;
        q = q->next;
    }
    return NULL;
}

node *pseach_return_p(hashtable h, elementtype x) {
    int i = key(x);
    if (i >= 0 && i < MX) {
        return search_return_p(h[i], x);
    }
}


// Xóa phần tử khỏi bảng băm
void remove(hashtable h, elementtype x) {
    int k = key(x);
    node *p = h[k], *prev = NULL;

    while (p != NULL && p->data != x) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) return; // Không tìm thấy

    if (prev == NULL) {
        h[k] = p->next;
    } else {
        prev->next = p->next;
    }
    delete p;
}

node* search_max_list(list l) {
    if (l == NULL) return NULL;
    node* maxNode = l;
    node* p = l->next;
    while (p != NULL) {
        if (p->data > maxNode->data) {
            maxNode = p;
        }
        p = p->next;
    }
    return maxNode;
}

node* search_max_hash(hashtable h) {
    for (int i = 0; i < MX; i++) {
        if (h[i] != NULL) {
            return search_max_list(h[i]);
        }
    }
    return NULL;
} 

void max_hash(hashtable h, int n, elementtype x) {   // xem lai ham nay 
    int stop = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] != NULL) {
            node *m = search_max_list(h[i]);
            stop = 1;
            break;
        }
        if (!stop) {
            cout << endl << "Khong co phan tu nao trong bang bam" << endl;
        }
        else {
            for (int j = i; j < n; j++) {
                if (h[j] != NULL) {
                    node *t= search_max_list(h[j]);
                    if (t->data > m->data) m = t;
                }
            }
        }
    }
}


int main() {
    hashtable h;
    initHash(h);
    addnode1(h, 1);
    addnode1(h, 2);
    addnode1(h, 3);
    addnode2(h[3], 10);
    showlist(h[3]);
    // cout << endl;
    // addnode1(h, 4);
    // cout << endl;
    // showhash(h);
    // remove(h, 1);
    // showhash(h);
}
