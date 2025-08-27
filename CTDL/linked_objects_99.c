#include <stdio.h>

struct Symbol {
	char* name;
	unsigned long val;
};

struct Node {
	struct Node *next;
	struct Symbol *element;
};

struct Node *nodeA;
struct Node *nodeB;
struct Node *nodeC;

int main() {
	struct Symbol oneSym;
	struct Symbol twoSym;
	struct Symbol threeSym;
	
	oneSym.name = "one"; oneSym.val = 1;
	twoSym.name = "two"; twoSym.val = 2;
	threeSym.name = "three"; threeSym.val = 3;
	
	nodeA = malloc(sizeof(struct Node));
	nodeB = malloc(sizeof(struct Node));
	nodeC = malloc(sizeof(struct Node));
	
	nodeA->element = &oneSym;
	nodeA->next = nodeB;
	
	nodeB->element = &twoSym;
	nodeB->next = nodeC;
	
	nodeC->element = &threeSym;
	nodeC->next = NULL;
	
	struct Node *nodeP;
	nodeP = nodeA;
	while (nodeP!=NULL) {
		printf("Name: %s    Value: %lu\n",nodeP->element->name, nodeP->element->val);
		nodeP = nodeP->next;
	}
	
	return 0;
}