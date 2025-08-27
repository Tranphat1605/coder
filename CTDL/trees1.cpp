#include <iostream>
using namespace std;    

typedef int elementtype;
typedef struct node *bstree;
struct node {
    elementtype data;
    node *left;
    node *right;
};

//khoi tao cay
void init(bstree &l) {
    l = NULL;
}

int emptyy(bstree l) {
    return (l == NULL);
}

void showgtp(bstree l) {
    if (!emptyy(l)) {
        showgtp(l->left);
        cout << l->data << " ";
        showgtp(l->right);
    }
}

void showpgt(bstree l) {
    if (!emptyy(l)) {
        showpgt(l->right);
        cout << l->data << " ";
        showpgt(l->left);
    }
}

void bstree_insert(bstree &l, elementtype x) {
    if (l == NULL) {
        l = new node;
        l->data = x;
        l->left = l->right = NULL;
    } else if (x < l->data) {
        bstree_insert(l->left, x);
    } else {
        bstree_insert(l->right, x);
    }
}

node *bstree_min(bstree l) {
    if(l == NULL) return NULL;
    while (l->left != NULL) l = l->left;
    return l;
}

node *bestree_max(bstree l) {
    if(l == NULL) return NULL;
    while (l->right != NULL) l = l->right;
    return l;
}

int bstree_search(bstree l, elementtype x) {
    if (l == NULL) return 0;
    if (l->data == x) return 1;
    if (x < l->data) return bstree_search(l->left, x);
    return bstree_search(l->right, x);
}

void father_node(bstree l, node *t, bstree &fa) {
    if(t == l) fa = NULL;
    else {
        if (l->left != NULL) father_node(l->left, t, fa);
        else if (l->right != NULL) father_node(l->right, t, fa);
        else fa = l;
    }
}

node *bstree_search_node(bstree l, elementtype x) {
    if (l == NULL) return NULL;
    if (l->data == x) return l;
    if (x < l->data) return bstree_search_node(l->left, x);
    return bstree_search_node(l->right, x);
}


void delete_node(bstree &l, elementtype x) {
    node *q = bstree_search_node(l, x), *fa, *p;
    if (q != NULL) {
        if (q == l) {
            if (q->next == NULL) l = l->right;
            else {
                p = bstree_min(l->right);
                p->left = l->left;
                l = l->right;
            }
        
        }
    }
}

void dispose(bstree &l) {
    if (l != NULL) {
        dispose(l->left);
        dispose(l->right);
        delete l;
        l = NULL;
    }
}