#include<iostream>
using namespace std;
typedef int elementtype;
struct node{
    elementtype data;
    node* next;
};
typedef struct{
    node* front;
    node* rear;
} queue;
void init(queue &q){
    q.front = NULL;
    q.rear = NULL;
}
int empty(queue q){
    return q.front == NULL;
}
void push(queue &q, elementtype x){
    node* p = new node;
    p->data = x;
    p->next = NULL;
    if (empty(q)){
        q.front = p;
        q.rear = p;
    }else{
        q.rear->next = p;
        q.rear = p ;
    }
}
void pop(queue &q){
    if(!empty(q)){
        cout<<q.front->data<<" ";
        node* t = q.front;
        q.front = q.front->next;
        if(q.front == NULL) q.rear == NULL;
        delete t;
    }
}
void show(queue q){
    while(!empty(q)) pop(q);
}
void peek(queue q){
    if (!empty(q)){
        cout<<q.front->data;
    }
}
int main(){
    queue q;
    init(q);
    elementtype a[8]={3,5,2,6,7,4,8,1};
    for ( int i = 0; i < 8 ; i++){
        push(q, a[i]);
    }
    show(q);cout<<endl;
    peek(q);
    return 0;
}
