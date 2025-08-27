#include<iostream>
using namespace std;
typedef int elementtype;
struct node{
    elementtype data;
    struct node* next;
};
typedef node* queue;
void init(queue &q){
    q = NULL;
}
int empty(queue q){
   return (q == NULL) ;
}
void push(queue &q, elementtype x){
    node* p = new node;
    p->data = x;
    p->next = NULL;
    if (empty(q)){
        q = p;
    }
    else{
        node* t = q;
        while(!empty(t->next)) t = t->next;
        t->next = p;
    }
}
void pop(queue &q){
    if(!empty(q)) {
        cout<<q->data<<" ";
        node* t = q;
        q = q->next;
        delete t;
    }
}
void show(queue q){
    while(!empty(q)){
        pop(q);
    }
}
void peek(queue q){
    if (!empty(q)){
        cout<<q->data;
    }
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
