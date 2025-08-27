#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct ElementType {
	int ID;
	char *name;
};

struct Node {
	struct Node *next;
	struct ElementType e;
};

typedef struct Node *List;
typedef struct Node *Position;

int insert(List *pL, struct ElementType e, Position p) {
	Position newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
		return FALSE;
	newNode->e = e;
	
	if (*pL == NULL || p == NULL) {
		newNode->next = *pL;
		*pL = newNode;
	} else {
		newNode->next = p->next;
		p->next = newNode;
	}
	return TRUE;
}

Position findByID(List pL, int ID) {
	while (pL != NULL && pL->e.ID != ID)
		pL = pL->next;
	return pL;
}

void show(List pL) {
	while (pL != NULL) {
		printf("ID: %d			Name: %s\n", pL->e.ID, pL->e.name);
		pL = pL->next;
	}
}

int main() {
	List stdList = NULL;
	struct ElementType e1, e2, e3, e4;
	
	e1.ID = 1; e1.name = "Nguyen Van A";
	e2.ID = 2; e2.name = "Nguyen Van B";
	e3.ID = 3; e3.name = "Nguyen Van C";
	e4.ID = 4; e4.name = "Nguyen Van D";
	
	insert(&stdList, e3, NULL);
	insert(&stdList, e2, NULL);
	insert(&stdList, e1, NULL);
	
	printf("The list is:\n");
	show(stdList);
	
	Position p = findByID(stdList, 2);
	
	insert(&stdList, e4, p);
	printf("\nThe new list is:\n");
	show(stdList);
	
	return 0;
}




