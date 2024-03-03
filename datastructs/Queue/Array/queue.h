typedef struct queue{
    int size,head,tail;
    int* Q;
}queue;

void init(queue* queue, int s);
int isEmpty(queue q);
void enqueue(queue* queue, int n);
int dequeue(queue* queue);
void display(queue queue);