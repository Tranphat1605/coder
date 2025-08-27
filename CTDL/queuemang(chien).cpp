#include<iostream>
using namespace std;
const int maxsize = 100;
typedef int elementtype;
typedef struct {
    elementtype arr[maxsize];
    int n;
    int size = maxsize;
} queue;
void init(queue &q){
    q.n = 0;
}
int empty(queue q){
   return (q.n == 0) ;
}
int full(queue q){
    return q.n == q.size;
}
void push(queue &q, elementtype x){
    if(!full(q)) q.arr[q.n++] = x;
}
void pop(queue &q){
    if(!empty(q)){
        cout<<q.arr[0]<<" ";
        for(int i = 0 ; i < q.n - 1 ; i++){
            q.arr[i] = q.arr[i + 1];
        }
        q.n--;
    }
}
void show(queue q){
    if(!empty(q)){
        for(int i = 0 ; i < q.n ; i++){
            cout<<q.arr[i]<<" ";
        }
    }
}
int search(queue q, elementtype x){
    if(!empty(q)){
       for(int i = 0 ; i < q.n ; i++){
            if(q.arr[i] == x) return i + 1 ;
        }
        cout<<"Khong ton tai "<<x<<" trong queue!!!"<<endl;
    }
}
void peek(queue q){
    if (!empty(q)) cout<<q.arr[0];
}
int main(){
    queue q;
    init(q);
    elementtype a[8]={3,5,2,6,7,4,8,1};
    for ( int i = 0; i < 8 ; i++){
        push(q, a[i]);
    }
    peek(q); cout<<endl;
    show(q);

}

