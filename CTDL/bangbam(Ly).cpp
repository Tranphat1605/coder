// #include <iostream>
// using namespace std;
// typedef int ele;
// const int mx=10;
// typedef struct node *list;
// struct node{
//     ele data;
//     node *next;
// };
// list ha[mx];
// int key(ele x){
//     return x % mx;
// };
// void init(list ha[mx]){
//     for(int i=0;i<mx;i++) ha[i]=NULL;
// }
// void insert(list ha[mx], ele x){
//     int i=key(x);
//     node *temp=new node;
//     temp->data=x;
//     temp->next=NULL;
//     if(ha[i]==NULL) ha[i]=temp;
//     else{ node *p=ha[i];
//         while(p->next!=NULL) p=p->next;
//         p->next=temp;
//     }
// }


// void show(list ha[mx]){
//     for(int i=0;i<mx;i++){
//         if(ha[i]==NULL) continue;
//         node *p=ha[i];
//         while(p!=NULL) {cout << p->data<<" "; p=p->next;}
//         cout <<endl;
//     }
// }
// int main(){
//      list ha[mx];
//      init(ha);
//      for(int i=0;i<100;i++) insert(ha,i);
//      show(ha);
// }
#include <iostream>
using namespace std;
const int mx=10;
typedef struct node *list;
struct node{
    int data;
    node *next;
};
list ha[mx];
void init(list ha[mx]){
    for(int i=0;i<mx;i++){
        ha[i]=NULL;
    }
}
int key(int x){
     return x%mx;
}
void insert(list ha[mx], int x){
   int i=key(x);
        node *temp=new node;
        temp->data=x;
        temp->next=NULL;
    if(ha[i]==NULL) ha[i]=temp;
    else {
        node *p=ha[i];
        while(p->next!=NULL){p=p->next; }
        p->next=temp;
    }
    }

void show(list ha[mx]){
    for(int i=0;i<mx;i++){
        if(ha[i]==NULL) continue;
        node *p=ha[i];
        while(p!=NULL){cout<<p->data<<" "; p=p->next;}
        cout<<endl;
    }
}
int empty(list l){
    return (l==NULL);
}
int find(list ha[mx], int x){
    int i=key(x);
    node *p=ha[i];
    while(p!=NULL){
        if(p->data==x) return 1;
        p=p->next;
    }
    return 0;
}
// void remove(list ha[mx], int x){
//     if(find(ha,x)){
//         int i=key(x);
//     node *p=ha[i];
//     if(p->data==x) {p=p->next; return;}
//     while(p->next->data!=x) p=p->next;
//     {p->next=p->next->next;}
//     } else return;
// }
// void remove(list ha[mx], int x) {
//     int i = key(x);
//     node *p = ha[i], *prev = NULL;

//     while (p != NULL) {
//         if (p->data == x) {
//             if (prev == NULL) {
//                 ha[i] = p->next; // xóa node đầu
//             } else {
//                 prev->next = p->next; // xóa node giữa/cuối
//             }
//             delete p;
//             return;
//         }
//         prev = p;
//         p = p->next;
//     }
// }
    void remove2(list ha[mx], int x){
        int i=key(x);
        node *p=ha[i], *pre=NULL;
        while(p!=NULL){
            if(p->data==x){
                if(pre==NULL) ha[i]=ha[i]->next;
                else {
                    pre->next=p->next;
                }
                    delete p;
                    return;
            }
            pre=p;
            p=p->next;
        }
    }
void remove(list ha[mx],int x){
    int i=key(x);
    node *p=ha[i];
    if(find(ha,x)){
        if(ha[i]->data==x){ha[i]=ha[i]->next;delete p; return;}
    while(p->next!=NULL&&p->next->data!=x) p=p->next;
    node *q=p->next;
    p->next=p->next->next;
    delete q;
    }
}
// int count(list ha[mx]) {
//     int total = 0;
//     for (int i = 0; i < mx; i++) {
//         node *p = ha[i];
//         while (p != NULL) {
//             total++;
//             p = p->next;
//         }
//     }
//     return total;
// }
int count(list ha[mx]){
    int total=0;
    for(int i=0;i<mx;i++){
        node *p=ha[i];
        while(p!=NULL){
            total++;
            p=p->next;
        }
    }
    return total;
}
// void xoa(list ha[mx]){
//     for(int i=0;i<mx;i++){
//         node *p=ha[i];
//         while(p!=NULL){
//             node *q=p;
//             p=p->next;
//             delete q;
//         }
//         ha[i]=NULL;
//     }
// }
void xoa(list ha[mx]) {
    for (int i = 0; i < mx; i++) {
        while (ha[i] != NULL) {
            node *tmp = ha[i];
            ha[i] = ha[i]->next;
            delete tmp;
        }
    }
}

int main(){
    list ha[mx];
    init(ha);
    insert(ha, 4);
insert(ha, 87);
insert(ha, 23);
insert(ha, 59);
insert(ha, 16);
insert(ha, 42);
insert(ha, 95);
insert(ha, 38);
insert(ha, 61);
insert(ha, 11);
insert(ha, 70);
insert(ha, 7);
insert(ha, 98);
insert(ha, 35);
insert(ha, 26);
insert(ha, 89);
insert(ha, 14);
insert(ha, 68);
insert(ha, 53);
insert(ha, 92);
    show(ha);
//     cout<<find(ha,100);
//     remove2(ha,68);
// show(ha);
cout <<"so phan tu la "<<count(ha)<<"\n";
xoa(ha);
show(ha);

}