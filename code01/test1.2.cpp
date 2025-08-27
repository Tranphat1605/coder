#include <stdio.h> 
#include <string.h>

#define MAXN 500000
char so[MAXN];
int main () {
	int n,k;
	scanf("%d %d", &n, &k);
	scanf("%s", so);
	while (k>0) {
		int i;
		for (i = 0; i < n-1; i++) {
			if (so[i] < so[i+1]) {
				break; 
			}
		}
		for (int j = i; j < n-1; j++) {
			so [j] = so[j+1];
		} 
		n--;
		k--;
	}
	so[n] = '\0';
    printf("%s\n", so);

    return 0;
}
