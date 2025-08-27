#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct sinhvien{
	char ten[100];
	char lop[50];
	char ngaysinh[50];
	float gpa;
};

typedef struct sinhvien sinhvien;

int cmp(const void *a, const void *b){
	sinhvien *x = (sinhvien*)a;
	sinhvien *y = (sinhvien*)b;
	if (x->gpa > y->gpa) {
		return -1;
	}
	return 1;
}

int main () {
	FILE *f1, *f2;
	sinhvien a[1000];
	int n = 0;
	f1 = fopen ("sinhvien.txt", "r");
	if (f1 == NULL) {
		printf("File khong hop le!");
	} else {
		f2 = fopen ("sinhvien_out1.txt", "w");
		char data[200];
		while (fgets(data, 200, f1)!=NULL) {
			data[strlen(data)-1] = '\0';
			int d = 0;
			char *token = strtok(data, ",");
			while (token != NULL) {
				d++;
				if (d == 1) {
					strcpy(a[n].ten, token);
				}
				else if (d == 2) {
					strcpy(a[n].lop, token);
				}
				else if (d == 3) {
					strcpy(a[n].ngaysinh, token);
				}
				else {
					a[n].gpa = atof(token);
				}
				token = strtok(NULL, ",");
			}
			n++;
		}
		qsort(a, n, sizeof(sinhvien), cmp);
		int i;
		for (i = 0; i < n; i++) {
			fprintf (f2, "%s, %s, %s, %f\n", a[i].ten, a[i].lop, a[i].ngaysinh, a[i].gpa);
			
		} 
		fclose(f1);
		fclose(f2);
	}
	return 0;
} 

