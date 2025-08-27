//Sap xep chon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int a[10], n, i, j, tam;
	
	srand(time(NULL));
	n=3+rand()%8; printf("\nn= %d",n);
	for (i=0; i<n; i++) a[i]=1+rand()%10;
	printf("\n"); for (i=0; i<n; i++) printf("%d ", a[i]);
	//Sap xep tang dan
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++)
			if (a[j]<a[i]){
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
	printf("\n"); for (i=0; i<n; i++) printf("%d ", a[i]);		
}

