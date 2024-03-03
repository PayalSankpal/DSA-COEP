#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init(queue* queue, int s){
    queue->size=s;
    queue->Q=(int*)malloc(sizeof(int)*s);
    queue->head=-1;
    queue->tail=-1;
}

int isEmpty(queue q){
   return (q.head==-1 && q.tail==-1);
}

int isFull(queue q){
    return(q.tail==q.size-1);
}

void enqueue(queue* queue, int n){
    if(isFull(*queue)){
        return;
    }
    if(queue->tail==-1){
        queue->head++;
    }
    queue->Q[++queue->tail]=n;
}

int dequeue(queue* queue){
    if(isEmpty(*queue)){
        return INT_MIN;
    }
    return queue->Q[queue->head++];
}

void display(queue queue){
    if(isEmpty(queue)){
        return;
    }
    for(int i=queue.head; i<=queue.tail; i++){
        printf("%d ",queue.Q[i]);
    }
    printf("%c",'\n');
}