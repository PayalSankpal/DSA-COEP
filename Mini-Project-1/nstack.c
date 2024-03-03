#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "nstack.h"

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