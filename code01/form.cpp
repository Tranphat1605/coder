#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
int ngay, thang, nam;
}NgayThang;
struct SinhVien{
char msv[10];
char ten[30];
char gt[5];
 NgayThang date;
char lop[10];
float toan, triet, ltc;
float dtb;
};
typedef SinhVien SV;
void nhap(SV &sv){
printf("\nNhap msv: "); scanf("%s",&sv.msv);
printf("Nhap ten: "); fflush(stdin); gets(sv.ten);
printf("Nhap gioi tinh: "); gets(sv.gt);
printf("Nhap ngay sinh: "); scanf("%d%d%d",&sv.date.ngay,&sv.date.thang,&sv.date.nam);
printf("Sinh vien lop:"); scanf("%s",&sv.lop);
printf("Diem toan cao cap: "); scanf("%f",&sv.toan);
printf("Diem triet: "); scanf("%f",&sv.triet);
printf("Diem lap trinh C: "); scanf("%f",&sv.ltc);
sv.dtb=0;
}


void nhapN(SV a[], int n){
printf("\n==NHAP THONG TIN SINH VIEN==\n");
for(int i = 0; i< n; ++i){
printf("\nNhap SV thu %d:", i+1);
nhap(a[i]);
 }
printf("\n____________________________________\n");
}
float dtb(float a,float b,float c)
{return(a+b+c)/3;
}
float dtb (SV a[MAX],int n)
{
int i;
for(i=0;i<n;i++)
 {
a[i].dtb=dtb(a[i].toan,a[i].triet,a[i].ltc);
 }
}
void in1sv (SV sv)
{
printf("|%-10s|%-25s|%d/%d/%d\t|%-10.2f|\n",sv.msv,sv.ten,sv.date.ngay,sv.date.thang,sv.date.nam,sv.dtb);
}
void insv(SV a[MAX],int n)
{
int j;
printf("==XUAT DANH SACH SINH VIEN==\n");
for(j=0;j<=67;j++){printf("-");
 }
printf("\n|%-10s|%-25s|%-15s |%-10s|\n","Masv","Ho ten","Ngay sinh","DTB");
for(j=0;j<=67;j++){printf("-");
 }

printf("\n");
for(j=0;j<n;j++)
 {
in1sv(a[j]);
 }
for(j=0;j<=67;j++){printf("-");
 }
printf("\n");
}
void sapxep(SV a[], int n){
 SV tmp;
for(int i = 0;i < n;++i){
for(int j = i+1; j < n;++j){
if(a[i].dtb > a[j].dtb){
 tmp = a[i];
a[i] = a[j];
a[j] = tmp;
 }
 }
 }
}
void xeploai(SV sv){
if(sv.dtb >= 8) printf("Gioi");
else if(sv.dtb >= 6.5) printf("Kha");
else if(sv.dtb >= 4) printf("Trung binh");
else printf("Yeu");
}
void xeploaiN(SV a[], int n){
printf("\n____________________________________\n");
for(int i = 0;i < n;++i){
printf("\nXep loai cua SV %s la: ",a[i].ten);
xeploai(a[i]);

 }
printf("\n____________________________________\n");
}
void XuatFile(SV a[], int n, char fileName[]){
FILE * fb ;
fb = fopen("fileName", "w");
fprintf(fb, "\n\t\t==XUAT DANH SACH SINH VIEN==\n\n");
fprintf(fb,
"+-----------------------------------------------------------------------------------------+\n");
fprintf(fb, "| %-5s \t| %-20s \t| %-10s \t| %-11s \t| %-15s |\n", "MSV", "Ho va ten","Gioi
tinh", "Ngay sinh", "Diem trung binh");
fprintf(fb, "+-------------------------
 ----------------------------------------------------------------+\n");
int i;
for(i=0; i<n; i++){
fprintf(fb, "| %-5s \t| %-20s \t| %-11s \t| ", a[i].msv, a[i].ten,a[i].gt);
fprintf(fb, " %d/", a[i].date.ngay);
fprintf(fb,"%d/",a[i].date.thang);
fprintf(fb,"%d \t|",a[i].date.nam);
fprintf(fb, " %-15.2f |\n", a[i].dtb);
 }
fprintf(fb,
"+-----------------------------------------------------------------------------------------+\n");
fclose(fb);
}
int main(){
int key;int j;
char fileName[] = "DLSV.txt";
bool daNhap = false;
int n;
 SV a[MAX];
while(true){
system("cls");

printf("MENU QUAN LY SINH VIEN KHOA CONG NGHE THONG TIN\n");
printf("=============================================================\n");
printf("1. NHAP THONG TIN SINH VIEN\n");
printf("2. XUAT DANH SACH SINH VIEN\n");
printf("3. TINH DIEM TRUNG BINH SINH VIEN\n");
printf("4. SAP XEP SINH VIEN THEO THU TU TANG DAN CUA DIEM TRUNG BINH\n");
printf("5. XEP LOAI SINH VIEN\n");
printf("6. NHAP, XUAT DU LIEU VAO FILE\n");
printf("0. THOAT CHUONG TRINH\n");
printf("=============================================================\n");
printf("** Nhap lua chon cua ban **\n");
scanf("%d",&key);
switch(key){
case 1:
do{
printf("\nNhap so luong SV: "); scanf("%d", &n);
 }while(n <= 0);
nhapN(a, n);
printf("\nBan da nhap thanh cong!");
 daNhap = true;
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
case 2:
if(daNhap){
printf("\n XUAT DANH SACH SINH VIEN\n");
insv(a, n);
 }else{
printf("\nNhap DS SV truoc!!!!");
 }
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
case 3:

printf("\nTINH DIEM TRUNG BINH SINH VIEN");
dtb(a, n);
printf("\n \tDA HOAN THANH!");
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
case 4:
if(daNhap){
printf("\nSAP XEP SINH VIEN THEO THU TU TANG DAN CUA DIEM TRUNG BINH\n");
sapxep(a, n);
insv(a, n);
 }else{
printf("\nNhap DS SV truoc!!!!");
 }
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
case 5:
if(daNhap){
printf("\nXEP LOAI SINH VIEN");
xeploaiN(a, n);
 }else{
printf("\nNhap DS SV truoc!!!!");
 }
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
 case 6:
printf("Da xuat DLSV vao file \n");
XuatFile(a, n, fileName);
printf("Bam phim bat ki de tiep tuc!");
getch();
break;

case 0:
printf("\nBan da chon thoat chuong trinh!");
getch();
return 0;
default:
printf("\nKhong co chuc nang nay!");
printf("\nBam phim bat ky de tiep tuc!");
getch();
break;
