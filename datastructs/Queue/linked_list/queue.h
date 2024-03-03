typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    node* tail;
}queue;

void init(queue* queue);
int isEmpty(queue q);
void enqueue(queue* queue, int n);
int dequeue(queue* queue);