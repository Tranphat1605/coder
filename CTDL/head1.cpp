#include <iostream>

using namespace std;

typedef int elementtype;

typedef struct node {
    elementtype data;
}node;
typedef struct heap {
    unsigned int size;
    node *heap_arr;
}head;

void create_begin_heap(heap &h, node a[], unsigned int n) {
    h.size = n;
    h.heap_arr = a;
}

void init(heap &h) {
    h.size = 0;
    h.heap_arr = NULL;
}

unsigned int index_leftnode (unsigned int i) {
    return 2*i+1;
}
unsigned int index_rightnode (unsigned int i) {
    return 2*i+2;
}
unsigned int index_parent (unsigned int i) {
    return (i-1)/2;
}

void show(heap h, unsigned int i) {
    if (i >= 0 && i < h.size) {
        cout << h.heap_arr[i].data << " ";
        show(h, index_leftnode(i));
        show(h, index_rightnode(i));
    }
}

void show_m1c(node a[], unsigned int i) {

}

void show_all_subheap( heap h) {
    for (int i = 0; i < h.size/2; i++) {
        cout << h.heap_arr[i].data << " ";
        cout << endl << "Nhanh trai: ";
        show(h, index_leftnode(i));
        cout << endl << "Nhanh phai: ";
        show(h, index_rightnode(i));
    }
}

void exchange(node &a, node &b) {
    node temp = a;
    a = b;
    b = temp;
}

void max_heap(heap &h, unsigned int i) {
    unsigned int m = i, l, r;
    l = index_leftnode(i);
    r = index_rightnode(i);
    if (l < h.size && h.heap_arr[l].data > h.heap_arr[m].data) m = l;
    if (r < h.size && h.heap_arr[r].data > h.heap_arr[m].data) m = r;
    if (m != i) {
        exchange(h.heap_arr[i], h.heap_arr[m]);
        max_heap(h, m);
    }
}

void build_max_heap(heap h) {
    for (int i = h.size/2-1; i >= 0; i--) {
        max_heap(h, i);
    }
}

void heapsort_asc(heap h) {
    build_max_heap(h);
    for (int i = h.size-1; i >= 0; i--) {
        exchange(h.heap_arr[0], h.heap_arr[i]);
        max_heap(h, 0);
    }
}

void min_heap(heap h, unsigned int i) {
    unsigned int m = i, l, r;
    l = index_leftnode(i);
    r = index_rightnode(i);
    if (l < h.size && h.heap_arr[l].data < h.heap_arr[m].data) m = l;
    if (r < h.size && h.heap_arr[r].data < h.heap_arr[m].data) m = r;
    if (m != i) {
        exchange(h.heap_arr[i], h.heap_arr[m]);
        min_heap(h, m);
    }
}

void build_min_heap(heap h) {
    for (int i = h.size/2-1; i >= 0; i--) {
        min_heap(h, i);
    }
}

void insert_max_heap(head &h, elementtype x) {
    h.heap_arr[h.size].data = x;
    h.size++;
    int i = h.size-1;
    while (1) {
        i = index_parent(i);
        if (i < 0) break;
        max_heap(h, i);
        if (i == 0) {
            break;
        }
    }
}

void delete_max_heap(head &h, elementtype &x) {
    int i = 0;
    for (i = 0; i < h.size; i++) {
        if (h.heap_arr[i].data == x) break;
        }
    if (i < h.size) {
        h.heap_arr[i].data = INT_MIN;
        max_heap(h, i);
        for (i = h.size/2; i < h.size; i++) {
            if (h.heap_arr[i].data == INT_MAX)   /// còn một phần nữa 
        }
    }

}



int main () {
    node a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    heap h = {20, a};
    build_max_heap(h);
    show_all_subheap(h);
}