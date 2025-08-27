#include <stdio.h>

#define EMPTY -1

struct ElementType {
	int id;
	char *name;
};

struct StackInfo {
	unsigned int capacity;
	int top;
	struct ElementType *stack_array;
};

typedef struct StackInfo *Stack;

Stack createStack(unsigned int capacity) {
	Stack S = malloc(sizeof(struct StackInfo));
	if (S == NULL)
		return NULL;
	S->stack_array = malloc(sizeof(struct ElementType) * capacity);
	if (S->stack_array == NULL)
		return NULL;
	S->capacity = capacity;
	S->top = EMPTY;
	return S;
}

int isFull(Stack S) {
	return S->capacity == S->top + 1;
}

int isEmpty(Stack S) {
	return S->top == EMPTY;
}

void push(Stack S, struct ElementType e) {
	if (isFull(S)) {
		printf("The stack is full!\n");
		return;
	}
	S->top++;
	S->stack_array[S->top] = e;	
}

struct ElementType* pop(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");		
		return NULL;
	}
	S->top--;
	return &S->stack_array[S->top + 1];
}

struct ElementType* top(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");		
		return NULL;
	}
	return &S->stack_array[S->top];
}

int main() {
	Stack S = createStack(100);
	struct ElementType *e, e1, e2, e3;
	e1.id = 1; e1.name = "Nguyen Van A";
	e2.id = 2; e2.name = "Nguyen Van B";
	e3.id = 3; e3.name = "Nguyen Van C";
	
	push(S,e1);
	push(S,e2);
	push(S,e3);
	
	e = pop(S);
	printf("Id: %d 				Name: %s\n",e->id, e->name);
	e = pop(S);
	printf("Id: %d 				Name: %s\n",e->id, e->name);
	e = pop(S);
	printf("Id: %d 				Name: %s\n",e->id, e->name);
	e = pop(S);	
	return 0;
}

