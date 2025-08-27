#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0
int parent[100006];
int Size[100006];
int n,m;
int capacity=0;
typedef struct Edge{
	int x,y,w;
} Edge;

Edge a[200006];

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void init(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		Size[i]=1;
	}
}
 
int Find(int u){
	if(u==parent[u]){
		return u;
	}
	else{
		return parent[u]=Find(parent[u]);
	}
}

bool  Union(int u, int v){
	u=Find(u);
	v=Find(v);
	if(u==v){
		return false;
	}
	else{
		if(Size[u]<Size[v]){
			parent[u]=v;
			Size[v]+=Size[u];
		}
		else{
			parent[v]=u;
			Size[u]+=Size[v];
		}
	}
	return true;
}

void kruskal(){
	qsort(a,m,sizeof(Edge),cmp);
	long long d=0;
	int dem=0;
	Edge b[100006];
	for(int i=0;i<m;i++){
		if(dem==n-1) break;
		if(Union(a[i].x,a[i].y)){
			b[dem]=a[i];
			d+=a[i].w;
			dem++;
		}
	}
	if(dem!=n-1){
		printf("IMPOSSIBLE");
		return ;
	}
	printf("%lld",d);
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[i].x = x;
		a[i].y = y;
		a[i].w = w;
	}
	kruskal();
}