#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct ElementType {
	int id;
	char *name;
};

struct Node {
	struct ElementType e;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;

List create() {
	Position headerNode = malloc(sizeof(struct Node));
	if (headerNode == NULL)
		return NULL;
	headerNode->next = NULL;
	headerNode->prev = NULL;
	return headerNode;
}

int insert(List pL, struct ElementType e, Position p) {
	if (p == NULL)
		p = pL;
	Position newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
		return FALSE;
	
	newNode->e = e;
	newNode->next = p->next;
	newNode->prev = p;
	p->next = newNode;
	if (newNode->next != NULL)
		newNode->next->prev = newNode;
	return TRUE;
}

void show(List pL) {
	pL = pL->next;
	while (pL != NULL) {
		printf("ID: %d			Name: %s\n",pL->e.id, pL->e.name);
		pL = pL->next;
	}
}

Position findByID(List pL, int id) {
	pL = pL->next;
	while (pL != NULL && pL->e.id != id)
		pL = pL->next;
	return pL;
}

void del(List pL, Position p) {
	if (p == NULL)
		return;
	p->prev->next = p->next;
	if (p->next != NULL)
		p->next->prev = p->prev;
	free(p);
}

int main() {
	struct ElementType e1, e2, e3, e4;
	e1.id = 1; e1.name = "Nguyen Van A";
	e2.id = 2; e2.name = "Nguyen Van B";
	e3.id = 3; e3.name = "Nguyen Van C";
	e4.id = 4; e4.name = "Nguyen Van D";
	
	List stdList = create();
	if (stdList == NULL) {
		printf("Cannot create a list. Please try again later!");
		exit(0);
	}
	
	insert(stdList, e3, NULL);
	insert(stdList, e2, NULL);
	insert(stdList, e1, NULL);
	
	printf("The list is:\n");
	show(stdList);
	
	Position p = findByID(stdList, 2);
	insert(stdList, e4, p);
	
	printf("\nThe list is:\n");
	show(stdList);
	
	del(stdList, p);
	printf("\nThe list is:\n");
	show(stdList);
	
	return 0;
}

