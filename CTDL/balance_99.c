#include <stdio.h>

#define EMPTY -1

struct ElementType {	
	char c;
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
	char *stat = "(i + 5*[(17 – j/(6*k))])";
	int n = strlen(stat);
	for (int i = 0; i < n; i++) {
		if (stat[i] == '(' || stat[i] == '[') {
			struct ElementType e;
			e.c = stat[i];
			push(S, e);
		} else if (stat[i] == ')' || stat[i] == ']') {
			if (isEmpty(S)) {
				printf("Unbalanced!");
				return 0;
			} else if (stat[i] == ')' && top(S)->c == '(' || stat[i] == ']' && top(S)->c == '[')
				pop(S);
			else {
				printf("Unbalanced!");
				return 0;
			}
		}
	}
	if (isEmpty(S))
		printf("Balanced!");
	else
		printf("Unbalanced!");
	return 0;
}

