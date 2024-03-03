#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void init_st(stack* st){
    *st=NULL;
    return;
}

void push(stack* st, char value){
    st_node* nn = (st_node*)malloc(sizeof(st_node));
    nn->data=value;
    nn->next=*st;
    (*st)=nn;
    return;
}

char pop(stack* st){
    if(isEmptyst(*st)){
        return '\0';
    }
    char c = (*st)->data;
    st_node* p = *st;
    (*st)=(*st)->next;
    free(p);
    return c;
}

int isEmptyst(stack st){
    if(st==NULL){
        return 1;
    }
    return 0;
}