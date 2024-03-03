typedef struct array{
    int *p;
    int size;
    int length;
}array;

void init(array *arr, int n);
void append(array *arr,int val);
void insert_at_index(array *arr,int val, int pos);
void display(array arr);
void addition(array arr1,array arr2, array* sum);