#include <stdio.h>
#include <stdlib.h>

struct Listnode{
    int data;
    struct Listnode *next;
};
 typedef struct Listnode* node

 node deleteDuplicates(node head){
    node current = head;
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){
            node temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}