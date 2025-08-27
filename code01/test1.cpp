#include<stdio.h>
#include<math.h>
#define ll long long
#define db double

//Chuyen co so
const char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void Z(ll s, int p){
	if(s<0) s=(unsigned )s;
	if(s>=p){
		Z(s/p,p);
		printf("%c",a[s%p]);
	}
	else printf("%c",a[s]);
}

void R(db s, int p){
	int cnt=1;
	do{
		s*=p;
		printf("%c",a[(int)s]);
		s-=(int)s;
		cnt++;
	}while(cnt<=10 && s!=0);
}

void noi(db s, int p){
	if(p==10) printf("%lf",s);
	else{
		if(s==(ll)s) Z((ll)s,p);
		else{
			if(s>=0){
				Z((ll)s,p);
				printf(".");
				R(s-(ll)s,p);
			}
			else{
				Z((ll)s-1,p);
				printf(".");
				R(s-(ll)s+1,p);
			}
		}
	}
}

int main(){
    db s;
    int p;
    printf("Nhap so can chuyen: ");
    scanf("%lf",&s);
    do{
        printf("Co so can chuyen: ");
        scanf("%d",&p);
        if(p<2 || p>16) printf("Nhap lai!(2-16)\n");
    }while(p<2 || p>16);
    printf("Ket qua la: ");
    noi(s,p);
}

