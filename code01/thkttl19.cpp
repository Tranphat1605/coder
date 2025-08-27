#include <stdio.h> 
float so35(float a) {
	if (a<5&&a>3) {
		return 1;
	} else {
		return 0;
	}
}
int main () {
	float x,y,z;
	printf ("Nhap 3 so x, y, z: ");
	scanf("%f %f %f", &x, &y, &z);
	printf ("So nam trong khoang (3, 5) la: \n");
	if (so35(x)) printf ("%f\n", x);
	if (so35(y)) printf ("%f\n", y);
	if (so35(z)) printf ("%f\n", z);
	return 0;
}
