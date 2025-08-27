#include <stdio.h>
#include <limits.h>

struct Node {
	int coeff;
	int exp;
	struct Node *next;
};

typedef struct Node *Polynomial;
typedef struct Node *Position;

Polynomial create() {
	Polynomial header = malloc(sizeof(struct Node));
	header->next = NULL;
	header->exp = INT_MAX;
	return header;
}

void insert(Polynomial poly, int coeff, int exp) {
	Position p = poly;
	while (p->next != NULL && p->next->exp >= exp)
		p = p->next;
	if (p->exp == exp) {
		p->coeff += coeff;		
	} else {
		Position newNode = malloc(sizeof(struct Node));
		newNode->coeff = coeff;
		newNode->exp = exp;
		newNode->next = p->next;
		p->next = newNode;
	}
}

Polynomial add(Polynomial A, Polynomial B) {
	Polynomial C = create();
	A = A->next;
	while (A != NULL) {
		insert(C, A->coeff, A->exp);
		A = A->next;
	}
	B = B->next;
	while (B != NULL) {
		insert(C, B->coeff, B->exp);
		B = B->next;
	}
	return C;
}

Polynomial mult(Polynomial A, Polynomial B) {
	Polynomial C = create();
	A = A->next;
	B = B->next;
	Position temp = B;
	while (A != NULL) {
		while (B != NULL) {
			insert(C, A->coeff * B->coeff, A->exp + B->exp);
			B = B->next;
		}
		A = A->next;
		B = temp;
	}
	return C;
}

void show(Polynomial poly) {
	poly = poly->next;
	Position firstNode = poly;
	while (poly!=NULL){
		if (poly->coeff == 0){
			poly = poly->next;
			continue;
		}
		
		if (poly->coeff < 0){
			if (poly!=firstNode)
				printf(" - ");
			else
				printf("-");
		} else {
			if (poly!=firstNode)
				printf(" + ");
		}
		if (abs(poly->coeff) != 1 || poly->exp == 0)
			printf("%d",abs(poly->coeff));
		if (poly->exp > 0)
			printf("x");
		if (poly->exp > 1)
			printf("^%d",poly->exp);		
		poly = poly->next;
	}
}

int main() {
	Polynomial A, B, C;
	
	A = create();
	insert(A, 3, 2);
	insert(A, 2, 1);
	insert(A, -4, 0);
	
	B = create();
	insert(B, 1, 5);
	insert(B, -3, 2);
	insert(B, 1, 0);
	
	printf("A = ");
	show(A);
	
	printf("\nB = ");
	show(B);
		
	C = add(A, B);
	printf("\nA + B = ");
	show(C);
	
	C = mult(A, B);
	printf("\nA x B = ");
	show(C);
		
	return 0;
}