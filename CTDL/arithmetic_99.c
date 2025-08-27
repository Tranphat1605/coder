#include <stdio.h>
#include <limits.h>

#define EMPTY -1

struct StackInfo {
	unsigned int capacity;
	int top;
	int *stack_array;
};

typedef struct StackInfo *Stack;

Stack createStack(unsigned int capacity) {
	Stack S = malloc(sizeof(struct StackInfo));
	if (S == NULL)
		return NULL;
	S->capacity = capacity;
	S->stack_array = malloc(sizeof(int) * capacity);
	if (S->stack_array == NULL)
		return NULL;
	S->top = EMPTY;
}

int isFull(Stack S) {
	return S->top == S->capacity - 1;
}

int isEmpty(Stack S) {
	return S->top == EMPTY;
}

void push(Stack S, int e) {
	if (isFull(S))	{
		printf("The stack is full!\n");
		return;
	}
	S->top++;
	S->stack_array[S->top] = e;
}

int pop(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");
		return INT_MAX;
	}
	S->top--;
	return S->stack_array[S->top + 1];
}

int top(Stack S) {
	if (isEmpty(S)) {
		printf("The stack is empty!\n");
		return NULL;
	}	
	return S->stack_array[S->top];
} 

int main() {
	Stack S = createStack(100);
	char s[] = "1 2 3 * + 4 5 * 6 + 7 * +";	
	char *temp = strtok(s, " ");
	while (temp != NULL) {
		if (strcmp(temp, "+") == 0 || strcmp(temp, "-") == 0 || strcmp(temp, "*") == 0 || strcmp(temp, "/") == 0) {
			int temp1, temp2;
			temp1 = pop(S);
			temp2 = pop(S);
			if (strcmp(temp, "*") == 0) push(S, temp2 * temp1);
			else if (strcmp(temp, "-") == 0) push(S, temp2 - temp1);
			else if (strcmp(temp, "+") == 0) push(S, temp2 + temp1);
			else if (strcmp(temp, "/") == 0) push(S, temp2 / temp1);
		} else {
			push(S, atoi(temp));
		}
		temp = strtok(NULL, " ");
	}
	int result = pop(S);
	printf("%d\n", result) ;
	return 0;
}
