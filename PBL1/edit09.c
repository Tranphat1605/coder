#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define INITIAL_CAPACITY 100

typedef struct
{
    int ngay, thang, nam;
} date;

int soSanhNgay(date a, date b)
{
    if (a.nam > b.nam)
        return 1;
    if (a.nam < b.nam)
        return -1;
    if (a.thang > b.thang)
        return 1;
    if (a.thang < b.thang)
        return -1;
    if (a.ngay > b.ngay)
        return 1;
    if (a.ngay < b.ngay)
        return -1;
    return 0;
}

void nhapNgay(date *a)
{
    while (1)
    {
        scanf("%d%d%d", &a->ngay, &a->thang, &a->nam);
        if (a->ngay < 1 || a->ngay > 31 || a->thang < 1 || a->thang > 12 || a->nam < 1)
        {
            printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
            continue;
        }
        if ((a->thang == 4 || a->thang == 6 || a->thang == 9 || a->thang == 11) && a->ngay > 30)
        {
            printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
            continue;
        }
        if (a->thang == 2)
        {
            if ((a->nam % 4 == 0 && a->nam % 100 != 0) || a->nam % 400 == 0)
            {
                if (a->ngay > 29)
                {
                    printf("Ngay khong hop le. Nhap lai (dd mm yyyy): ");
                    continue;
                }
            }
            else
            {
                if (a->ngay > 28)
                {
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
    if (a.ngay < 10)
    {
        printf("0");
        printf("%d/", a.ngay);
    }
    else
        printf("%d/", a.ngay);
    if (a.thang < 10)
    {
        printf("0");
        printf("%d/", a.thang);
    }
    else
        printf("%d/", a.thang);
    printf("%-7d", a.nam);
}

typedef struct
{
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

void swapVatTu(VatTu *a, VatTu *b)
{
    VatTu temp = *a;
    *a = *b;
    *b = temp;
}

int soSanhVatTu(VatTu a, VatTu b, int sapxeptheo)
{
    switch (sapxeptheo)
    {
    case 1:
        return strcmp(a.ma_vat_tu, b.ma_vat_tu);
    case 2:
        return strcmp(a.ten_vat_tu, b.ten_vat_tu);
    case 3:
        return soSanhNgay(a.ngay_nhap, b.ngay_nhap);
    default:
        return 0;
    }
}

void tinhThanhTien(VatTu *vt)
{
    float giam = (vt->so_luong > 200) ? 0.25 : (vt->so_luong > 100) ? 0.10 : 0;
    vt->thanh_tien = vt->so_luong * vt->don_gia * (1 - giam);
}

void resizeArray(VatTu **ds, int *capacity, int requiredSize)
{
    if (requiredSize > *capacity)
    {
        *capacity = (requiredSize > *capacity * 2) ? requiredSize : *capacity * 2;
        VatTu *temp = realloc(*ds, *capacity * sizeof(VatTu));
        if (temp == NULL)
        {
            printf("Khong du bo nho\n");
            exit(1);
        }
        *ds = temp;
    }
}

void docFile(VatTu **ds, int *n, int *capacity)
{
    char filename[100];
    int m;
    printf("Nhap ten file can doc (co phan mo rong .txt): ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }
    if (fscanf(f, "%d", &m) != 1)
    {
        printf("Loi khi doc so luong vat tu tu file.\n");
        fclose(f);
        return;
    }
    if (m == 0)
    {
        printf("File trong\n");
        fclose(f);
        return;
    }
    resizeArray(ds, capacity, *n + m);
    int i = *n;
    *n += m;
    for (; i < *n; i++)
    {
        if (fscanf(f, "%9s", (*ds)[i].ma_vat_tu) != 1 ||
            fscanf(f, " %49[^\n]", (*ds)[i].ten_vat_tu) != 1 ||
            fscanf(f, " %19[^\n]", (*ds)[i].loai_vat_tu) != 1 ||
            fscanf(f, "%9s", (*ds)[i].don_vi_tinh) != 1 ||
            fscanf(f, "%d%d%d", &(*ds)[i].ngay_nhap.ngay, &(*ds)[i].ngay_nhap.thang, &(*ds)[i].ngay_nhap.nam) != 3 ||
            fscanf(f, " %49[^\n]", (*ds)[i].nha_san_xuat) != 1 ||
            fscanf(f, "%d", &(*ds)[i].so_luong) != 1 ||
            fscanf(f, "%f", &(*ds)[i].don_gia) != 1)
        {
            printf("Xay ra loi khi doc du lieu tu file.\n");
            fclose(f);
            *n = i;
            return;
        }
        tinhThanhTien(&(*ds)[i]);
    }
    fclose(f);
}

void xuatFile(VatTu *ds, int n)
{
    char filename[100];
    printf("Nhap ten file can xuat (co phan mo rong .txt): ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Khong mo duoc file\n");
        return;
    }
    fprintf(f, "%d\n", n);
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%s\n", ds[i].ma_vat_tu);
        fprintf(f, "%s\n", ds[i].ten_vat_tu);
        fprintf(f, "%s\n", ds[i].loai_vat_tu);
        fprintf(f, "%s\n", ds[i].don_vi_tinh);
        fprintf(f, "%d %d %d\n", ds[i].ngay_nhap.ngay, ds[i].ngay_nhap.thang, ds[i].ngay_nhap.nam);
        fprintf(f, "%s\n", ds[i].nha_san_xuat);
        fprintf(f, "%d\n", ds[i].so_luong);
        fprintf(f, "%f\n", ds[i].don_gia);
    }
    fclose(f);
}

void nhapMotVatTu(VatTu *vt)
{
    printf("Ma vat tu: ");
    scanf("%9s", vt->ma_vat_tu);
    printf("Ten vat tu: ");
    scanf(" %49[^\n]", vt->ten_vat_tu);
    printf("Loai vat tu: ");
    scanf(" %19[^\n]", vt->loai_vat_tu);
    printf("Don vi tinh: ");
    scanf("%9s", vt->don_vi_tinh);
    printf("Ngay nhap (dd/mm/yyyy): ");
    nhapNgay(&vt->ngay_nhap);
    printf("Nha san xuat: ");
    scanf(" %49[^\n]", vt->nha_san_xuat);
    printf("So luong: ");
    scanf("%d", &vt->so_luong);
    printf("Don gia: ");
    scanf("%f", &vt->don_gia);
}

void xuatMotVatTu(VatTu vt)
{
    printf("%-10s %-20s %-15s %-10s ", vt.ma_vat_tu, vt.ten_vat_tu, vt.loai_vat_tu, vt.don_vi_tinh);
    xuatNgay(vt.ngay_nhap);
    printf("%-15s %-10d %-10.2f %-10.2f\n", vt.nha_san_xuat, vt.so_luong, vt.don_gia, vt.thanh_tien);
}

void nhapThemVatTu(VatTu **ds, int *n, int *capacity)
{
    int m, i;
    printf("Nhap so luong vat tu can them: ");
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("So luong khong hop le\n");
        return;
    }
    resizeArray(ds, capacity, *n + m);
    for (i = 0; i < m; i++)
    {
        printf("\nNhap thong tin vat tu %d:\n", i + 1);
        nhapMotVatTu(&(*ds)[*n]);
        tinhThanhTien(&(*ds)[*n]);
        (*n)++;
    }
}

void xoaVatTu(VatTu **ds, int *n)
{
    int i, j, confirm, found = 0;
    printf("\nDanh sach vat tu co so luong lon hon 100:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
           "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    for (i = 0; i < *n; i++)
    {
        if ((*ds)[i].so_luong > 100)
        {
            xuatMotVatTu((*ds)[i]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Khong tim thay vat tu co so luong lon hon 100\n");
        return;
    }
    printf("Ban co chac chan muon xoa cac vat tu nay khong? (1: Co, 0: Khong): ");
    scanf("%d", &confirm);
    if (confirm != 1)
    {
        printf("Da huy thao tac xoa\n");
        return;
    }
    int deleted = 0;
    i = 0;
    while (i < *n)
    {
        if ((*ds)[i].so_luong > 100)
        {
            for (j = i; j < *n - 1; j++)
            {
                (*ds)[j] = (*ds)[j + 1];
            }
            (*n)--;
            deleted++;
        }
        else
        {
            i++;
        }
    }
    if (deleted > 0)
        printf("Da xoa %d vat tu co so luong lon hon 100\n", deleted);
    else
        printf("Khong co vat tu nao duoc xoa\n");
}

void xoaVatTuBatKy(VatTu **ds, int *n)
{
    VatTu x;
    int i, j, chon, k = 0;
    system("cls");
    printf("Xoa vat tu theo:\n");
    printf("0. Thoat\n");
    printf("1. Ma vat tu\n");
    printf("2. Ten vat tu\n");
    printf("3. Ngay nhap\n");
    printf("Chon: ");
    scanf("%d", &chon);
    if (chon == 0)
        return;
    switch (chon)
    {
    case 1:
        printf("Nhap ma vat tu can xoa: ");
        scanf("%9s", x.ma_vat_tu);
        break;
    case 2:
        printf("Nhap ten vat tu can xoa: ");
        scanf(" %49[^\n]", x.ten_vat_tu);
        break;
    case 3:
        printf("Nhap ngay nhap can xoa (dd/mm/yyyy): ");
        nhapNgay(&x.ngay_nhap);
        break;
    default:
        printf("Lua chon khong hop le\n");
        return;
    }
    for (i = 0; i < *n; i++)
    {
        if (soSanhVatTu((*ds)[i], x, chon) == 0)
        {
            xuatMotVatTu((*ds)[i]);
            printf("Ban co chac chan muon xoa vat tu nay khong? (1: Co, 0: Khong): ");
            scanf("%d", &j);
            if (j == 0)
                continue;
            for (j = i; j < *n - 1; j++)
            {
                (*ds)[j] = (*ds)[j + 1];
            }
            (*n)--;
            i--;
            k = 1;
        }
    }
    if (k > 0)
        printf("Xoa thanh cong\n");
    else
        printf("Khong tim thay vat tu can xoa\n");
}

void sapXep(VatTu *ds, int trai, int phai, int sapxeptheo)
{
    int i = trai, j = phai;
    VatTu mid = ds[(trai + phai) / 2];
    do
    {
        while (soSanhVatTu(mid, ds[i], sapxeptheo) > 0 && i < phai)
            i++;
        while (soSanhVatTu(ds[j], mid, sapxeptheo) > 0 && j > trai)
            j--;
        if (i <= j)
        {
            swapVatTu(&ds[i], &ds[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (trai < j)
        sapXep(ds, trai, j, sapxeptheo);
    if (i < phai)
        sapXep(ds, i, phai, sapxeptheo);
}

void thongKeTheoLoai(VatTu *ds, int n)
{
    printf("\nBang thong ke theo loai vat tu:\n");
    printf("%-20s %-10s %-10s\n", "Loai vat tu", "So luong", "Tong tien");
    char loai[INITIAL_CAPACITY][20];
    int soLuong[INITIAL_CAPACITY] = {0};
    float tongTien[INITIAL_CAPACITY] = {0};
    int count = 0, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < count; j++)
            if (strcmp(ds[i].loai_vat_tu, loai[j]) == 0)
            {
                soLuong[j] += ds[i].so_luong;
                tongTien[j] += ds[i].thanh_tien;
                break;
            }
        if (j == count)
        {
            strcpy(loai[count], ds[i].loai_vat_tu);
            soLuong[count] = ds[i].so_luong;
            tongTien[count] = ds[i].thanh_tien;
            count++;
        }
    }
    for (i = 0; i < count; i++)
    {
        Sleep(300);
        printf("%-20s %-10d %-10.2f\n", loai[i], soLuong[i], tongTien[i]);
    }
}

void inDanhSach(VatTu *ds, int n)
{
    printf("\nDanh sach vat tu:\n");
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
           "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    int i;
    for (i = 0; i < n; i++)
    {
        Sleep(300);
        xuatMotVatTu(ds[i]);
    }
}

void sapXepVatTu(VatTu *ds, int n, int *sapxeptheo)
{
    system("cls");
    printf("Sap xep vat tu theo:\n");
    printf("0. Thoat\n");
    printf("1. Ma vat tu\n");
    printf("2. Ten vat tu\n");
    printf("3. Ngay nhap\n");
    printf("Chon: ");
    scanf("%d", sapxeptheo);
    if (*sapxeptheo == 0)
        return;
    if (*sapxeptheo < 1 || *sapxeptheo > 3)
    {
        printf("Lua chon khong hop le\n");
        return;
    }
    sapXep(ds, 0, n - 1, *sapxeptheo);
    printf("Sap xep thanh cong\n");
    inDanhSach(ds, n);
}

void timKiemVatTu(VatTu *ds, int n)
{
    VatTu x;
    int i, chon;
    system("cls");
    printf("Tim kiem vat tu theo:\n");
    printf("0. Thoat\n");
    printf("1. Ma vat tu\n");
    printf("2. Ten vat tu\n");
    printf("3. Ngay nhap\n");
    printf("Chon: ");
    scanf("%d", &chon);
    getchar();
    switch (chon)
    {
    case 0:
        return;
    case 1:
        printf("Nhap ma vat tu can tim: ");
        fgets(x.ma_vat_tu, sizeof(x.ma_vat_tu), stdin);
        x.ma_vat_tu[strcspn(x.ma_vat_tu, "\n")] = '\0';
        break;
    case 2:
        printf("Nhap ten vat tu can tim: ");
        fgets(x.ten_vat_tu, sizeof(x.ten_vat_tu), stdin);
        x.ten_vat_tu[strcspn(x.ten_vat_tu, "\n")] = '\0';
        break;
    case 3:
        printf("Nhap ngay nhap can tim (dd/mm/yyyy): ");
        nhapNgay(&x.ngay_nhap);
        break;
    default:
        printf("Lua chon khong hop le\n");
        return;
    }
    int found = 0;
    printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
           "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
    for (i = 0; i < n; i++)
    {
        if (soSanhVatTu(ds[i], x, chon) == 0)
        {
            xuatMotVatTu(ds[i]);
            found = 1;
        }
    }
    if (!found)
        printf("Khong tim thay vat tu\n");
}

void chenVatTu(VatTu **ds, int *n, int *capacity)
{
    int i, k;
    printf("Nhap vi tri can chen: ");
    scanf("%d", &k);
    if (k < 0 || k > *n)
    {
        printf("Vi tri khong hop le\n");
        return;
    }
    resizeArray(ds, capacity, *n + 1);
    for (i = *n; i > k; i--)
    {
        (*ds)[i] = (*ds)[i - 1];
    }
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&(*ds)[k]);
    tinhThanhTien(&(*ds)[k]);
    (*n)++;
}

void chenVatTuVaSapXep(VatTu **ds, int *n, int *capacity, int sapxeptheo)
{
    int i;
    if (sapxeptheo < 1 || sapxeptheo > 3)
    {
        printf("Chua sap xep danh sach, vui long sap xep truoc\n");
        return;
    }
    resizeArray(ds, capacity, *n + 1);
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&(*ds)[*n]);
    tinhThanhTien(&(*ds)[*n]);
    for (i = *n; i > 0; i--)
    {
        if (soSanhVatTu((*ds)[i - 1], (*ds)[i], sapxeptheo) > 0)
        {
            swapVatTu(&(*ds)[i], &(*ds)[i - 1]);
        }
        else
            break;
    }
    (*n)++;
    printf("Vat tu duoc chen o vi tri %d\n", i + 1);
}

void inMenu()
{
    printf("===== MENU =====\n");
    printf("0. Thoat\n");
    printf("1. Doc file\n");
    printf("2. Xuat file\n");
    printf("3. Nhap them vat tu\n");
    printf("4. Xoa mot vat tu co so luong lon\n");
    printf("5. Xoa vat tu bat ky\n");
    printf("6. Sap xep vat tu\n");
    printf("7. Thong ke vat tu theo loai\n");
    printf("8. In danh sach vat tu\n");
    printf("9. Tim kiem vat tu\n");
    printf("10. Chen vat tu\n");
    printf("11. Chen vat tu va sap xep\n");
}

int main()
{
    int chon = 0;
    int n = 0;
    int capacity = INITIAL_CAPACITY;
    int sapxeptheo = 0;
    VatTu *danhSach = malloc(capacity * sizeof(VatTu));
    if (danhSach == NULL)
    {
        printf("Khong du bo nho\n");
        return 1;
    }
    do
    {
        system("cls");
        inMenu();
        printf("Chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            free(danhSach);
            break;
        case 1:
            docFile(&danhSach, &n, &capacity);
            break;
        case 2:
            xuatFile(danhSach, n);
            break;
        case 3:
            nhapThemVatTu(&danhSach, &n, &capacity);
            break;
        case 4:
            xoaVatTu(&danhSach, &n);
            break;
        case 5:
            xoaVatTuBatKy(&danhSach, &n);
            break;
        case 6:
            sapXepVatTu(danhSach, n, &sapxeptheo);
            break;
        case 7:
            thongKeTheoLoai(danhSach, n);
            break;
        case 8:
            inDanhSach(danhSach, n);
            break;
        case 9:
            timKiemVatTu(danhSach, n);
            break;
        case 10:
            chenVatTu(&danhSach, &n, &capacity);
            break;
        case 11:
            chenVatTuVaSapXep(&danhSach, &n, &capacity, sapxeptheo);
            break;
        default:
            printf("Khong hop le. Nhap lai: \n");
            break;
        }
        if (chon != 0)
        {
            printf("Bam phim bat ky de tiep tuc\n");
            getch();
        }
    } while (chon != 0);
    return 0;
}