#include <iostream> 
using namespace std;

struct node {
	int data;
	struct node *next;
};

typedef struct node* queue;

void init (queue &l) {
	l = NULL;
}

int emptyy(queue l) {
	return (l == NULL);
} 

void push(queue &l, int x) {
	node *p = new node;
	p->data = x;
	p->next = NULL;
	if (emptyy(l)) {
		l = p;
	} 
	node *q = l;
	while (q->next != NULL) {
		q = q->next;
	}
	q->next = p;
}

void pop(queue &l) {
	if (emptyy(l)) {
		cout << "Hang doi rong" << endl;
		return;
	}
	node *p = l;
	l = l->next;
	delete p;
}

int pop2(queue &l) {
	if (emptyy(l)) {
		cout << "Hang doi rong" << endl;
		return -1;
	}
	int x = l->data;
	node *p = l;
	l = l->next;
	delete p;
	return x;
}

node *search(queue l, int x) {
	if (emptyy(l)) {
		cout << "Hang doi rong" << endl;
		return NULL;
	}
	node *p = l;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
} 
 
void delete_node (queue &l, int x) {
	node *p = search(l, x);
	if (p == NULL) {
		cout << "Khong co node" << endl;
		return;
	}
	node *q = l;
	if (p == l) {
		pop(l);
		return;
	}
	while (q->next != p) {
		q = q->next;
	}
	q->next = p->next;
	delete p;
}

void delete_all(queue &l) {
	while (l != NULL) {
		node *p = l;
		l = l->next;
		delete p;
	}
}
