#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T x) : data(x), next(NULL) {}
};

template <typename T>
class linklist {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    linklist();
    linklist(const linklist& l);
    ~linklist();

    linklist& operator=(const linklist& l);

    void clear();
    void chendau(T x);
    void chencuoi(T x);
    void chen(Node<T>* q, T x);

    void xoadau();
    void xoacuoi();
    void xoa(Node<T>* q);
    void xoadata(T x);

    Node<T>* search(T x);
    void sort(bool (*cmp)(T, T));

    T& operator[](int k);
    friend ostream& operator<<(ostream& out, const linklist<T>& l) {
        Node<T>* p = l.head;
        out << "[ ";
        while (p != NULL) {
            out << p->data;
            if (p->next != NULL) out << " -> ";
            p = p->next;
        }
        out << " ]";
        return out;
    }
};


template <typename T>
linklist<T>::linklist() {
    head = tail = NULL;
}

template <typename T>
linklist<T>::linklist(const linklist& l) {
    head = tail = NULL;
    Node<T>* p = l.head;
    while (p != NULL) {
        chencuoi(p->data);
        p = p->next;
    }
}

template <typename T>
linklist<T>::~linklist() {
    clear();
}

template <typename T>
linklist<T>& linklist<T>::operator=(const linklist& l) {
    if (this != &l) {
        clear();
        Node<T>* p = l.head;
        while (p != NULL) {
            chencuoi(p->data);
            p = p->next;
        }
    }
    return *this;
}

template <typename T>
void linklist<T>::clear() {
    Node<T>* p;
    while (head != NULL) {
        p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}

template <typename T>
void linklist<T>::chendau(T x) {
    Node<T>* p = new Node<T>(x);
    if (head == NULL) head = tail = p;
    else {
        p->next = head;
        head = p;
    }
}

template <typename T>
void linklist<T>::chencuoi(T x) {
    Node<T>* p = new Node<T>(x);
    if (head == NULL) head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
}

template <typename T>
void linklist<T>::chen(Node<T>* q, T x) {
    if (q == NULL) return;
    Node<T>* p = new Node<T>(x);
    p->next = q->next;
    q->next = p;
    if (q == tail) tail = p;
}

template <typename T>
void linklist<T>::xoadau() {
    if (head == NULL) return;
    Node<T>* p = head;
    head = head->next;
    delete p;
    if (head == NULL) tail = NULL;
}

template <typename T>
void linklist<T>::xoacuoi() {
    if (head == NULL) return;
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node<T>* p = head;
    while (p->next != tail) p = p->next;
    delete tail;
    tail = p;
    tail->next = NULL;
}

template <typename T>
void linklist<T>::xoa(Node<T>* q) {
    if (q == NULL || q->next == NULL) return;
    Node<T>* p = q->next;
    q->next = p->next;
    if (p == tail) tail = q;
    delete p;
}

template <typename T>
void linklist<T>::xoadata(T x) {
    if (head == NULL) return;
    if (head->data == x) {
        xoadau();
        return;
    }
    Node<T>* p = head;
    while (p->next != NULL && p->next->data != x) p = p->next;
    if (p->next != NULL) {
        Node<T>* tmp = p->next;
        p->next = tmp->next;
        if (tmp == tail) tail = p;
        delete tmp;
    }
}

template <typename T>
Node<T>* linklist<T>::search(T x) {
    Node<T>* p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

template <typename T>
void linklist<T>::sort(bool (*cmp)(T, T)) {
    if (head == NULL) return;
    for (Node<T>* p = head; p != NULL; p = p->next) {
        for (Node<T>* q = p->next; q != NULL; q = q->next) {
            if (cmp(q->data, p->data)) {
                T tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

template <typename T>
T& linklist<T>::operator[](int k) {
    Node<T>* p = head;
    int i = 0;
    while (p != NULL && i < k) {
        p = p->next;
        i++;
    }
    if (p == NULL) throw out_of_range("Vi tri khong hop le!");
    return p->data;
}

bool tang(int a, int b) { return a < b; }
bool giam(int a, int b) { return a > b; }

int main() {
    linklist<int> l;
    l.chencuoi(5);
    l.chencuoi(1);
    l.chencuoi(3);
    l.chendau(9);
    cout << "Danh sach l: " << l << endl;
    cout << "Chen 7 sau node dau tien\n";
    l.chen(l.search(9), 7);
    cout << l << endl;
    cout << "Xoa phan tu cuoi: ";
    l.xoacuoi();
    cout << l << endl;
    cout << "Xoa phan tu co gia tri 7: ";
    l.xoadata(7);
    cout << l << endl;
    cout << "Phan tu thu 1: " << l[1] << endl;
    cout << "Sap xep tang dan: ";
    l.sort(tang);
    cout << l << endl;
    cout << "Sap xep giam dan: ";
    l.sort(giam);
    cout << l << endl;
    Node<int>* found = l.search(5);
    cout << "Tim 5: " << (found ? "Co ton tai" : "Khong co") << endl;
    return 0;
}
