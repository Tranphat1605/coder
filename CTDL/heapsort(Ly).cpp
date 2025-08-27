#include <iostream>
// #include <math.h>
using namespace std;
void doi(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void heap_max(int arr[], int n, int i){
    int l=2*i+1;
    int r=2*i+2;
    int lar=i;
    if(l<n&&arr[l]>arr[lar]) lar=l;
    if(r<n&&arr[r]>arr[lar]) lar=r;
    if(lar!=i){
        doi(arr[i],arr[lar]);
        heap_max(arr,n,lar);
    }
}
void build(int arr[], int n){
    for(int i=(n-1)/2;i>=0;i--){
         heap_max(arr,n,i);
    }
}
void show(int arr[], int n){
    for(int i=0;i<n;i++) cout <<arr[i]<<" ";
    cout<<endl;
}
void sxep(int arr[], int n){
    build(arr,n);
    for(int i=n-1;i>=0;i--){
        doi(arr[0],arr[i]);
        heap_max(arr,i,0);
    }
}
int main(){
  int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Mang ban dau: ";
    show(arr, n);

    sxep(arr, n);

    cout << "Sau khi sap xep HeapSort: ";
    show(arr, n);

    return 0;
}