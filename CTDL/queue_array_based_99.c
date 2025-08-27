#include <stdio.h>

struct ElementType {
	int value;
};

struct QueueInfo {
	unsigned int capacity;
	unsigned int count;
	unsigned int front;
	unsigned int rear;
	struct ElementType *queue_array;
};

typedef struct QueueInfo *Queue;

Queue create(unsigned int capacity) {
	Queue Q = malloc(sizeof(struct QueueInfo));
	if (Q == NULL)
		return NULL;
	Q->queue_array = malloc(sizeof(struct ElementType) * capacity);
	if (Q->queue_array == NULL)
		return NULL;
	Q->capacity = capacity;
	Q->count = 0;
	Q->front = 1;
	Q->rear = 0;	
}

int isEmpty(Queue Q) {
	return Q->count == 0;
}

int isFull(Queue Q) {
	return Q->count == Q->capacity;
}

int increase(unsigned int value, Queue Q) {	
	if (++value == Q->capacity) 
		value = 0;
	return value;
}

void enqueue(Queue Q, struct ElementType e) {
	if (isFull(Q)) {
		printf("The queue is full already!\n");
		return;
	}
	Q->rear = increase(Q->rear, Q);
	Q->queue_array[Q->rear] = e;
	Q->count++;	
}

struct ElementType* dequeue(Queue Q) {
	if (isEmpty(Q)) {
		printf("The queue is empty already!\n");
		return NULL;		
	}
	unsigned int temp = Q->front;
	Q->front = increase(Q->front, Q);
	Q->count--;
	return &Q->queue_array[temp];
}

int main() {
	struct ElementType e1, e2, e3 ,e4;
	e1.value = 2; e2.value = 4; e3.value = 1; e4.value = 3;
	Queue Q = create(100);
	enqueue(Q, e1);
	enqueue(Q, e2);
	enqueue(Q, e3);
	enqueue(Q, e4);
	while (!isEmpty(Q)) 
		printf("Value = %d\n",dequeue(Q)->value);
	return 0;
}
