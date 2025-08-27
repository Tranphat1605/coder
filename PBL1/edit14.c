#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define INITIAL_CAPACITY 100
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

typedef struct
{
    int ngay, thang, nam;
} date;
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
int soSanhNgay(date a, date

 b)
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
void nhapNgay(date *a);
void xuatNgay(date a);
void tinhThanhTien(VatTu *vt);
void resizeArray(VatTu **ds, int capacity)
{
    VatTu *temp = realloc(*ds, capacity * sizeof(VatTu));
    if (temp == NULL)
    {
        printf("Khong du bo nho\n");
        exit(1);
    }
    *ds = temp;
}
void docDong(char line[], VatTu *a)
{
    char *token = strtok(line, ",");
    if (token)
        strcpy(a->ma_vat_tu, token);
    else
        a->ma_vat_tu[0] = '\0';

    token = strtok(NULL, ",");
    if (token)
        strcpy(a->ten_vat_tu, token);
    else
        a->ten_vat_tu[0] = '\0';

    token = strtok(NULL, ",");
    if (token)
        strcpy(a->loai_vat_tu, token);
    else
        a->loai_vat_tu[0] = '\0';

    token = strtok(NULL, ",");
    if (token)
        strcpy(a->don_vi_tinh, token);
    else
        a->don_vi_tinh[0] = '\0';

    token = strtok(NULL, ",");
    if (token)
    {
        if (sscanf(token, "%d/%d/%d", &a->ngay_nhap.ngay, &a->ngay_nhap.thang, &a->ngay_nhap.nam) != 3)
        {
            a->ngay_nhap.ngay = a->ngay_nhap.thang = a->ngay_nhap.nam = 0;
        }
    }
    else
    {
        a->ngay_nhap.ngay = a->ngay_nhap.thang = a->ngay_nhap.nam = 0;
    }

    token = strtok(NULL, ",");
    if (token)
        strcpy(a->nha_san_xuat, token);
    else
        a->nha_san_xuat[0] = '\0';

    token = strtok(NULL, ",");
    if (token)
        a->so_luong = atoi(token);
    else
        a->so_luong = 0;

    token = strtok(NULL, ",");
    if (token)
        a->don_gia = atof(token);
    else
        a->don_gia = 0.0;

    token = strtok(NULL, ",");
    if (token)
        a->thanh_tien = atof(token);
    else
        a->thanh_tien = 0.0;
}
void docFile(VatTu **ds, int *n)
{
    char filename[100];
    int m;
    setColor(14);
    printf("Nhap ten file can doc (co phan mo rong .txt): ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Khong mo duoc file.\n");
        return;
    }
    if (fscanf(f, "%d", &m) != 1)
    {
        printf("Loi khi doc so luong vat tu tu file.\n");
        fclose(f);
        return;
    }
    fgetc(f);
    if (m == 0)
    {
        printf("File trong.\n");
        fclose(f);
        return;
    }
    resizeArray(ds, m);
    *n = 0;
    char line[200];
    while (fgets(line, sizeof(line), f) != NULL && *n < m)
    {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) <= 1)
            continue;
        docDong(line, &(*ds)[*n]);
        tinhThanhTien(&(*ds)[*n]);
        (*n)++;
    }
    if (*n == 0)
    {
        printf("Khong doc duoc du lieu vat tu nao.\n");
    }
    else
    {
        printf("Doc thanh cong %d vat tu.\n", *n);
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
        VatTu a = ds[i];
        fprintf(f, "%s,%s,%s,%s,%d/%d/%d,%s,%d,%.2f,%.2f\n",
                a.ma_vat_tu, a.ten_vat_tu, a.loai_vat_tu, a.don_vi_tinh,
                a.ngay_nhap.ngay, a.ngay_nhap.thang, a.ngay_nhap.nam,
                a.nha_san_xuat, a.so_luong, a.don_gia, a.thanh_tien);
    }
    fclose(f);
}
void swapVatTu(VatTu *a, VatTu *b);
int soSanhVatTu(VatTu a, VatTu b, int sapxeptheo);
void nhapMotVatTu(VatTu *vt, VatTu **ds, int n);
void xuatMotVatTu(VatTu vt);
void nhapThemVatTu(VatTu **ds, int *n, int *sapxeptheo);
void xoaVatTu(VatTu **ds, int *n);
void xoaVatTuBatKy(VatTu **ds, int *n);
void sapXep(VatTu *ds, int trai, int phai, int sapxeptheo);
void thongKeTheoLoai(VatTu *ds, int n);
void inDanhSach(VatTu *ds, int n);
void sapXepVatTu(VatTu *ds, int n, int *sapxeptheo);
void kiemTraSapXep(VatTu **ds, int n, int *sapxeptheo);
void timKiemVatTu(VatTu *ds, int n);
void chenVatTu(VatTu **ds, int *n, int *sapxeptheo);
void chenVatTuVaoDanhSachDaSapXep(VatTu **ds, int *n, int sapxeptheo);
void suaVatTu(VatTu **ds, int n);
void inMenu();
void inGioiThieu();
void themVatTuVaoCuoi(VatTu **ds, int *n) ;
int main()
{
    inGioiThieu();
    int chon = 0;
    int n = 0;
    int sapxeptheo = 0;
    VatTu *danhSach = malloc(INITIAL_CAPACITY * sizeof(VatTu));
    do
    {
        inMenu();
        printf("Chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            free(danhSach);
            break;
        case 1:
            docFile(&danhSach, &n);
            break;
        case 2:
            xuatFile(danhSach, n);
            break;
        case 3:
            nhapThemVatTu(&danhSach, &n, &sapxeptheo);
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
            chenVatTu(&danhSach, &n, &sapxeptheo);
            break;
        case 11:
            chenVatTuVaoDanhSachDaSapXep(&danhSach, &n, sapxeptheo);
            break;
        case 12:
            suaVatTu(&danhSach, n);
            break;
        case 13:
            themVatTuVaoCuoi(&danhSach, &n);
            break;
        default:
            setColor(10);
            printf("Khong hop le. Nhap lai: \n");
            break;
        }
        if (chon != 0)
        {
            setColor(10);
            printf("\n");
            printf("Bam phim bat ky de tiep tuc\n");
            getch();
            system("cls");
        }
    } while (chon != 0);
    return 0;
}

void nhapNgay(date *a)
{
    while (1)
    {
        scanf("%d/%d/%d", &a->ngay, &a->thang, &a->nam);
        if (a->ngay < 1 || a->ngay > 31 || a->thang < 1 || a->thang > 12 || a->nam < 1)
        {
            printf("Ngay khong hop le. Nhap lai (dd/mm/yyyy): ");
            continue;
        }
        if ((a->thang == 4 || a->thang == 6 || a->thang == 9 || a->thang == 11) && a->ngay > 30)
        {
            printf("Ngay khong hop le. Nhap lai (dd/mm/yyyy): ");
            continue;
        }
        if (a->thang == 2)
        {
            if ((a->nam % 4 == 0 && a->nam % 100 != 0) || a->nam % 400 == 0)
            {
                if (a->ngay > 29)
                {
                    printf("Ngay khong hop le. Nhap lai (dd/mm/yyyy): ");
                    continue;
                }
            }
            else
            {
                if (a->ngay > 28)
                {
                    printf("Ngay khong hop le. Nhap lai (dd/mm/yyyy): ");
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
        printf("0%d/", a.ngay);
    else
        printf("%d/", a.ngay);
    if (a.thang < 10)
        printf("0%d/", a.thang);
    else
        printf("%d/", a.thang);
    printf("%-7d", a.nam);
}

void tinhThanhTien(VatTu *vt)
{
    float giam = (vt->so_luong > 200) ? 0.25 : (vt->so_luong > 100) ? 0.10
                                                                    : 0;
    vt->thanh_tien = vt->so_luong * vt->don_gia * (1 - giam);
}

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

void nhapMotVatTu(VatTu *vt, VatTu **ds, int n)
{
    int i, trung;
    do {
        trung = 0;
        printf("Ma vat tu: ");
        scanf("%9s", vt->ma_vat_tu);
        for (i = 0; i < n; i++) {
            if (strcmp(vt->ma_vat_tu, (*ds)[i].ma_vat_tu) == 0) {
                printf("Ma vat tu da ton tai. Vui long nhap lai.\n");
                trung = 1;
                break;
            }
        }
    } while (trung);

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

void nhapThemVatTu(VatTu **ds, int *n, int *sapxeptheo)
{
    int m, i;
    printf("Nhap so luong vat tu can them: ");
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("So luong khong hop le\n");
        return;
    }
    resizeArray(ds, *n + m);
    for (i = 0; i < m; i++)
    {
        printf("\nNhap thong tin vat tu %d:\n", i + 1);
        nhapMotVatTu(&(*ds)[*n], ds, *n);
        tinhThanhTien(&(*ds)[*n]);
        (*n)++;
    }
    // Kiểm tra xem danh sách có còn được sắp xếp không
    kiemTraSapXep(ds, *n, sapxeptheo);
}

void xoaVatTu(VatTu **ds, int *n)
{
    int i, j, confirm, found = 0;
    for (i = 0; i < *n; i++)
    {
        if ((*ds)[i].so_luong > 100)
        {
            if (found == 0)
            {
                setColor(14);
                printf("\nDanh sach vat tu co so luong lon hon 100:\n");
                printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
                       "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
            }
            xuatMotVatTu((*ds)[i]);
            found = 1;
        }
    }
    if (!found)
    {
        setColor(14);
        printf("Khong tim thay vat tu co so luong lon hon 100.\n");
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
    setColor(14);
    printf("\nBang thong ke theo loai vat tu:\n");
    printf("%-12s %-10s %-10s\n", "Loai vat tu", "So luong", "Tong tien");
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
        printf("%-12s %-10d %-10.2f\n", loai[i], soLuong[i], tongTien[i]);
    }
}

void inDanhSach(VatTu *ds, int n)
{
    setColor(1);
    printf("\n");
    printf("========================================================================================================================\n\n");
    setColor(14);
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

void kiemTraSapXep(VatTu **ds, int n, int *sapxeptheo)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (soSanhVatTu((*ds)[i], (*ds)[i + 1], *sapxeptheo) > 0)
        {
            *sapxeptheo = 0;
            return;
        }
    }
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
        printf("Lua chon khong hop le.\n");
        return;
    }
    int found = 0;
    for (i = 0; i < n; i++)
    {
        if (soSanhVatTu(ds[i], x, chon) == 0)
        {
            if (found == 0)
            {
                printf("Da tim thay vat tu.\n");
                printf("%-10s %-20s %-15s %-10s %-12s %-15s %-10s %-10s %-10s\n",
                       "Ma VT", "Ten VT", "Loai VT", "DVT", "Ngay Nhap", "Nha SX", "So Luong", "Don Gia", "Thanh Tien");
                found = 1;
            }
            xuatMotVatTu(ds[i]);
        }
    }
    if (!found)
        printf("Khong tim thay vat tu.\n");
}

void themVatTuVaoCuoi(VatTu **ds, int *n) {
    setColor(1);
    char tiepTuc;
    do {
        resizeArray(ds, *n + 1);
        
        printf("\nNhap thong tin vat tu thu %d:\n", *n + 1);
        nhapMotVatTu(&(*ds)[*n], ds, *n);
        tinhThanhTien(&(*ds)[*n]);
        (*n)++;
        
        printf("Them thanh cong! Ban co muon nhap tiep khong? (y/n): ");
        scanf(" %c", &tiepTuc);
        
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}


void chenVatTu(VatTu **ds, int *n, int *sapxeptheo)
{
    int i, k;
    printf("Nhap vi tri can chen: ");
    scanf("%d", &k);
    if (k < 0 || k > *n)
    {
        printf("Vi tri khong hop le.\n");
        return;
    }
    *n += 1;
    resizeArray(ds, *n);
    for (i = *n - 1; i > k; i--)
    {
        (*ds)[i] = (*ds)[i - 1];
    }
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&(*ds)[k], ds, *n);
    tinhThanhTien(&(*ds)[k]);
    // Kiểm tra xem danh sách có còn được sắp xếp không
    kiemTraSapXep(ds, *n, sapxeptheo);
}

void chenVatTuVaoDanhSachDaSapXep(VatTu **ds, int *n, int sapxeptheo)
{
    int i;
    if (sapxeptheo < 1 || sapxeptheo > 3)
    {
        printf("Chua sap xep danh sach, vui long sap xep truoc\n");
        return;
    }
    *n += 1;
    resizeArray(ds, *n);
    printf("Nhap thong tin vat tu can chen:\n");
    nhapMotVatTu(&(*ds)[*n - 1], ds, *n - 1);
    tinhThanhTien(&(*ds)[*n - 1]);
    for (i = *n - 1; i > 0; i--)
    {
        if (soSanhVatTu((*ds)[i - 1], (*ds)[i], sapxeptheo) > 0)
        {
            swapVatTu(&(*ds)[i], &(*ds)[i - 1]);
        }
        else
            break;
    }
    printf("Vat tu duoc chen o vi tri %d\n", i + 1);
}

void suaVatTu(VatTu **ds, int n)
{
    VatTu x;
    int i, chon;
    printf("Nhap ma vat tu can sua : ");
    scanf("%s", x.ma_vat_tu);
    for (i = 0; i < n; ++i)
    {
        if (soSanhVatTu(x, (*ds)[i], 1) == 0)
            break;
    }
    if (i == n)
    {
        printf("Khong tim thay vat tu can sua.");
        return;
    }
    printf("Chon thong tin can sua:\n");
    printf("0. Thoat\n");
    printf("1. So luong\n");
    printf("2. Don gia\n");
    printf("3. Ngay nhap\n");
    printf("Chon: ");
    scanf("%d", &chon);
    switch (chon)
    {
    case 0:
        return;
    case 1:
        printf("Nhap so luong moi: ");
        scanf("%d", &(*ds)[i].so_luong);
        break;
    case 2:
        printf("Nhap don gia moi: ");
        scanf("%f", &(*ds)[i].don_gia);
        break;
    case 3:
        printf("Nhap ngay nhap moi (dd/mm/yyyy): ");
        nhapNgay(&(*ds)[i].ngay_nhap);
        break;
    default:
        printf("Lua chon khong hop le\n");
        return;
    }
    tinhThanhTien(&(*ds)[i]);
    printf("Sua thanh cong\n");
}

void inGioiThieu()
{
    system("cls");
    setColor(2);
    printf("=========================================================================================================\n");
    printf("|                                          DU AN QUAN LY VAT TU                                          |\n");
    printf("| Sinh vien thuc hien: Duong Sy An       MSSV: 102240014                                                 |\n");
    printf("| Sinh vien thuc hien: Tran Van Phat     MSSV: 102240047           Lop: 24T_DT1                          |\n");
    printf("| Giao Vien huong dan: Do Thi Tuyet Hoa                                                                  |\n");
    printf("=========================================================================================================\n\n");
    printf("Nhan phim bat ky de tiep tuc...\n");
    getch();
    system("cls");
}

void inMenu()
{
    setColor(1);
    printf("========================================================= MENU =========================================================\n\n\n");
    setColor(10);
    printf("0. Thoat\n");
    printf("1. Doc file\n");
    printf("2. Xuat file\n");
    printf("3. Nhap them vat tu\n");
    printf("4. Xoa cac vat tu co so luong lon\n");
    printf("5. Xoa vat tu bat ky\n");
    printf("6. Sap xep vat tu\n");
    printf("7. Thong ke vat tu theo loai\n");
    printf("8. In danh sach vat tu\n");
    printf("9. Tim kiem vat tu\n");
    printf("10. Chen vat tu\n");
    printf("11. Chen vat tu vao danh sach da sap xep\n");
    printf("12. Sua vat tu\n");
    printf("13. Them vat tu vao cuoi danh sach\n");
    printf("\n\n");
    setColor(1);
    printf("========================================================================================================================\n\n");
    setColor(10);
}