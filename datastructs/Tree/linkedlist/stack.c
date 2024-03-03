#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_stack(stack *stk){
    *stk=NULL;
    return;
}

int isEmpty_s(stack stk){
    return (stk==NULL);
}


void push(stack *stk, node* n){
    snode* nn = (snode*)malloc(sizeof(snode));
    if(nn){
        nn->data=n;
        nn->next=*stk;
    }
    else{
        return;
    }
    *stk=nn;
    return;
}
node* pop(stack *stk){
    if(isEmpty_s(*stk)){
        return '\0';
    }
    node* p = (*stk)->data;
    (*stk)=(*stk)->next;
    return p;
}

node* peek(stack stk){
    if(isEmpty_s(stk)){
        return NULL;
    }
    return stk->data;
}