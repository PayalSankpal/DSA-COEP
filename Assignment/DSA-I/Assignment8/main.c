#include<stdio.h>
#include "queue.h"

int main(){
    int choice = 0;
    queue q1;
    init(&q1);
    printf("Queue created and initialized.\n");
    while(1){
        printf("**********Menu*********\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.End\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter character to be pushed:\n");
            char n;
            scanf(" %c",&n);
            enqueue(&q1,n);
            printf("Pushed!\n");
        }
        else if(choice==2){
            printf("The deleted is %c\n", dequeue(&q1));
        }
        else if(choice==3){
            break;
        }
        else{
            printf("Invlaid choice.\n");
        }
        
    }
    return 0;
}