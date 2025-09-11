#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkList {
private:
    Node *head, *tail;
    void copyList(const LinkList &l);
public:
    LinkList();
    ~LinkList();
    LinkList(const LinkList &l);
    void insertFront(int x);
    void insertBack(int x);
    void insertAfter(int y, int x);
    void deleteFront();
    void deleteBack();
    void deleteAfter(int y);
    void insertValue(int x);
    void deleteValue(int x);
    void sort(bool asc = true);
    friend ostream& operator<<(ostream &out, const LinkList &l);
};

LinkList::LinkList() {
    head = tail = NULL;
}

LinkList::~LinkList() {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = NULL;
}

void LinkList::copyList(const LinkList &l) {
    Node *cur = l.head;
    while (cur) {
        insertBack(cur->data);
        cur = cur->next;
    }
}

LinkList::LinkList(const LinkList &l) {
    head = tail = NULL;
    copyList(l);
}

void LinkList::insertFront(int x) {
    Node *p = new Node{x, NULL};
    if (!head) head = tail = p;
    else {
        p->next = head;
        head = p;
    }
}

void LinkList::insertBack(int x) {
    Node *p = new Node{x, NULL};
    if (!head) head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

void LinkList::insertAfter(int y, int x) {
    Node *cur = head;
    while (cur && cur->data != y) cur = cur->next;
    if (cur) {
        Node *p = new Node{x, cur->next};
        cur->next = p;
        if (cur == tail) tail = p;
    }
}

void LinkList::deleteFront() {
    if (!head) return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
    if (!head) tail = NULL;
}

void LinkList::deleteBack() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node *cur = head;
    while (cur->next != tail) cur = cur->next;
    delete tail;
    tail = cur;
    tail->next = NULL;
}

void LinkList::deleteAfter(int y) {
    Node *cur = head;
    while (cur && cur->data != y) cur = cur->next;
    if (cur && cur->next) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        if (tmp == tail) tail = cur;
        delete tmp;
    }
}

void LinkList::insertValue(int x) {
    Node *cur = head;
    while (cur) {
        if (cur->data == x) return;
        cur = cur->next;
    }
    insertBack(x);
}

void LinkList::deleteValue(int x) {
    if (!head) return;
    if (head->data == x) {
        deleteFront();
        return;
    }
    Node *cur = head;
    while (cur->next && cur->next->data != x) cur = cur->next;
    if (cur->next) {
        Node *tmp = cur->next;
        cur->next = tmp->next;
        if (tmp == tail) tail = cur;
        delete tmp;
    }
}

void LinkList::sort(bool asc) {
    for (Node *i = head; i; i = i->next) {
        for (Node *j = i->next; j; j = j->next) {
            if (asc ? i->data > j->data : i->data < j->data) {
                swap(i->data, j->data);
            }
        }
    }
}

ostream& operator<<(ostream &out, const LinkList &l) {
    Node *cur = l.head;
    while (cur) {
        out << cur->data << " ";
        cur = cur->next;
    }
    return out;
}

int main() {
    LinkList L;
    L.insertBack(5);
    L.insertBack(2);
    L.insertFront(10);
    L.insertAfter(5, 7);
    cout << "Danh sach ban dau: " << L << endl;
    L.deleteFront();
    cout << "Xoa dau: " << L << endl;
    L.deleteBack();
    cout << "Xoa cuoi: " << L << endl;
    L.insertValue(8);
    cout << "Them gia tri 8: " << L << endl;
    L.deleteValue(5);
    cout << "Xoa gia tri 5: " << L << endl;
    L.sort(true);
    cout << "Sap xep tang: " << L << endl;
    L.sort(false);
    cout << "Sap xep giam: " << L << endl;
    return 0;
}
