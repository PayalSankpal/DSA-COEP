typedef struct heap{
    int * tree;
    int size;
    int length;
}heap;

void init_heap(heap* t, int N);
void insert_heap(heap* t, int n);
void max_heapify(heap* h);
void min_heapify(heap* h);
void levelwise(heap* t);
int isEmpty(heap* h);