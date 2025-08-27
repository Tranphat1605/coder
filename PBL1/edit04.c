#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VAT_TU 100

typedef struct {
    int ngay, thang, nam;
} date;

// Hàm so sánh ngày
bool soSanhNgay(date a, date b) {
    if (a.nam > b.nam) return true;
    else if (a.nam == b.nam) {
        if (a.thang > b.thang) return true;
        else if (a.thang == b.thang) {
            if (a.ngay > b.ngay) return true;
        }
    }
    return false;
}

// Hàm nhập ngày và kiểm tra tính hợp lệ
void nhapNgay(date *a) {
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

// Hàm xuất ngày
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

// Hàm tính thành tiền
void tinhThanhTien(VatTu *vt) {
    float giam = 0;
    if (vt->so_luong > 200) giam = 0.25;
    else if (vt->so_luong > 100) giam = 0.10;
    vt->thanh_tien = vt->so_luong * vt->don_gia * (1 - giam);
}

// Hàm đọc file
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

// Hàm nhập thông tin một vật tư
void nhapMotVatTu(VatTu *vt) {
    printf("Ma vat tu: "); scanf("%s", vt->ma_vat_tu);
    printf("Ten vat tu: "); scanf(" %[^\n]", vt->ten_vat_tu);
    printf("Loai vat tu: "); scanf(" %[^\n]", vt->loai_vat_tu);
    printf("Don vi tinh: "); scanf("%s", vt->don_vi_tinh);
    printf("Ngay nhap (dd mm yyyy): "); nhapNgay(&vt->ngay_nhap);
    printf("Nha san xuat: "); scanf(" %[^\n]", vt->nha_san_xuat);
    printf("So luong: "); scanf("%d", &vt->so_luong);
    printf("Don gia: "); scanf("%f", &vt->don_gia);
    tinhThanhTien(vt);
}

// Hàm xuất thông tin một vật tư
void xuatMotVatTu(VatTu vt) {
    printf("%-10s %-20s %-15s %-10s ", vt.ma_vat_tu, vt.ten_vat_tu, vt.loai_vat_tu, vt.don_vi_tinh);
    xuatNgay(vt.ngay_nhap);
    printf(" %-15s %-10d %-10.2f %-10.2f\n", vt.nha_san_xuat, vt.so_luong, vt.don_gia, vt.thanh_tien);
}

// Hàm nhập danh sách vật tư
void nhapDanhSach(VatTu ds[], int *n) {
    int m;
    printf("Nhap so luong vat tu can them: ");
    scanf("%d", &m);
    if (*n + m > MAX_VAT_TU) {
        printf("Vuot qua so luong toi da. Chi co the them toi da %d vat tu.\n", MAX_VAT_TU - *n);
        m = MAX_VAT_TU - *n;
    }
    for (int i = 0; i < m; i++) {
        printf("Nhap thong tin vat tu %d:\n", *n + 1);
        nhapMotVatTu(&ds[*n]);
        (*n)++;
    }
}

// Hàm xóa vật tư có số lượng lớn hơn 100
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
    printf("Da xoa cac vat tu co so luong lon hon 100.\n");
}

// Hàm in danh sách vật tư
void inDanhSach(VatTu ds[], int n) {
    printf("\nDanh sach vat tu:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
           "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    for (int i = 0; i < n; i++) {
        xuatMotVatTu(ds[i]);
    }
}

// Hàm sắp xếp vật tư
void sapXepVatTu(VatTu ds[], int n) {
    int chon;
    printf("Sap xep vat tu theo:\n");
    printf("0. Thoat\n");
    printf("1. Ma vat tu\n");
    printf("2. Ten vat tu\n");
    printf("3. Ngay nhap\n");
    printf("Chon: ");
    scanf("%d", &chon);
    switch (chon) {
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
            printf("Lua chon khong hop le.\n");
            return;
    }
    printf("Sap xep thanh cong.\n");
    inDanhSach(ds, n);
}

// Hàm thống kê theo loại vật tư
void thongKeTheoLoai(VatTu ds[], int n) {
    printf("\nBang thong ke theo loai vat tu:\n");
    printf("%-20s %-10s %-10s\n", "Loai vat tu", "So luong", "Tong tien");

    char loai[MAX_VAT_TU][20];
    int so_luong[MAX_VAT_TU] = {0};
    float tong_tien[MAX_VAT_TU] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(ds[i].loai_vat_tu, loai[j]) == 0) {
                so_luong[j] += ds[i].so_luong;
                tong_tien[j] += ds[i].thanh_tien;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(loai[count], ds[i].loai_vat_tu);
            so_luong[count] = ds[i].so_luong;
            tong_tien[count] = ds[i].thanh_tien;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", loai[i], so_luong[i], tong_tien[i]);
    }
}

// Hàm tìm kiếm vật tư
void timKiemVatTu(VatTu ds[], int n) {
    char key[50];
    printf("Nhap ma vat tu hoac ten vat tu can tim: ");
    scanf(" %[^\n]", key);

    printf("\nKet qua tim kiem:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
           "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma_vat_tu, key) == 0 || strstr(ds[i].ten_vat_tu, key) != NULL) {
            xuatMotVatTu(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay vat tu nao!\n");
    }
}

// Hàm chèn vật tư tại vị trí bất kỳ
void chenVatTuTaiViTri(VatTu ds[], int *n) {
    if (*n >= MAX_VAT_TU) {
        printf("Danh sach da day, khong the them vat tu moi.\n");
        return;
    }

    int viTri;
    printf("Nhap vi tri can chen (0 - %d): ", *n);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *n; i > viTri; i--) {
        ds[i] = ds[i - 1];
    }

    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&ds[viTri]);
    (*n)++;
}

// Hàm chèn vật tư và giữ danh sách đã sắp xếp
void chenVatTuVaSapXep(VatTu ds[], int *n) {
    if (*n >= MAX_VAT_TU) {
        printf("Danh sach da day, khong the them vat tu moi.\n");
        return;
    }

    VatTu newVT;
    printf("Nhap thong tin vat tu can them:\n");
    nhapMotVatTu(&newVT);

    int i = *n - 1;
    while (i >= 0 && strcmp(ds[i].ma_vat_tu, newVT.ma_vat_tu) > 0) {
        ds[i + 1] = ds[i];
        i--;
    }

    ds[i + 1] = newVT;
    (*n)++;
}

// Hàm main
int main() {
    VatTu danhSach[MAX_VAT_TU];
    int n = 0;
    docFile(danhSach, &n);

    int chon;
    do {
        printf("\n===== MENU =====\n");
        printf("0. Thoat\n");
        printf("1. Nhap danh sach vat tu\n");
        printf("2. Xoa vat tu\n");
        printf("3. Sap xep vat tu\n");
        printf("4. Thong ke theo loai\n");
        printf("5. In danh sach vat tu\n");
        printf("6. Tim kiem vat tu\n");
        printf("7. Chen vat tu tai vi tri bat ki\n");
        printf("8. Chen vat tu va giu danh sach da sap xep\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            case 1:
                nhapDanhSach(danhSach, &n);
                break;
            case 2:
                xoaVatTu(danhSach, &n);
                break;
            case 3:
                sapXepVatTu(danhSach, n);
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
                chenVatTuTaiViTri(danhSach, &n);
                break;
            case 8:
                chenVatTuVaSapXep(danhSach, &n);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (chon != 0);

    return 0;
}