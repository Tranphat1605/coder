#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMPTY -1

struct stack_info{
	int capacity;
	int top;
	char *data;
};

typedef struct stack_info *stack;

stack create(int capacity){
	stack newStack = malloc(sizeof(struct stack_info));
	if (newStack == NULL) return NULL;
	newStack->capacity = capacity;
	newStack->top = -1;
	newStack->data = malloc(capacity * sizeof(int));
	return newStack;
}

int isFull(stack s){
	return s->top == s->capacity - 1;
}

void push(stack s, char op){
	if (isFull(s)){
		printf("Stack is full already!");
		return;
	}
	s->top++;
	s->data[s->top] = op;
}

int isEmpty(stack s){
	return s->top == EMPTY;
}

char top(stack s){
	if(isEmpty(s)) return EMPTY;
	return s->data[s->top];
}

int pop(stack s){
	if (isEmpty(s)) return EMPTY;
	s->top--;
	return s->data[s->top + 1];
}

int main(){
	stack st = create(100);
	char c[] = "1+2*3+(4*5+6)*7";
	char kq[100];
	int pri[256];
	pri['*'] = 2;
	pri['/'] = 2;
	pri['+'] = 1;
	pri['-'] = 1;
	pri['('] = 0;
	pri[')'] = 0;
	int cnt = 0;
	int len = strlen(c);
	for(int i = 0; i < len; i++){
		if(c[i] == '(')
			push(st, c[i]);
		else if(c[i] == ')'){
			while(!isEmpty(st) && top(st) != '(')
				kq[cnt++] = pop(st);			
			if(!isEmpty(st)) pop(st);
		}
		else if(isdigit(c[i]))
			kq[cnt++] = c[i];
		else{
			while(!isEmpty(st) && top(st) != '(' && pri[top(st)] >= pri[c[i]]){
				kq[cnt++] = pop(st);
			}
			push(st, c[i]);
		}
	}
	while(!isEmpty(st)){
		kq[cnt++] = pop(st);
	}
	kq[cnt] = '\0';
	int size = strlen(kq);
	for(int i = 0; i < size; i++){
		printf("%c", kq[i]);
	}
	return 0;
}