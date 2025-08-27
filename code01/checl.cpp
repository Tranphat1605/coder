#include <stdio.h> 
#include <string.h>

int check(char a[]){
	int l = 0;
	int r = strlen(a) - 1;
	for (int i = l; l < r; l++, r--) {
		if (a[l] != a[r]) {
			return 0;
		}
	}
	return 1;  
} 
int main () {
	char a[1000];
	scanf("%s", a);
	if (check(a)) {
		printf("la chuoi doi xung");
	}
	else {
		printf ("Khong la chuoi doi xung");
	}
	return 0;
}
