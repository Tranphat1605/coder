#include <stdio.h>
#include <string.h>
void nhap(char A[][1000], int n)
{
    int i;
    char tam[1000];
    printf("Nhap mang A gom %d phan tu: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i+1);
        scanf("%s", &tam);
        strcpy(A[i],tam);
    }
}
void xuat(char A[][1000], int &n)
{
    int i;
    printf("Mang A: {"); 
    for (i = 0; i < n; i++) 
    {   
        printf("%s", A[i]); 
        if (i < n-1) 
        { 
            printf(", "); 
        } 
    } 
    printf("}\n");
}
void xuatmoi(char A[][1000], int *n)
{
    int i;
    for (i = 0; i < (*n - 1); i++)
    {
        strcpy(A[i],A[i+1]); 
    }
    (*n)--;
    printf("Mang A sau khi xoa phan tu dau tien:\n");
}
int main()
{
    int n;
    char A[1000][1000];
    do{
    printf("Nhap so luong phan tu cua mang (n>= 15): ");
    scanf("%d", &n);
    if (n < 15){
        printf("Vui long nhap n >= 15 \n");
    }
    } while(n < 15);
        nhap(A, n);
        xuat(A, n);
        xuatmoi(A, &n);
        xuat(A, n);
    return 0;
}
