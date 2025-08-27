#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int ngay, thang, nam;
} NgayThang;

typedef struct {
    char msv[10];
    char ten[30];
    char gt[5];
    NgayThang date;
    char lop[10];
    float toan, triet, ltc;
    float dtb;
} SinhVien;

typedef SinhVien SV;

void nhap(SV *sv) {
    printf("\nNhap msv: ");
    scanf("%s", sv->msv);
    
    printf("Nhap ten: ");
    while (getchar() != '\n');  // Xóa b? ð?m
    fgets(sv->ten, sizeof(sv->ten), stdin);
    sv->ten[strcspn(sv->ten, "\n")] = 0; 

    printf("Nhap gioi tinh: ");
    fgets(sv->gt, sizeof(sv->gt), stdin);
    sv->gt[strcspn(sv->gt, "\n")] = 0;

    printf("Nhap ngay sinh (dd mm yyyy): "); 
    scanf("%d %d %d", &sv->date.ngay, &sv->date.thang, &sv->date.nam);

    printf("Sinh vien lop: ");
    scanf("%s", sv->lop);
    
    printf("Diem toan cao cap: ");
    scanf("%f", &sv->toan);
    
    printf("Diem triet: ");
    scanf("%f", &sv->triet);
    
    printf("Diem lap trinh C: ");
    scanf("%f", &sv->ltc);

    sv->dtb = 0; 
}

void nhapN(SV a[], int n) {
    printf("\n== NHAP THONG TIN SINH VIEN ==\n");
    for (int i = 0; i < n; ++i) {
        printf("\nNhap SV thu %d:", i + 1);
        nhap(&a[i]);
    }
    printf("\n____________________________________\n");
}

float tinhDTB(float a, float b, float c) {
    return (a + b + c) / 3;
}

void tinhDTBN(SV a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].dtb = tinhDTB(a[i].toan, a[i].triet, a[i].ltc);
    }
}

void in1sv(SV sv) {
    printf("|%-10s|%-25s|%02d/%02d/%04d\t|%-10.2f|\n", 
           sv.msv, sv.ten, sv.date.ngay, sv.date.thang, sv.date.nam, sv.dtb);
}

void insv(SV a[], int n) {
    printf("== XUAT DANH SACH SINH VIEN ==\n");
    for (int j = 0; j < 67; j++) { printf("-"); }
    printf("\n|%-10s|%-25s|%-15s |%-10s|\n", "Masv", "Ho ten", "Ngay sinh", "DTB");
    for (int j = 0; j < 67; j++) { printf("-"); }
    printf("\n");

    for (int j = 0; j < n; j++) {
        in1sv(a[j]);
    }

    for (int j = 0; j < 67; j++) { printf("-"); }
    printf("\n");
}

void sapxep(SV a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].dtb < a[j].dtb) { // S?p x?p gi?m d?n
                SV tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void xeploai(SV sv) {
    if (sv.dtb >= 8) 
        printf("Gioi");
    else if (sv.dtb >= 6.5) 
        printf("Kha");
    else if (sv.dtb >= 4) 
        printf("Trung binh");
    else 
        printf("Yeu");
}

void xeploaiN(SV a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\nXep loai cua SV %s la: ", a[i].ten);
        xeploai(a[i]);
    }
    printf("\n____________________________________\n");
}

void XuatFile(SV a[], int n, const char fileName[]) {
    FILE *fb = fopen(fileName, "w");
    if (fb == NULL) {
        printf("Loi mo file!\n");
        return;
    }

    fprintf(fb, "\n\t\t== DANH SACH SINH VIEN ==\n\n");
    fprintf(fb, "+-----------------------------------------------------+\n");
    fprintf(fb, "| %-10s | %-20s | %-10s | %-10s |\n", 
            "MSV", "Ho va ten", "Ngay sinh", "DTB");
    fprintf(fb, "+-----------------------------------------------------+\n");

    for (int i = 0; i < n; i++) {
        fprintf(fb, "| %-10s | %-20s | %02d/%02d/%04d | %-10.2f |\n", 
                a[i].msv, a[i].ten, a[i].date.ngay, a[i].date.thang, a[i].date.nam, a[i].dtb);
    }
    fprintf(fb, "+-----------------------------------------------------+\n");

    fclose(fb);
}

int main() {
    int n;
    char fileName[] = "DLSV.txt";
    SV a[MAX];

    printf("\nNhap so luong SV: ");
    scanf("%d", &n);

    nhapN(a, n);
    tinhDTBN(a, n);
    sapxep(a, n);
    insv(a, n);
    xeploaiN(a, n);
    XuatFile(a, n, fileName);

    return 0;
}

