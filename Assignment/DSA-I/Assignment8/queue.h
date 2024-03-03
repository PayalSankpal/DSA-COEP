typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    node* tail;
}queue;

void init(queue* queue);
int isEmpty(queue q);
void enqueue(queue* queue, char n);
char dequeue(queue* queue);