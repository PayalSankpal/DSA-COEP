#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cstack.h"

void init_cstack(cstack *stk){
    *stk=NULL;
    return;
}

int isEmpty_c(cstack stk){
    return (stk==NULL);
}


void push_c(cstack *stk, char n){
    csnode* nn = (csnode*)malloc(sizeof(csnode));
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

char pop_c(cstack *stk){
    if(isEmpty_c(*stk)){
        return '\0';
    }
    char p = (*stk)->data;
    (*stk)=(*stk)->next;
    return p;
}

char peek_c(cstack stk){
    if(isEmpty_c(stk)){
        return '\0';
    }
    return stk->data;
}