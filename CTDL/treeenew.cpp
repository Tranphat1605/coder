#include <iostream> 

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* tree;

void init(tree &l) {
	l = NULL;
}

int emptyy (tree l) {
	return (l == NULL);
}

void insert_node(tree &l, int x) {
	if (l == NULL) {
		node *p = new node;
		p->data = x;
		p->right = p->left = NULL;
		l = p; 
		return;
	}
	if (x > l->data) {
		insert_node(l->right, x);
	}
	if (x < l->data) {
		insert_node(l->left, x);
	}	
}

void show_LNR (tree l) {
	if (l != NULL) {
		show_LNR(l->left);
		cout << l->data << " ";
		show_LNR(l->right);	
	}
}

void delete_node (tree &l, int x) {
	if (emptyy(l)) {
		cout << "khong tim thay node can xoa" << endl;
		return;
	} 
	if (x > l->data) {
		delete_node (l->right, x);
	} else if (x < l->data) {
		delete_node (l->left, x);
	} else {
		if (l->left == NULL && l->right == NULL) {
			delete l;
			l = NULL
		} else if (l->left == NULL) {
			node *tmp = l;
			l = l->right;
			delete tmp;
		} else if (l->right == NULL) {
			node *tmp = l;
			l = l->left;
			delete tmp;
		} else {
			node *mright = l->right;
			while (mright->left != NULL) {
				mright = mright->left;
			}
			l->data = mright->data;
			delete_node(l->right, mright->data);
		}
	}
}

void delete_node(tree &l, int x ) {
	if (emptyy(l)) {
		cout << "khong tim thay gia tri can xoa" << endl;
		return;
 	}
 	if (x > l->data) {
 		delete_node (l->right, x);
	} else if (x < l->data) {
		delete_node (l->left, x);
	} else {
		if (l->left == NULL && l->right == NULL) {
			delete l;
			l = NULL;
		} else if (l->left == NULL) {
			node *tmp = l;
			l = l->right;
			delete tmp;
		} else if (l->right == NULL) {
			node *tmp = l;
			l = l->left;
			delete tmp;
		} else {
			node *peren = l;
			node *mright = l->right;
			while (mright->left != NULL) {
				peren = mright;
				mright= mright->left;
			}
			l->data = mright->data;
			if (peren->left == mright) {
				delete_node(peren->left, mright->data);
			} else {
				delete_node(peren->right, mright->data);
			}
		}
	}
}
