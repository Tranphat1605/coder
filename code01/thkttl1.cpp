#include <stdio.h> 
#include <math.h>

void tamgiac(float a, float b, float c) {
	if (a <= 0 || b <= 0 || c <= 0) printf ("Do day cua tam giac phai lon hon 0") ;
	else {
	    if ((a + b) <= c || (b + c) <= a || (a + c) <= b) {
	        printf("Khong phai hinh tam giac");
	    } else {
	        if ((a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) && (a == b || b == c || c == a)) {
	            printf("Tam giac vuong can");
	        }
	        if ((a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)) {
	            printf("Tam giac vuong");
	        }
	        if (a == b && b == c) {
	            printf("Tam giac deu");
	        }
	        else if (a == b || b == c || c == a) {
	            printf("Tam giac can");
	        } 
	        if ((a != b && b != c && c != a) && (a * a + b * b != c * c && a * a + c * c != b * b && b * b + c * c != a * a)) {
	            printf("Tam giac binh thuong");
	        }
	    }
	}
}
int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    tamgiac(a, b, c);
    return 0;
}
