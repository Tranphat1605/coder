#include <iostream>
#include <stdio.h>

using namespace std;

struct element{
    string mssv;
    int diem;
    string xloai;
};

typedef struct node *list;
struct node {
    element data;
    node *next;
};

void init(list &l) {
    l = NULL;
}

void addnode(list &l, element x) {
    node *q, *p;
    q = new node;
    q->data = x;
    q->next = NULL;
    if (l == NULL) l = q;
    else {
        p = l;
        while (p->next != NULL) p = p->next;
        p->next = q;
    }
}

void insert_top(list &l, element x) {
    node *q, *p;
    q = new node;
    q->data = x;
    q->next = l;
    l = q;
}

// int search_p_node(list l, string mssv) {
//     if (l == NULL) return 0;
//     node *p = l;
//     do {
//         if (p->data.mssv == mssv) return 1;
//         p = p->next;
//     } while (p != l);
//     return 0;
// }

// int search_p(list l, string mssv) {
//     if (l == NULL) return 0;
//     node *p = l;
//     do {
//         if (p->data.mssv == mssv) return 1;
//         p = p->next;
//     } while (p != l);
//     return 0;
// }

node *search_return_p(list l, string mssv){
    node *q = l;
    while(q != NULL){
        if(q->data.mssv == mssv) return q;
        q = q->next;
    }
    return NULL;
}

node *search_return_p_node(list l, string mssv){
    node *q = l;
    while(q != NULL){
        if(strcmp(q->data.mssv, mssv) == 0) return q;
        q = q->next;
    }
    return NULL;
}

void show(list l) {
    node *p = l;
    do {
        cout << p->data.mssv << " " << p->data.diem << " " << p->data.xloai << endl;
        p = p->next;
    } while (p != l);
}


int main() {
    list l;
    init(l);
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        element x;
        cout << "Nhap MSSV: " << endl;
        cin >> x.mssv;
        cout << "Nhap diem: " << endl;
        cin >> x.diem;
        cout << "Nhap xep loai: " << endl;
        cin >> x.xloai;
        addnode(l, x);
    }
    x-masv="001"
160
x. xloai="gioi";
161
init(1);
162
addnode(1, x);
163
x.diem=8;
164
x-masv="002";
• 165
x. xloai="kha";
166
addnode (1, x);
167
show (1);
168
p=search _return_p(1,"001");
169
if(p!=NULL)
170

171
else cout«<"ko tim thay";
172
/*
for(int i=0;i<5;i+)
173
addnode（L,i+1）；
174
    show(l);
}