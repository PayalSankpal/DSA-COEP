#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "queue.h"

void init(queue* queue){
    queue->head=NULL;
    queue->tail=NULL;
}

int isEmpty(queue q){
    return (q.head==NULL && q.tail==NULL);
}

void enqueue(queue* queue, int n){
    node* nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data=n;
        nn->next=NULL;
    }
    else{
        return;
    }
    if(isEmpty(*queue)){
        queue->head=queue->tail=nn;
        return;
    }
    queue->tail->next=nn;
    queue->tail=nn;
}

int dequeue(queue* queue){
    if(isEmpty(*queue)){
        return INT_MIN;
    }
    node * on=queue->head;
    int data = on->data;
    queue->head=queue->head->next;
    if(queue->head==NULL){
        queue->tail=queue->head;
    }
    free(on);
    return data;
}
