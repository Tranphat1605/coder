#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int main () {
	char c[101];
	int s = 00;
	fgets(c, 101, stdin);
	for (int i = 0; i < strlen(c); i++) {
		if (isspace(c[i])){
			s++;
		}
	}
	printf ("%d", s);
	return 0;
}
