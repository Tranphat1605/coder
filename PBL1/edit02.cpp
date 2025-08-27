#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAT_TU 100

typedef struct {
    int ngay, thang, nam;
} date;

void nhapNgay(date* a) {
    int hopLe = 0;
    while (!hopLe) {
        printf("Nhap ngay (dd mm yyyy): ");
        scanf("%d %d %d", &a->ngay, &a->thang, &a->nam);

        if (a->ngay < 1 || a->ngay > 31 || a->thang < 1 || a->thang > 12 || a->nam < 1) {
            printf("Ngay khong hop le. Nhap lai!\n");
            continue;
        }

        if ((a->thang == 4 || a->thang == 6 || a->thang == 9 || a->thang == 11) && a->ngay > 30) {
            printf("Thang %d chi co 30 ngay. Nhap lai!\n", a->thang);
            continue;
        }

        if (a->thang == 2) {
            int namNhuan = (a->nam % 4 == 0 && a->nam % 100 != 0) || (a->nam % 400 == 0);
            if ((namNhuan && a->ngay > 29) || (!namNhuan && a->ngay > 28)) {
                printf("Thang 2 nam %d chi co %d ngay. Nhap lai!\n", a->nam, namNhuan ? 29 : 28);
                continue;
            }
        }

        hopLe = 1;
    }
}

void xuatNgay(date a) {
    printf("%02d/%02d/%04d", a.ngay, a.thang, a.nam);
}

typedef struct {
    char ma_vat_tu[10];
    char ten_vat_tu[50];
    char loai_vat_tu[20];
    char don_vi_tinh[10];
    date ngay_nhap;
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
        
        getchar(); // Xóa b? ð?m trý?c khi nh?p chu?i
        printf("Ten vat tu: "); fgets(ds[i].ten_vat_tu, sizeof(ds[i].ten_vat_tu), stdin);
        ds[i].ten_vat_tu[strcspn(ds[i].ten_vat_tu, "\n")] = '\0'; // Xóa k? t? xu?ng d?ng

        printf("Loai vat tu: "); fgets(ds[i].loai_vat_tu, sizeof(ds[i].loai_vat_tu), stdin);
        ds[i].loai_vat_tu[strcspn(ds[i].loai_vat_tu, "\n")] = '\0';

        printf("Don vi tinh: "); scanf("%s", ds[i].don_vi_tinh);
        
        printf("Ngay nhap: "); nhapNgay(&ds[i].ngay_nhap);

        getchar(); // Xóa b? ð?m
        printf("Nha san xuat: "); fgets(ds[i].nha_san_xuat, sizeof(ds[i].nha_san_xuat), stdin);
        ds[i].nha_san_xuat[strcspn(ds[i].nha_san_xuat, "\n")] = '\0';

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
        printf("%-10s %-20s %-15s %-10s ", ds[i].ma_vat_tu, ds[i].ten_vat_tu, ds[i].loai_vat_tu, ds[i].don_vi_tinh);
        xuatNgay(ds[i].ngay_nhap);
        printf(" %-15s %-10d %-10.2f %-10.2f\n", ds[i].nha_san_xuat, ds[i].so_luong, ds[i].don_gia, ds[i].thanh_tien);
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

