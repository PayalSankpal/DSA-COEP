#include<stdio.h>
#include "stack.h"

int main(){
    int choice = 0;
    stack s1;
    init(&s1);
    printf("Stack created and initialized.\n");
    while(1){
        printf("**********Menu*********\n");
        printf("1.Push to the stack\n");
        printf("2.Pop from the stack\n");
        printf("3.Peek from the stack\n");
        printf("4.End\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter interger to be pushed\n");
            int n;
            scanf("%d",&n);
            push(&s1,n);
            printf("Pushed!\n");
        }
        else if(choice==2){
            printf("%d\n",pop(&s1));
        }
        else if(choice==3){
            printf("%d\n",peek(s1));
        }
        else if (choice==4){
            break;
        }
        else{
            printf("Invlaid choice.\n");
        }
        
    }
    return 0;
}
