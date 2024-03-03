#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"


void init(stack* stk, int s){
    stk->size = s;
    stk->length = 0;
    stk->s=(int *)malloc(sizeof(int)*s);
}

int isEmpty(stack stk){
    return (stk.length==0);
}

int isFull(stack stk){
    return (stk.length==stk.size);
}

void push(stack *stk, int n){
    if(isFull(*stk)){
        return;
    }
    stk->s[stk->length++]=n;
    return;
}

int pop(stack* stk){
    if(isEmpty(*stk)){
        return INT_MAX;
    }
    return(stk->s[--(stk->length)]);
}

int peek(stack stk){
    if(isEmpty(stk)){
        return INT_MAX;
    }
    return(stk.s[stk.length-1]);
}