#include <iostream>
using namespace std;

struct element {
    string mssv;
    int diem;
    string xloai;
};

struct node {
    element data;
    node *next;
};

typedef node* list;

void init(list &l) {
    l = NULL;
}

void addnode(list &l, element x) {
    node *q = new node;
    q->data = x;
    q->next = NULL;
    if (l == NULL) {
        l = q;
    } else {
        node *p = l;
        while (p->next != NULL) p = p->next;
        p->next = q;
    }
}

node *search_return_p(list l, string mssv) {
    node *q = l;
    while (q != NULL) {
        if (q->data.mssv == mssv)
            return q;
        q = q->next;
    }
    return NULL;
}

void show(list l) {
    node *p = l;
    while (p != NULL) {
        cout << p->data.mssv << " " << p->data.diem << " " << p->data.xloai << endl;
        p = p->next;
    }
}

int main() {
    list l;
    init(l);
    
    // Thêm sinh viên 001
    element x;
    x.mssv = "001";
    x.diem = 9;
    x.xloai = "Gioi";
    addnode(l, x);

    // Thêm sinh viên 002
    x.mssv = "002";
    x.diem = 8;
    x.xloai = "Kha";
    addnode(l, x);

    // Hiển thị danh sách
    cout << "\nDanh sach sinh vien:\n";
    show(l);

    // Tìm sinh viên có MSSV = "001"
    node *p = search_return_p(l, "001");
    if (p != NULL) {
        cout << "\nTim thay sinh vien: " << p->data.mssv << " - " << p->data.diem << " - " << p->data.xloai << endl;
    } else {
        cout << "\nKhong tim thay sinh vien co MSSV = 001\n";
    }

    return 0;
}
