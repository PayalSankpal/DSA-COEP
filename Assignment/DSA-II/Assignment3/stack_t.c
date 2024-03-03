#include<stdio.h>
#include<stdlib.h>
#include"stack_t.h"

void init_st_t(stack_t* st){
    *st=NULL;
    return;
}

void push_t(stack_t* st, tr_node* value){
    st_node_t* nn = (st_node_t*)malloc(sizeof(st_node_t));
    nn->data=value;
    nn->next=*st;
    (*st)=nn;
    return;
}

tr_node* pop_t(stack_t* st){
    if(isEmptyst_t(*st)){
        return NULL;
    }
    st_node_t* p = *st;
    tr_node* c = p->data;
    (*st)=(*st)->next;
    free(p);
    return c;
}

int isEmptyst_t(stack_t st){
    if(st==NULL){
        return 1;
    }
    return 0;
}