#include<stdio.h>
#include "stack.h"

int main(){
    stack s1;
    init(&s1,50);
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    push(&s1,4);
    push(&s1,5);
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",peek(s1));
    return 0;
}