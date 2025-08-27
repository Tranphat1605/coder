#include <iostream> 

using namespace std;

typedef int elementtype;

struct node {
	elementtype data;
	node *next;
};

typedef struct node *queue;

void init (queue &l) {
	l = NULL;
} 

int emptyy(queue l) {
	return (l == NULL);
}

void push(queue &l, elementtype x) {
	node *p = new node;
	p->data = x; 
	p->next = NULL;
	if (emptyy(l)) {
		l = p;
	} else {
		node *q = l;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
	}
}

void pop(queue &l) {
	if (emptyy(l)) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	node *p = l;
	l = l->next;
	delete p;
}
 
elementtype peek(queue l) {
	if (emptyy(l)) {
		cout << "Hang doi rong:" << endl;
		return 0;
	}
	return l->data;
} 

elementtype rear(queue l) {
	if (emptyy(l)) {
		cout << "Hang doi rong!" << endl;
		return 0;
	}
	queue p = l;
	if (l->next == NULL) {
		return l->data;
	} else {
		while (p->next != NULL ) {
			p = p->next;
		}
		return p->data;
	}
	return 0;
}
