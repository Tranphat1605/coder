#include <iostream>
using namespace std;

typedef int elementtype;
const int MX = 10;

struct node {
    elementtype data[MX];
    int n;
    int maxsize;
};

typedef struct node queue;

// Khởi tạo hàng đợi
void init(queue &l) {
    l.n = 0;
    l.maxsize = MX;  // Khởi tạo maxsize
}

// Kiểm tra hàng đợi rỗng
int empty(const queue &l) {
    return l.n == 0;
}

// Kiểm tra hàng đợi đầy
int full(const queue &l) {
    return l.n == l.maxsize;
}

// Thêm phần tử vào hàng đợi
void push(queue &l, elementtype x) {
    if (full(l)) {
        cout << "Queue is full!\n";
        return;
    }
    l.data[l.n++] = x;
}

// Lấy phần tử đầu và xóa khỏi hàng đợi (FIFO)
elementtype pop(queue &l) {
    if (empty(l)) {
        cout << "Queue is empty!\n";
        return -1;  // Trả về giá trị báo lỗi
    }
    elementtype front = l.data[0];
    for (int i = 1; i < l.n; ++i) {
        l.data[i - 1] = l.data[i];  // Dịch các phần tử về đầu
    }
    l.n--;
    return front;
}

// Trả về phần tử đầu tiên (không xóa)
elementtype front(const queue &l) {
    if (empty(l)) {
        cout << "Queue is empty!\n";
        return -1;  // Trả về giá trị báo lỗi
    }
    return l.data[0];
}

// In toàn bộ các phần tử trong hàng đợi
void print(const queue &l) {
    if (empty(l)) {
        cout << "Queue is empty!\n";
        return;
    }
    for (int i = 0; i < l.n; ++i) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

// Hàm main để thử
int main() {
    queue q;
    init(q);

    push(q, 10);
    push(q, 20);
    push(q, 30);
    print(q);  // Output: 10 20 30

    cout << "Front: " << front(q) << endl;  // Output: 10

    cout << "Popped: " << pop(q) << endl;   // Output: 10
    print(q);  // Output: 20 30

    return 0;
}
