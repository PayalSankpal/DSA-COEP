#define N 4

typedef struct queue{
    int count,head,tail;
    int Q[N];
}queue;

void init(queue* queue);
int isEmpty(queue q);
int isFull(queue q);
void enqueue(queue* queue, int n);
int dequeue(queue* queue);
void display(queue queue);