#include "tree.h"

typedef struct qnode{
    node* data;
    struct qnode* next;
}qnode;

typedef struct queue{
    qnode* head;
    qnode* tail;
}queue;

void init(queue* queue);
int isEmpty(queue q);
void enqueue(queue* queue, node* n);
node* dequeue(queue* queue);