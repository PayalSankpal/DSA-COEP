#include<stdio.h>
#include<stdlib.h>


void init_tree(expTree* t){
    *t=NULL;
    return;
}

tr_node* create_node(char value){
    tr_node* nn = (tr_node*)malloc(sizeof(tr_node));
    if(nn){
        nn->data=value;
        nn->left=NULL;
        nn->right=NULL;
        return nn;
    }
    return NULL;
}

void inorder(expTree t){
    if(!t){
        return;
    }
    inorder(t->left);
    printf("%c",t->data);
    inorder(t->right);
}