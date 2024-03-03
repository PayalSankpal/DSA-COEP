#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define LEFT 10
#define RIGHT -10

void initBST(BST* t){
    *t = NULL;
    return;
}

node* create_node(int MIS, const char* Name){
    node* nn = (node*)malloc(sizeof(node));
    if(nn){
        nn->MIS = MIS;
        nn->Name = strdup(Name); // Assuming you want to copy the string
        nn->left = NULL;
        nn->right = NULL;
    }
    else{
        return NULL;
    }
    return nn;
}

void display(node * n){
    printf("%d  %s\n", n->MIS, n->Name);
    return;
}

void insertNode(BST* t, int MIS, const char* Name) {
    node* p = *t, *q = NULL;
    int direction;
    while (p) {
        q = p;
        if (p->MIS == MIS) {
            return; // Duplicate entry
        } else if (p->MIS > MIS) {
            p = p->left;
            direction = LEFT;
        } else if (p->MIS < MIS) {
            p = p->right;
            direction = RIGHT;
        }
    }
    node* nn = create_node(MIS, Name);
    if (q == NULL) {
        *t = nn;
        return;
    }
    if (MIS < q->MIS) {
        q->left = nn;
    } else {
        q->right = nn;
    }
    return;
}

node* search(BST t, int val){
    node* p = t;
    while (p) {
        if (p->MIS == val) {
            return p;
        } else if (p->MIS > val) {
            p = p->left;
        } else if (p->MIS < val) {
            p = p->right;
        }
    }
    return NULL;
}

void preorder(BST t){
    if (t) {
        display(t);
        preorder(t->left);
        preorder(t->right);
    } else {
        return;
    }
    return;
}

void inorder(BST t){
    if (t) {
        inorder(t->left);
        display(t);
        inorder(t->right);
    } else {
        return;
    }
    return;
}

void postorder(BST t){
    if (t) {
        postorder(t->left);
        postorder(t->right);
        display(t);
    } else {
        return;
    }
    return;
}

int Count(BST t){
    if (!t) {
        return 0;
    }
    return Count(t->left) + 1 + Count(t->right);
}

void removeNode(BST* t, int val){
    node* p = *t, *q = NULL;
    int direction;
    while (p) {
        if (p->MIS == val) {
            break;
        } else if (p->MIS > val) {
            q = p;
            p = p->left;
            direction = LEFT; 
        } else if (p->MIS < val) {
            q = p;
            p = p->right;
            direction = RIGHT; 
        }
    }
    if (!p) {
        return; // Node not found
    }
    if (!p->left && !p->right) { // Leaf node
        if (direction == LEFT) {
            q->left = NULL;
        } else {
            q->right = NULL;
        }
        free(p);
    } else if (p->left && !p->right) { // Left child only
        if(!q){
            *t = p->left;
            return;
        }
        if (direction == LEFT) {
            q->left = p->left;
        } else {
            q->right = p->left;
        }
        free(p);
    } else if (!p->left && p->right) { // Right child only
        if(!q){
            *t = p->right;
            return;
        }
        if (direction == LEFT) {
            q->left = p->right;
        } else {
            q->right = p->right;
        }
        free(p);
    } else { // Both children - replace with left subtree's largest
        node* m = p->left, *n = NULL;
        while (m->right) {
            n = m;
            m = m->right;
        }
        if (m == p->left) {
            p->MIS = m->MIS;
            p->Name=m->Name;
            p->left = m->left;
            free(m);
            return;
        }
        p->MIS = m->MIS;
        p->Name=m->Name;
        if (m->left) {
            n->right = m->left;
        } else {
            n->right = NULL;
        }
        free(m);
    }
    return;
}


