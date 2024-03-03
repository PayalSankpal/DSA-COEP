typedef struct array{
    int *p;
    int size;
    int length;
}array;

void init(array *arr, int n);
void append(array *arr,int val);
void insert_at_index(array *arr,int val, int pos);
void delete_at_index(array *arr, int pos);
void display(array arr);
int max_in_array(array arr);
int min_in_array(array arr);
void reverse_the_array(array *arr);
void merge_array(array *arr1, array *arr2);
