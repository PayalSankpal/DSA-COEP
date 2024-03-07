typedef struct heap{
    int * tree;
    int size;
    int length;
}heap;

void init_heap(heap* t, int N);
void max_insert_heap(heap* t, int n);
void max_heapify(heap* h);
void max_heapsort(heap* h);
void min_insert_heap(heap* t, int n);
void min_heapify(heap* h);
void min_heapsort(heap* h);
void levelwise(heap* t);
int isEmpty(heap* h);