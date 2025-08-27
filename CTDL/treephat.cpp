#include <iostream>

using namespace std; 
typedef int elementtype;

struct node {
	elementtype data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
typedef struct node* tree;

void init (tree &t) {
	t = NULL;
} 

int emptyy(tree t) {
	return (t == NULL) ;
}

void tree_insert (tree &t, elementtype x) {
	if (t == NULL) {
		node *p = new node;
		p->data = x;
		p->left = p->right = NULL;
		t = p;
	}
	else {
		if (x < t->data) {
			tree_insert(t->left, x);
		}
		else if (x > t->data) {
			tree_insert(t->right, x);
		}
	}
}

void show_NLR(tree t) {  //in goc - trai - phai
	if (t != NULL) {
		cout << t->data << " " ;
		show_NLR(t->left);
		show_NLR(t->right);
	}
}

void show_NRL(tree t) {  // in goc - phai - trai
	if (t != NULL) {
		cout << t->data << " " ;
		show_NRL(t->right);
		show_NRL(t->left);
	}
}

void show_LNR(tree t ) {  // duyet tu be den lon 
	if (t != NULL) {
		show_LNR(t->left);
		cout << t->data << " " ;
		show_LNR(t->right);
	}
}

void show_RNL(tree t ) {  // duyet tu lon den be
	if (t != NULL) {
		show_RNL(t->right);
		cout << t->data << " " ;
		show_RNL(t->left);
	}
}

void delete_node(tree &t, elementtype x) {
	if (t == NULL) {
		cout << "Khong tim thay gia tri " << x << " de xoa.\n";
		return;
	}

	if (x < t->data) {
		delete_node(t->left, x);
	} else if (x > t->data) {
		delete_node(t->right, x);
	} else {
		// Đã tìm thấy node cần xóa
		if (t->left == NULL && t->right == NULL) {
			// Trường hợp 1: không có con
			delete t;
			t = NULL;
		} else if (t->left == NULL) {
			// Trường hợp 2a: chỉ có con phải
			node* tmp = t;
			t = t->right;
			delete tmp;
		} else if (t->right == NULL) {
			// Trường hợp 2b: chỉ có con trái
			node* tmp = t;
			t = t->left;
			delete tmp;
		} else {
			// Trường hợp 3: có 2 con
			// Tìm node nhỏ nhất bên phải (inorder successor)
			node* minRight = t->right;
			while (minRight->left != NULL) {
				minRight = minRight->left;
			}
			t->data = minRight->data; // thay giá trị node cần xóa
			delete_node(t->right, minRight->data); // xóa node thay thế
		}
	}
}

node *search(tree t, elementtype x) {
	if (t == NULL) {
		return NULL;
	}
	else {
		if (x < t->data) {
			return search(t->left, x);
		}
		else if (x > t->data) {
			return search(t->right, x);
		}
		else {
			return t;
		}
	}
}


int main () {
    tree t;
    init(t);
    tree_insert(t, 10);
    tree_insert(t, 5);
    tree_insert(t, 15);
    tree_insert(t, 3);
    tree_insert(t, 7);
    tree_insert(t, 12);
    tree_insert(t, 20);
    show_LNR(t);
	cout << endl;
	cout << search(t, 12)->data;
	return 0;
}




