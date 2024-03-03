#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init(queue* queue){
    queue->count=0;
    queue->head=0;
    queue->tail=0;
}

int isEmpty(queue q){
   return (q.count==0);
}

int isFull(queue q){
    return(q.count==N);
}

void enqueue(queue* queue, int n){
    if(isFull(*queue)){
        return;
    }
    queue->Q[queue->tail]=n;
    queue->tail=((queue->tail)+1)%N;
    (queue->count)++;
}

int dequeue(queue* queue){
    if(isEmpty(*queue)){
        return INT_MIN;
    }
    int d;
    d = (queue->Q)[(queue->head)];
    queue->head=((queue->head)+1)%N;
    (queue->count)--;
    return d;
}

void display(queue queue){
    if(isEmpty(queue)){
        return;
    }
    for(int i=0; i<queue.count; i++){
        printf("%d ",queue.Q[(queue.head+i)%N]);
    }
    printf("%c",'\n');
}