#include <iostream>
using namespace std;

#ifndef hashtable_h
#define hashtable_h

#define DEFAULT_BUCKETS 101   // số bucket (nên là số nguyên tố)

struct dlnode {
    int key;
    int value;
    dlnode *prev;
    dlnode *next;
    dlnode(int k=0, int v=0): key(k), value(v), prev(NULL), next(NULL) {}
};

class hashtable {
private:
    dlnode **bucket;   // mảng con trỏ tới head của từng danh sách đôi
    int M;             // số bucket
    int n;             // số phần tử đang có

    int hashfunc(int k) const {
        // băm đơn giản cho int
        if (k < 0) k = -k;
        return k % M;
    }

public:
    hashtable(int buckets = DEFAULT_BUCKETS);
    ~hashtable();

    bool empty() const;
    int  size()  const;

    void clear();                  // xóa toàn bộ
    void insert(int k, int v);     // thêm mới hoặc cập nhật
    bool find(int k, int &out_v);  // tìm, ghi ra out_v nếu thấy
    bool erase(int k);             // xóa theo key

    void show();                   // in ra toàn bộ bảng băm
};

#endif // hashtable_h

// ================== IMPLEMENTATION ==================

hashtable::hashtable(int buckets) {
    if (buckets <= 0) buckets = DEFAULT_BUCKETS;
    M = buckets;
    n = 0;
    bucket = new dlnode*[M];
    for (int i = 0; i < M; i++) bucket[i] = NULL;
}

hashtable::~hashtable() {
    clear();
    delete[] bucket;
}

bool hashtable::empty() const { return n == 0; }
int  hashtable::size()  const { return n; }

void hashtable::clear() {
    for (int i = 0; i < M; i++) {
        dlnode *p = bucket[i];
        while (p != NULL) {
            dlnode *tmp = p;
            p = p->next;
            delete tmp;
        }
        bucket[i] = NULL;
    }
    n = 0;
}

void hashtable::insert(int k, int v) {
    int idx = hashfunc(k);
    // tìm xem đã có key chưa -> cập nhật
    for (dlnode *p = bucket[idx]; p != NULL; p = p->next) {
        if (p->key == k) {
            p->value = v;
            return;
        }
    }
    // chèn đầu danh sách đôi
    dlnode *node = new dlnode(k, v);
    node->next = bucket[idx];
    node->prev = NULL;
    if (bucket[idx] != NULL) bucket[idx]->prev = node;
    bucket[idx] = node;
    n++;
}

bool hashtable::find(int k, int &out_v) {
    int idx = hashfunc(k);
    for (dlnode *p = bucket[idx]; p != NULL; p = p->next) {
        if (p->key == k) {
            out_v = p->value;
            return true;
        }
    }
    return false;
}

bool hashtable::erase(int k) {
    int idx = hashfunc(k);
    dlnode *p = bucket[idx];
    while (p != NULL && p->key != k) p = p->next;
    if (p == NULL) return false; // không tìm thấy

    // gỡ p khỏi DLL
    if (p->prev == NULL) {
        // p là head
        bucket[idx] = p->next;
        if (p->next) p->next->prev = NULL;
    } else {
        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
    }
    delete p;
    n--;
    return true;
}

void hashtable::show() {
    if (empty()) {
        cout << "Hash rong!\n";
        return;
    }
    for (int i = 0; i < M; i++) {
        cout << "[" << i << "]: ";
        dlnode *p = bucket[i];
        if (p == NULL) { cout << "(empty)"; }
        while (p != NULL) {
            cout << "<" << p->key << "," << p->value << "> ";
            p = p->next;
        }
        cout << "\n";
    }
}
