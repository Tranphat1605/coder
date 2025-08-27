#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void inMenu()
{
    system("cls");
    printf("==========Menu==========\n");
    printf("0. Thoat.\n");
    printf("1. Nhap ma tran.\n");
    printf("2. Tinh ma tran tong.\n");
    printf("3. Tinh ma tran tich.\n");
    printf("4. Tinh ma tran chuyen vi.\n");
    printf("5. Kiem tra ma tran doi xung.\n");
    printf("6. Hoan doi dong/cot.\n");
    printf("========================\n");
    printf("Nhap lua chon: ");
}
void choice(int* chon)
{
    printf("0. Thoat.\n");
    printf("1. Ma tran A.\n");
    printf("2. Ma tran B.\n");
    printf("Nhap lua chon: ");
    scanf("%d",chon);
    if(*chon<0||*chon>2)
    {
        printf("Lua chon khong hop le.\n");
        *chon=7;
    }
}
typedef struct
{
    int arr[20][20];
    int n;
}matran;
void docFile(matran *x)
{
    char filename[100];
    FILE *file;
    printf("Nhap ten file vao (co phan mo rong .txt): ");
    scanf("%s",filename);
    file=fopen(filename,"r");
    if(file==NULL)
    {
        printf("Khong the mo file.\n");
        return;
    }
    fscanf(file,"%d",&x->n);
    int i,j;
    for(i=0;i<x->n;++i)
        for(j=0;j<x->n;++j)
            fscanf(file,"%d",&x->arr[i][j]);
    fclose(file);
}
void nhapTay(matran *x)
{
    printf("Nhap bac cua ma tran: ");
    scanf("%d",&x->n);
    int i,j;
    for(i=0;i<x->n;++i)
        for(j=0;j<x->n;++j)
        {
            printf("Nhap phan tu a[%d][%d]: ",i+1,j+1);
            scanf("%d",&x->arr[i][j]);
        }
}
void nhapMaTran(matran *x)
{
    int chon;
    printf("Chon cach nhap ma tran:\n");
    printf("1. Nhap tu ban phim.\n");
    printf("2. Nhap tu file.\n");
    printf("Nhap lua chon: ");
    scanf("%d",&chon);
    switch (chon)
    {
        case 1:
            nhapTay(x);
            break;
        case 2:
            docFile(x);
            break;
        default:
            break;
    }
}
void xuatFile(matran x)
{
    char filename[100];
    FILE *file;
    printf("Nhap ten file ra (co phan mo rong .txt): ");
    scanf(" %s",filename);
    file=fopen(filename,"w");
    if(file==NULL)
    {
        printf("Khong the mo file.\n");
        return;
    }
    fprintf(file,"%d\n",x.n);
    int i,j;
    for(i=0;i<x.n;++i)
    {
        for(j=0;j<x.n;++j)
            fprintf(file,"%6d",x.arr[i][j]);
        fprintf(file,"\n");
    }
    fclose(file);
}
void xuatMaTran(matran x)
{
    if(x.n<1)
        return;
    int i,j;
    for(i=0;i<x.n;++i)
    {
        for(j=0;j<x.n;++j)
            printf("%6d",x.arr[i][j]);
        printf("\n");
    }
}
void luuMaTran(matran x)
{
    char chon;
    printf("Luu ma tran? (y/n) ");
    scanf(" %c",&chon);
    if(chon=='y')
        xuatFile(x);
    else
        printf("Khong luu ma tran.\n");
}
matran maTranTong(matran a, matran b)
{
    matran c;
    if(a.n!=b.n)
    {
        printf("Khong the cong hai ma tran.\n");
        c.n=0;
        return c;
    }
    c.n=a.n;
    int i,j;
    for(i=0;i<c.n;++i)
        for(j=0;j<c.n;++j)
            c.arr[i][j]=a.arr[i][j]+b.arr[i][j];
    printf("Ma tran tong:\n");
    xuatMaTran(c);
    luuMaTran(c);
    return c;
}
matran maTranTich(matran a, matran b)
{
    matran c;
    if(a.n!=b.n)
    {
        printf("Khong the nhan hai ma tran.\n");
        c.n=0;
        return c;
    }
    c.n=a.n;
    int i,j,k;
    for(i=0;i<c.n;++i)
    {
        for(j=0;j<c.n;++j)
        {
            c.arr[i][j]=0;
            for(k=0;k<c.n;++k)
                c.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
        }
    }
    printf("Ma tran tich:\n");
    xuatMaTran(c);
    luuMaTran(c);
    return c;
}
matran maTranChuyenVi(matran a)
{
    matran c;
    c.n=a.n;
    int i,j;
    for(i=0;i<c.n;++i)
        for(j=0;j<c.n;++j)
            c.arr[i][j]=a.arr[j][i];
    printf("Ma tran chuyen vi:\n");
    xuatMaTran(c);
    luuMaTran(c);
    return c;
}
int kiemTraDoiXung(matran a)
{
    int i,j;
    for(i=0;i<a.n;++i)
        for(j=0;j<i;++j)
            if(a.arr[i][j]!=a.arr[j][i])
                return 0;
    return 1;
}
matran hoanDoi(matran a)
{
    matran c;
    int chon,vt1,vt2,i;
    c.n=a.n;
    for(vt1=0;vt1<c.n;++vt1)
        for(vt2=0;vt2<c.n;++vt2)
            c.arr[vt1][vt2]=a.arr[vt1][vt2];
    printf("0. Thoat.\n");
    printf("1. Hoan doi dong.\n");
    printf("2. Hoan doi cot.\n");
    printf("Nhap lua chon: ");
    scanf("%d",&chon);
    switch (chon)
    {
        case 1:
        {
            printf("Nhap vi tri dong thu nhat: ");
            scanf("%d",&vt1);
            printf("Nhap vi tri dong thu hai: ");
            scanf("%d",&vt2);
            for(i=0;i<c.n;++i)
            {
                int tmp=a.arr[vt1][i];
                a.arr[vt1][i]=a.arr[vt2][i];
                a.arr[vt2][i]=tmp;
            }
            break;
        }
        case 2:
        {
            printf("Nhap vi tri cot thu nhat: ");
            scanf("%d",&vt1);
            printf("Nhap vi tri cot thu hai: ");
            scanf("%d",&vt2);
            for(i=0;i<c.n;++i)
            {
                int tmp=a.arr[i][vt1];
                a.arr[i][vt1]=a.arr[i][vt2];
                a.arr[i][vt2]=tmp;
            }
            break;
        }
        default:
            break;
    }
    printf("Ma tran sau khi hoan doi:\n");
    xuatMaTran(c);
    luuMaTran(c);
    return c;
}
int main()
{
    matran a,b;
    int chon;
    do
    {
        inMenu();
        scanf("%d",&chon);
        switch (chon)
        {
        case 1:
        {
            system("cls");
            printf("Chon ma tran can nhap:\n");
            choice(&chon);
            switch (chon)
            {
                case 1:
                {
                    nhapMaTran(&a);
                    printf("Ma tran A:\n");
                    xuatMaTran(a);
                    break;
                }
                case 2:
                {
                    nhapMaTran(&b);
                    printf("Ma tran B:\n");
                    xuatMaTran(b);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:
        {
            matran c=maTranTong(a,b);
            break;
        }
        case 3:
        {
            matran c=maTranTich(a,b);
            break;
        }
        case 4:
        {
            printf("Chon ma tran can tinh chuyen vi:\n");
            choice(&chon);
            switch (chon)
            {
                case 1:
                {
                    matran c=maTranChuyenVi(a);
                    break;
                }
                case 2:
                {
                    matran c=maTranChuyenVi(b);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 5:
        {
            printf("Chon ma tran can kiem tra doi xung:\n");
            choice(&chon);
            switch (chon)
            {
                case 1:
                {
                    if(kiemTraDoiXung(a))
                        printf("Ma tran A doi xung.\n");
                    else
                        printf("Ma tran A khong doi xung.\n");
                    break;
                }
                case 2:
                {
                    if(kiemTraDoiXung(b))
                        printf("Ma tran B doi xung.\n");
                    else
                        printf("Ma tran B khong doi xung.\n");
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 6:
        {
            printf("Chon ma tran can hoan doi dong/cot:\n");
            choice(&chon);
            switch (chon)
            {
                case 1:
                {
                    matran c=hoanDoi(a);
                    break;
                }
                case 2:
                {
                    matran c=hoanDoi(b);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 0:
        {
            printf("Ket thuc chuong trinh.\n");
            break;
        }        
        default:
            break;
        }
        if(chon>0)
        {
            printf("Nhan phim bat ky de tiep tuc.\n");
            getch();
        }
    }while(chon!=0);
    return 0;
}