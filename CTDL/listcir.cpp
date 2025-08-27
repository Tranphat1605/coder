 #include<stdio.h>
typedef int elementtype;
typedef struct node* list_db;
struct node {
    elementtype data;
    struct node* next;
};

void init(list_db &l) {
    l = NULL;
}

int Empty(list_db l) {
    return (l == NULL);
}

void show(list_db l) {
    if (Empty(l)) {
        printf("Ds rong!!!\n");
        return;
    }
    list_db p = l;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != l); // Trong danh sách vòng, điều kiện dừng là quay lại nút đầu
    printf("\n");
}

void addnode(list_db &l, elementtype x) {
    list_db q = new node;
    q->data = x;
    if (Empty(l)) {
        l = q;
        q->next = l; // Nút duy nhất trỏ về chính nó
    } else {
        list_db p = l;
        while (p->next != l) p = p->next; // Tìm nút cuối
        p->next = q;
        q->next = l; // Nút mới trỏ về nút đầu
    }
}

void insert_top(list_db &l, elementtype x) {
    node* q = new node;
    q->data = x;
    if (Empty(l)) {
        l = q;
        q->next = l; // Nút duy nhất trỏ về chính nó
    } else {
        list_db p = l;
        while (p->next != l) p = p->next; // Tìm nút cuối
        q->next = l; // Nút mới trỏ về nút đầu cũ
        p->next = q; // Nút cuối trỏ về nút mới
        l = q; // Cập nhật nút đầu
    }
}

node* search_x(list_db l, elementtype x) {
    if (Empty(l)) return 0;
    node* p = l;
    do {
        if (p->data == x) return p;
        p = p->next;
    } while (p != l);
    return NULL;
}

node* search_x_node(list_db l, node* x) {
    if (Empty(l)) return NULL;
    node* p = l;
    do {
        if (p == x) return p;
        p = p->next;
    } while (p != l);
    return NULL;
}

void delete_x(list_db &l, node* x) {
    if (Empty(l)) {
        printf("Danh sach rong!!!\n");
        return;
    }
    node* p = l;
    node* prev = NULL;
    do {
        if (p == x) break;
        prev = p;
        p = p->next;
    } while (p != l);

    if (p != x) {
        printf("Khong ton tai x!!!\n");
        return;
    }
    if (p == l && p->next == l) { // Chỉ có 1 nút
        l = NULL;
        delete p;
        return;
    }
    if (prev == NULL) { // Xóa nút đầu
        node* last = l;
        while (last->next != l) last = last->next;
        l = p->next;
        last->next = l;
    } else { // Xóa nút giữa hoặc cuối
        prev->next = p->next;
    }
    delete p;
}

node* node_max(list_db l, node* s) {
    if (Empty(l)) return NULL;
    node* p = l, *t = l;
    do {
        if (p->data > t->data) t = p;
        p = p->next;
    } while (p !=  s);
    return t;
}

elementtype data_max(list_db l, node* s) {
    node* p = node_max(l, s);
    return p->data;
}

void sort_list(list_db l) {
    if (Empty(l)) return;
    node* p = l;
    do p = p->next ; while (p != l);
    node* s = p;
    p = l;
    elementtype t;
    do {
        node* q = node_max(p,s);
        t = q->data;
        q->data = p->data;
        p->data = t;
        p = p->next;
    } while (p != l);
}

void insert_x(list_db l, elementtype x, node* a) {
    node* p = search_x_node(l, a);
    if (p == NULL) {
        printf("Khong tim thay node!!!\n");
        return;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void replace_x_y(list_db l, elementtype x, elementtype y){
    node* p;
    p = search_x(l, x);
    p->data = y ;
}
void replace_all_x_y(list_db l,elementtype  x, elementtype y) {
    list_db p = l;
    do {
        if( p->data == x) p->data = y;
        p = p->next;
    } while (p != l);
}
int main() {
    list_db l;
    init(l); // Khởi tạo danh sách rỗng

    // 1. Thêm các phần tử vào danh sách
    printf("Them cac phan tu vao danh sach:\n");
    addnode(l, 5);     // Thêm 5 vào cuối
    addnode(l, 3);     // Thêm 3 vào cuối
    insert_top(l, 7);  // Thêm 7 vào đầu
    insert_top(l, 5);  // Thêm 5 vào đầu
    addnode(l, 2);     // Thêm 2 vào cuối
    printf("Danh sach sau khi them: ");
    show(l); // Output: 5 7 5 3 2

    // 2. Kiểm tra danh sách rỗng
    printf("Kiem tra danh sach rong: %d\n", Empty(l)); // Output: 0 (không rỗng)

    // 3. Tìm kiếm phần tử
    elementtype x = 5;
    node* found = search_x(l, x);
    if (found) {
        printf("Tim thay %d trong danh sach\n", x); // Output: Tìm thấy 5
    } else {
        printf("Khong tim thay %d\n", x);
    }

    // 4. Tìm kiếm node
    node* some_node = l->next; // Lấy node thứ hai (giá trị 7)
    node* found_node = search_x_node(l, some_node);
    if (found_node) {
        printf("Tim thay node co gia tri %d\n", found_node->data); // Output: Tìm thấy node có giá trị 7
    } else {
        printf("Khong tim thay node\n");
    }

    // 5. Tìm node chứa giá trị lớn nhất
    node* max_node = node_max(l, l);
    if (max_node) {
        printf("Node co gia tri lon nhat: %d\n", max_node->data); // Output: 7
    }

    // 6. Tìm giá trị lớn nhất
    elementtype max_value = data_max(l, l);
    printf("Gia tri lon nhat: %d\n", max_value); // Output: 7

    // 7. Thay thế một phần tử x bằng y
    printf("Thay the mot phan tu 5 bang 10:\n");
    replace_x_y(l, 5, 10); // Thay thế phần tử 5 đầu tiên bằng 10
    printf("Danh sach sau khi thay the: ");
    show(l); // Output: 10 7 5 3 2

    // 8. Thay thế tất cả phần tử x bằng y
    printf("Thay the tat ca phan tu 5 bang 8:\n");
    replace_all_x_y(l, 5, 8); // Thay tất cả 5 bằng 8
    printf("Danh sach sau khi thay the tat ca: ");
    show(l); // Output: 10 7 8 3 2

    // 9. Chèn phần tử sau một node
    printf("Chen 6 sau node co gia tri 7:\n");
    node* node_to_insert_after = search_x(l, 7); // Tìm node có giá trị 7
    insert_x(l, 6, node_to_insert_after); // Chèn 6 sau node 7
    printf("Danh sach sau khi chen: ");
    show(l); // Output: 10 7 6 8 3 2

    // 10. Sắp xếp danh sách
    printf("Sap xep danh sach:\n");
    sort_list(l);
    printf("Danh sach sau khi sap xep: ");
    show(l); // Output: 10 8 7 6 3 2 (sắp xếp giảm dần)

    // 11. Xóa một node
    printf("Xoa node co gia tri 7:\n");
    node* node_to_delete = search_x(l, 7); // Tìm node có giá trị 7
    delete_x(l, node_to_delete); // Xóa node này
    printf("Danh sach sau khi xoa: ");
    show(l); // Output: 10 8 6 3 2

    // 12. Xóa danh sách để kiểm tra Empty
    printf("Xoa toan bo danh sach:\n");
    while (!Empty(l)) {
        delete_x(l, l); // Xóa node đầu liên tục
    }
    printf("Danh sach sau khi xoa het: ");
    show(l); // Output: Ds rong!!!
    printf("Kiem tra danh sach rong: %d\n", Empty(l)); // Output: 1 (rỗng)

    return 0;
}
