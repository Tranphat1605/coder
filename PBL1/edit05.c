#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define MAX_VAT_TU 100

int sapxeptheo=0;

typedef struct
{
	int ngay,thang,nam;
} date;

bool soSanhNgay(date a, date b)
{
    if(a.nam>b.nam)
        return true;
    else if(a.nam==b.nam)
    {
        if(a.thang>b.thang)
            return true;
        else if(a.thang==b.thang)
        {
            if(a.ngay>b.ngay)
                return true;
        }
    }
    return false;
}

void nhapNgay(date* a)
{
    while (1) {
        scanf("%d%d%d", &a->ngay, &a->thang, &a->nam);
        if (a->ngay < 1 || a->ngay > 31 || a->thang < 1 || a->thang > 12 || a->nam < 1) {
            printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
            continue;
        }
        if ((a->thang == 4 || a->thang == 6 || a->thang == 9 || a->thang == 11) && a->ngay > 30) {
            printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
            continue;
        }
        if (a->thang == 2) {
            if ((a->nam % 4 == 0 && a->nam % 100 != 0) || a->nam % 400 == 0) {
                if (a->ngay > 29) {
                    printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
                    continue;
                }
            } else {
                if (a->ngay > 28) {
                    printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
                    continue;
                }
            }
        }
        break;
    }
}

void xuatNgay(date a)
{
    if(a.ngay<10){
        printf("0");
        printf("%d/",a.ngay);}
    else
        printf("%d/",a.ngay);
    if(a.thang<10)
    {
        printf("0");
        printf("%d/",a.thang);
    }
    else
        printf("%d/",a.thang);
    printf("%-7d",a.nam);
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

void docFile(VatTu ds[], int *n) {
    FILE *f = fopen("VatTu.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc file\n");
        exit(1);
    }
    
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%s", ds[i].ma_vat_tu);
        fscanf(f, " %[^\n]", ds[i].ten_vat_tu);
        fscanf(f, " %[^\n]", ds[i].loai_vat_tu);
        fscanf(f, "%s", ds[i].don_vi_tinh);
        fscanf(f, "%d%d%d", &ds[i].ngay_nhap.ngay, &ds[i].ngay_nhap.thang, &ds[i].ngay_nhap.nam);
        fscanf(f, " %[^\n]", ds[i].nha_san_xuat);
        fscanf(f, "%d", &ds[i].so_luong);
        fscanf(f, "%f", &ds[i].don_gia);
        tinhThanhTien(&ds[i]);
    }
    fclose(f);
}

void nhapMotVatTu(VatTu *vt) {
    printf("Ma vat tu: "); scanf("%s", vt->ma_vat_tu);
    printf("Ten vat tu: "); scanf(" %[^\n]", vt->ten_vat_tu);
    printf("Loai vat tu: "); scanf(" %[^\n]", vt->loai_vat_tu);
    printf("Don vi tinh: "); scanf("%s", vt->don_vi_tinh);
    printf("Ngay nhap (dd/mm/yyyy): "); nhapNgay(&vt->ngay_nhap);
    printf("Nha san xuat: "); scanf(" %[^\n]", vt->nha_san_xuat);
    printf("So luong: "); scanf("%d", &vt->so_luong);
    printf("Don gia: "); scanf("%f", &vt->don_gia);
}
    
void xuatMotVatTu(VatTu vt) {
    printf("%-10s %-20s %-15s %-10s ", vt.ma_vat_tu, vt.ten_vat_tu, vt.loai_vat_tu, vt.don_vi_tinh);
    xuatNgay(vt.ngay_nhap);
    printf("%-15s %-10d %-10.2f %-10.2f\n", vt.nha_san_xuat, vt.so_luong, vt.don_gia, vt.thanh_tien);
}

void nhapThemVatTu(VatTu ds[], int *n) {
    int m;
    printf("Nhap so luong vat tu can them: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Nhap thong tin vat tu %d:\n", i + 1);
        nhapMotVatTu(&ds[*n]);
        tinhThanhTien(&ds[*n]);
        (*n)++;
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

void inDanhSach(VatTu ds[], int n) {
    printf("\nDanh sach vat tu:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n", 
        "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    
    for (int i = 0; i < n; i++) {
        xuatMotVatTu(ds[i]);
    }
}

void sapXepVatTu(VatTu ds[], int n) {
    switch (sapxeptheo)
    {
    case 0:
        return; 
    case 1:
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (strcmp(ds[i].ma_vat_tu, ds[j].ma_vat_tu) > 0) {
                    VatTu temp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (strcmp(ds[i].ten_vat_tu, ds[j].ten_vat_tu) > 0) {
                    VatTu temp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = temp;
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (soSanhNgay(ds[i].ngay_nhap, ds[j].ngay_nhap)) {
                    VatTu temp = ds[i];
                    ds[i] = ds[j];
                    ds[j] = temp;
                }
            }
        }
        break;
    default:
        printf("Khong hop le. Nhap lai: \n");
        break;
    }
}

void thongKeTheoLoai(VatTu ds[], int n) {
    printf("\nBang thong ke theo loai vat tu:\n");
    printf("%-20s %-10s %-10s\n", "Loai vat tu", "So luong", "Tong tien");
    char loai[MAX_VAT_TU][20];
    int soLuong[MAX_VAT_TU] = {0};
    float tongTien[MAX_VAT_TU] = {0};
    int count = 0,i,j;
    for(i = 0; i < n; i++) {
        for (j = 0; j < count; j++) 
            if (strcmp(ds[i].loai_vat_tu, loai[j]) == 0) {
                soLuong[j] += ds[i].so_luong;
                tongTien[j] += ds[i].thanh_tien;
                break;
            }
            if(j == count) {
                strcpy(loai[count], ds[i].loai_vat_tu);
                soLuong[count] = ds[i].so_luong;
                tongTien[count] = ds[i].thanh_tien;
                count++;
            }
    }
    for (int i = 0; i < count; i++)
        printf("%-20s %-10d %-10.2f\n", loai[i], soLuong[i], tongTien[i]);
}

void timKiemVatTu(VatTu ds[], int n) {
    char ma[10];
    int dem = 0;
    printf("Nhap ma vat tu can tim: ");
    scanf("%s", ma);
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n", 
        "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma_vat_tu, ma) == 0) {
            xuatMotVatTu(ds[i]);
            dem++;
        }
    }
    if (dem == 0)
        printf("Khong tim thay vat tu"); 
}

void chenVatTu(VatTu ds[], int *n) {
    int i,k;
    printf("Nhap vi tri can chen: ");
    scanf("%d", &k);
    if (k < 0 || k > *n) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for(i=*n;i>=k;i--)
    {
        ds[i]=ds[i-1];
    }
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&ds[i]);
    tinhThanhTien(&ds[i]);
    (*n)++;
}

void chenVatTuVaSapXep(VatTu ds[], int *n) {
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&ds[*n]);
    tinhThanhTien(&ds[*n]);
    (*n)++;
    sapXepVatTu(ds, *n);
}

int main() {
    int chon=0;
    int n;
    VatTu danhSach[MAX_VAT_TU];
    docFile(danhSach, &n);
    do {
        printf("===== MENU =====\n");
        printf("0. Thoat\n");
        printf("1. Nhap them vat tu\n");
        printf("2. Xoa vat tu\n");
        printf("3. Sap xep vat tu\n"); 
        printf("4. Thong ke theo loai\n");
        printf("5. In danh sach vat tu\n");
        printf("6. Tim kiem vat tu\n");
        printf("7. Chen vat tu\n");
        printf("8. Chen vat tu va sap xep\n");
        printf("Chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 0:
                break;
            case 1:
                nhapThemVatTu(danhSach, &n);
                break;
            case 2:
                xoaVatTu(danhSach, &n);
                break;
            case 3: 
                printf("Sap xep vat tu theo:\n");
                printf("0. Thoat\n");
                printf("1. Ma vat tu\n");
                printf("2. Ten vat tu\n");
                printf("3. Ngay nhap\n");
                printf("Chon: ");
                scanf("%d", &sapxeptheo);
                sapXepVatTu(danhSach, n);
                printf("Sap xep thanh cong\n"); 
                inDanhSach(danhSach, n);
                break;
            case 4:
                thongKeTheoLoai(danhSach, n);
                break;
            case 5:
                inDanhSach(danhSach, n);
                break;
            case 6:
                timKiemVatTu(danhSach, n);
                break;
            case 7:
                chenVatTu(danhSach, &n);
                break;
            case 8:
                chenVatTuVaSapXep(danhSach, &n);
                break;
            default:
                printf("Khong hop le. Nhap lai: \n");
                break;
        }
        if(chon!=0)
        {
            printf("Bam phim bat ky de tiep tuc\n");
            getch();
        }
    } while (chon != 0);
    return 0;
}