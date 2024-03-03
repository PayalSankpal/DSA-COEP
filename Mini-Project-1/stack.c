//number stack


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void init_nstack(nstack *stk){
    *stk=NULL;
    return;
}

int isEmpty(nstack stk){
    return (stk==NULL);
}


void push(nstack *stk, number* n){
    nsnode* nn = (nsnode*)malloc(sizeof(nsnode));
    if(nn){
        nn->num=n;
        nn->next=*stk;
    }
    else{
        return;
    }
    *stk=nn;
    return;
}

number* pop(nstack *stk){
    if(isEmpty(*stk)){
        return '\0';
    }
    number* p = (*stk)->num;
    (*stk)=(*stk)->next;
    return p;
}

number* peek(nstack stk){
    if(isEmpty(stk)){
        return '\0';
    }
    return stk->num;
}

//character stack

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