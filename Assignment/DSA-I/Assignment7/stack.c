#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init(stack *stk){
    *stk=NULL;
    return;
}

int isEmpty(stack stk){
    return (stk==NULL);
}


void push(stack *stk, char n){
    node* nn = (node*)malloc(sizeof(node));
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

char pop(stack *stk){
    if(isEmpty(*stk)){
        return '\0';
    }
    char p = (*stk)->data;
    (*stk)=(*stk)->next;
    return p;
}

char peek(stack stk){
    if(isEmpty(stk)){
        return '\0';
    }
    return stk->data;
}