#include <stdio.h>

void Out(int n, int A[n][n]){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int Check(int n, int i, int j, int A[n][n]){
    if (A[i][j]==1) return 0;//kiem tra chinh no
    for (int k = 0 ; k < n ; k++){
        if (A[i][k]==1) return 0;//kiem tra cot
        if (A[k][j]==1) return 0;//kiem tra hang
    }
    int x=i-1,y=j-1;
    while (x>=0&&y>=0&&x<n&&y<n){//kiem tra cheo tren trai
        if (A[x][y]==1) return 0; 
        x--;
        y--;
    }
    x=i-1;
    y=j+1;
    while (x>=0&&y>=0&&x<n&&y<n){//kiem tra cheo duoi trai
        if (A[x][y]==1) return 0; 
        x--;
        y++;
    }
    x=i+1;
    y=j-1;
    while (x>=0&&y>=0&&x<n&&y<n){//kiem tra cheo tren phai
        if (A[x][y]==1) return 0; 
        x++;
        y--;
    }
    x=i+1;
    y=j+1;
    while (x>=0&&y>=0&&x<n&&y<n){//kiem tra cheo duoi phai
        if (A[x][y]==1) return 0; 
        x++;
        y++;
    }
    return 1;
}

void Try(int i, int n , int A[n][n] ){
    for (int j = 0 ; j < n ; j++){
        if (Check(n,i,j,A)){
            A[i][j]=1;
            if (i==n-1){
                Out(n,A);
                printf("\n");
            }
            else Try(i+1,n,A);
            A[i][j]=0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n][n];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            A[i][j]=0;
        }
    }
    Try(0,n,A);
}