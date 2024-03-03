#include<stdio.h>
#include "queue.h"

int main(){
    queue q1;
    init(&q1);
    enqueue(&q1,1);
    enqueue(&q1,2);
    int n = dequeue(&q1);
    printf("The deleted is %d\n", n);
    n = dequeue(&q1);
    printf("The deleted is %d\n", n);
    n = dequeue(&q1);
    printf("The deleted is %d\n", n);
    return 0;
}