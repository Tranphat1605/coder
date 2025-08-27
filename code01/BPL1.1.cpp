#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAT_TU 100

typedef struct {
    char ma_vat_tu[10];
    char ten_vat_tu[50];
    char loai_vat_tu[20];
    char don_vi_tinh[10];
    char ngay_nhap[12];
    char nha_san_xuat[50];
    int so_luong;
    float don_gia;
    float thanh_tien;
} VatTu;

void tinhThanhTien(VatTu *vt) {
    float giam = 0;
    if (vt->so_luong > 200) {
        giam = 0.25;
    } else if (vt->so_luong > 100) {
        giam = 0.10;
    }
    vt->thanh_tien = vt->so_luong * vt->don_gia * (1 - giam);
}

void nhapDanhSach(VatTu ds[], int *n) {
    printf("Nhap so luong vat tu: ");
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin vat tu %d:\n", i + 1);
        printf("Ma vat tu: "); scanf("%s", ds[i].ma_vat_tu);
        printf("Ten vat tu: "); scanf(" %[^\n]", ds[i].ten_vat_tu);
        printf("Loai vat tu: "); scanf(" %[^\n]", ds[i].loai_vat_tu);
        printf("Don vi tinh: "); scanf("%s", ds[i].don_vi_tinh);
        printf("Ngay nhap (dd/mm/yyyy): "); scanf("%s", ds[i].ngay_nhap);
        printf("Nha san xuat: "); scanf(" %[^\n]", ds[i].nha_san_xuat);
        printf("So luong: "); scanf("%d", &ds[i].so_luong);
        printf("Don gia: "); scanf("%f", &ds[i].don_gia);

        tinhThanhTien(&ds[i]);
    }
}

void xoaVatTu(VatTu ds[], int *n) {
    int i = 0;
    while (i < *n) {
        if (ds[i].so_luong > 100) {
            for (int j = i; j < *n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            (*n)--;
        } else {
            i++;
        }
    }
}

void thongKeTheoLoai(VatTu ds[], int n) {
    printf("\nBang thong ke theo loai vat tu:\n");
    printf("%-20s %-10s %-10s\n", "Loai vat tu", "So luong", "Tong tien");
    
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f\n", ds[i].loai_vat_tu, ds[i].so_luong, ds[i].thanh_tien);
    }
}

void inDanhSach(VatTu ds[], int n) {
    printf("\nDanh sach vat tu:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n", 
        "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    
    for (int i = 0; i < n; i++) {
        printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10d %-10.2f %-10.2f\n",
            ds[i].ma_vat_tu, ds[i].ten_vat_tu, ds[i].loai_vat_tu, ds[i].don_vi_tinh,
            ds[i].ngay_nhap, ds[i].nha_san_xuat, ds[i].so_luong, ds[i].don_gia, ds[i].thanh_tien);
    }
}

int main() {
    VatTu danhSach[MAX_VAT_TU];
    int n;
    
    nhapDanhSach(danhSach, &n);
    xoaVatTu(danhSach, &n);
    inDanhSach(danhSach, n);
    thongKeTheoLoai(danhSach, n);

    return 0;
}

