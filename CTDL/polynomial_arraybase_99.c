#include <stdio.h>

#define MAX_SIZE 100

struct PolyInfo{
	int high_power;
	int coeff[MAX_SIZE + 1];
};

typedef struct PolyInfo *Polynomial;

Polynomial create() {
	Polynomial poly = malloc(sizeof(struct PolyInfo));
	poly->high_power = 0;
	for (int i = 0; i<= MAX_SIZE; i++)
		poly->coeff[i] = 0;
	return poly;
}

void show(Polynomial poly) {
	for (int i=poly->high_power;i>=0;i--){
		if (poly->coeff[i]==0)
			continue;
		if (poly->coeff[i]>0)
		{
			if (i!=poly->high_power)
				printf(" + ");
		} else {
			if (i!=poly->high_power)
				printf(" - ");
			else
				printf("-");
		}
		
		if (abs(poly->coeff[i])!=1 && i>0)
			printf("%d",abs(poly->coeff[i]));
		else if (i==0)
			printf("%d",abs(poly->coeff[i]));
			
		if (i!=0)
			printf("x");
		if (i>1)
			printf("^%d",i);		
	}
}

int max(int a, int b) {
	return a>b?a:b;
}

Polynomial add(Polynomial A, Polynomial B) {
	Polynomial C = create();
	C->high_power = max(A->high_power, B->high_power);
	for (int i = 0; i<= C->high_power; i++) {
		C->coeff[i] = A->coeff[i] + B->coeff[i];
	}
	return C;
}

Polynomial mult(Polynomial A, Polynomial B) {
	Polynomial C = create();
	C->high_power = A->high_power + B->high_power;	
	for (int i = 0; i <= A->high_power; i++)
		for (int j = 0; j<= B->high_power; j++)
			C->coeff[i + j] += A->coeff[i] * B->coeff[j];
	return C;
}

int main() {
	Polynomial A, B, C;
	int coeff_A[] = {-4, 2, 3};
	int coeff_B[] = {-1, 1, 3, 0, 0, 1};
	
	A = create();
	A->high_power = sizeof(coeff_A)/sizeof(coeff_A[0]) - 1;
	for (int i = 0; i<= A->high_power; i++)
		A->coeff[i] = coeff_A[i];
		
	B = create();
	B->high_power = sizeof(coeff_B)/sizeof(coeff_B[0]) - 1;
	for (int i = 0; i<= B->high_power; i++)
		B->coeff[i] = coeff_B[i];
		
	printf("A = ");
	show(A);
	printf("\nB = ");
	show(B);
	
	C = add(A, B);
	printf("\nC = ");
	show(C);
	
	C = mult(A, B);
	printf("\nC = ");
	show(C);
	
	return 0;
}