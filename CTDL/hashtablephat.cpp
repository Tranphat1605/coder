#include <iostream>
#include <climits>
using namespace std;

const int MX = 10;

struct node {
	int data; 
	struct node* next;
};

typedef struct node* list;
typedef list hashtable[MX];

void init (hashtable l) {
	for (int i = 0; i < MX; i++) {
		l[i] = NULL;
	}
} 

int empty_list (list l) {
	return l == NULL;
}

int key(int index) {
	return index % MX;
}

int empty_hash(hashtable h) {
	for (int i = 0; i < MX; i++) {
		if (h[i] != NULL) {
			return 0;
		}
	}
	return 1;
}

void show_list(list l) {
	if (empty_list(l)) {
		cout << "Line rong!" << endl;
		return;
	}
	while (l != NULL) {
		cout << l->data << " ";
		l = l->next;
	}
}

void show_hash(hashtable h) {
	if (empty_hash(h)) {
		cout << "Hash rong!" << " ";
		return;
	}
	for (int i = 0; i < MX; i++) {
		show_list(h[i]);
		cout << endl;
	}
}

void insert(hashtable h, int x) {
	int k = key(x);
	node *p = new node;
	p->data = x;
	p->next = NULL;
	if (h[k] == NULL) {
		h[k] = p;
		return;
	} 
	p->next = h[k];
	h[k] = p;
}

node *search_list (list l, int x) {
	node *p = l;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}


node *search_hash(hashtable h, int x) {
	int k = key(x);
	node *p = search_list(h[k], x);
	if (p != NULL) {
		return p;
	}
	return NULL;
}

int search_max_list(list l) {
	if (empty_list(l)) {
		cout << "Line rong" << endl;
		return INT_MIN;
	}
	node *p = l;
	int max = p->data;
	while (p != NULL) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int search_max_hash(hashtable h) {
	int max = search_max_list(h[0]);
	for (int i = 1; i < MX; i++) {
		int tmp = search_max_list(h[i]);
		if (max < tmp) {
			max = tmp;
		}
	}
	return max;
}

void delete_node_hash (hashtable h, int x) {
	int k = key(x);
	node *p = h[k];
	node *pre = NULL;
	while (p != NULL && p->data != x) {
		pre = p;
		p = p->next;
	}
	if (p == NULL) {
		cout << "Khong tim thay gia tri can!" << endl;
		return;
	}
	if (pre == NULL) {
		h[k] = p->next;
	} else {
		pre->next = p->next;
	}
	delete p; 
} 

void delete_all(hashtable h) {
	for (int i = 0; i < MX; i++) {
		node *p = h[i];
		while (p != NULL) {
			node *tmp = p;
			p = p->next;
			delete tmp;
		}
		h[i] = NULL;
	}
} 

int main () {
	hashtable h;
	init(h);
	insert(h, 10);
	insert(h, 20);
	insert(h, 30);
	insert(h, 40);
	insert(h, 50);
	show_hash(h);
	// delete_node_hash(h, 30);
	// show_hash(h);
	// delete_all(h);
	// show_hash(h);
	return 0;
}
