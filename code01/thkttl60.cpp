#include <stdio.h> 
void nhap(int A[], int n) {
	printf ("Nhap mang A gom %d phan tu: \n", n) ;
	for (int i = 0; i < n ; i++) {
		printf ("A[%d] = ", i);
		scanf ("%d", &A[i]);
	}
}
void xuat(int A[], int &n) {
	for (int i = 0; i < n; i++) {
		printf ("%d ", A[i]);
	}
	printf("\n");
}
void xuatmoi(int A[], int *n) {
	for(int i = 0; i < (*n-1) ;i++) { 
	A[i] = A[i+1];
	}
	(*n)--;
}
int main () {
	int n ;
	printf ("Nhap so luong phan tu cua mang (n>= 15): ");
	scanf ("%d", &n);
	while (n < 15) {
        printf("Vui long nhap so phan tu >= 15: ");
        scanf("%d", &n); 
    }
	int A[n];
	nhap(A,n);
	xuat(A,n);
	xuatmoi(A,&n); 
	xuat(A,n);
	return 0;
 
	
}
