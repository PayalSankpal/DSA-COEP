#include<stdio.h>
#include "queue.h"

int main(){
    queue q1;
    init(&q1);
    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    display(q1);
    int n = dequeue(&q1);
    printf("The deleted is %d\n", n);
    enqueue(&q1,5);
    display(q1);
    n = dequeue(&q1);
    printf("The deleted is %d\n", n);
    return 0;
}